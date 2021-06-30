%% CONVERSOR BUCK MALHA FECHADA

clear
clc
close all
T = 0.1e-3; 
s = tf('s'); 

%% Parâmetros do sinal de referência 

fs = 10000; %freq de amostragem
T0 = 40e-3; %periodo fundamental
f0 = 1/T0; %freq fundamental
N = fs/f0; %qnt de pontos por amostra

Aref = 18; %Amplitude máxima da referência
Oref = 6; %Offset mínima da referência
Vdif = Aref - Oref;
kq = 0;

%% Parametros do modulador PWM

E = 24;
NbitsPWM = 8;
P = 2^NbitsPWM; % num de níveis do PWM
Vmax = 30; % Tensão máxima na planta

%% Definição dos parâmetros do conv.A/D

EAD = 3; %Entrada do conversor A/D
NbitsAD = 10; %Num. de bits do conv. A/D
Q = 2^NbitsAD; %Num. de niveis conv. A/D
offsetCS = 0.5; %Offset do condicionamento
K = EAD / Vmax; %Ganho transdut.(div.res.)

%% Planta e Coeficientes da Equação de Diferenças

%Planta = Filtro Passa Baixas RLC 1 Ordem / BUCK 

% Periodo de amostragem
Tc = T/P; 
%Planta Contínua P(s) / Função de Transferência em Tempo Contínuo (CTTF)
Pc = 9775171.0654936 / (s^2 + 2020.202020202*s + 9775171.0654936);       
%Planta Discreta P(z) / Função de Transferência em Tempo Discreto (DTTF) 
Pd = c2d(Pc,Tc);

%Coeficientes ED
[npd,dpd] = tfdata(Pd,'v')
a1 = dpd(2); 
a0 = dpd(3);
b1 = npd(2); 
b0 = npd(3);

%% Condicionamento de Sinais e Coeficientes da Equação de Diferenças

%Condicionamento = Filtro Passa Baixas Sallen Key 2 Ordem

%Sensor Contínuo P(s) 
Sc = 96711798.839458 / (s^2 + 6673.1141199226*s + 96711798.839458);  
%Sensor Discreto
Sd = c2d(Sc,Tc);

%Coeficientes ED
[nsd,dsd] = tfdata(Sd,'v')
as1 = dsd(2); 
as0 = dsd(3);
bs1 = nsd(2); 
bs0 = nsd(3);

%% Ganhos do controlador

Kp = 0.1;
Ki = 0.125;
Kd = 1;

%% Inicialização dos Vetores

t = zeros(1,N); 
tc = zeros(1,N*P);
x = zeros(1,N);  %referencia
e = zeros(1,N);  %erro
d = zeros(1,N);

uP = zeros(1,N);       %Controle Proporcional
uI = zeros(1,N);       %Controle Integral
uD = zeros(1,N);       %Controle Derivativo
uPID = zeros(1,N);
PWM = zeros(1,N*P);

y = zeros(1,N*P);   %saida planta
yd = zeros(1,N*P);  %saída divisor resistivo
ys = zeros(1,N*P);  %saída do condicionamento
yo = zeros(1,N*P);  %offset na saída
ym = zeros(1,N);    %saida ADC
yA = zeros(1,N);  
yR = zeros(1,N*P);
yQ = zeros(1,N);

%% Simulação Conversor Buck 

for k = 2:N
    
    % Vetor de tempo disc. para graficos
    t(k) = k*T;
    kq = kq + 1;
    
    % Geração do sinal de referência1
    if(k>0 && k<=50)
        x(k) = Vdif;
    end
    if(k>50 && k<=60)
        x(k) = x(k-1) + (Oref/10);
    end
    if(k>60 && k<=150)
        x(k) = Aref;
    end
    if(k>150 && k<=160)
        x(k) = x(k-1) - (Oref/10);
    end
    if(k>160 && k<=250)
        x(k) = Vdif;
    end
    if(k>250 && k<=260)
        x(k) = x(k-1) - (Oref/10);
    end
    if(k>260 && k<=350)
        x(k) = Oref;
    end
    if(k>350 && k<=360)
        x(k) = x(k-1) + (Oref/10);
    end
    if(k>360 && k<=400)
        x(k) = Vdif;
    end
    
    % Malha de Controle
    e(k)= x(k) - ym(k); %erro = referencia + saida adc
    
    uP(k) = Kp*e(k);                    %Controle Proporcional
    uI(k) = uI(k-1) + Ki*e(k);          %Controle Integral
    uD(k) = Kd*(e(k) - e(k-1));         %Controle Derivativo
    uPID(k) = uP(k) + uI(k) + uD(k);    %Controle PID
    
    d(k) = abs(uPID(k))*P/E;
    su = sign(uPID(k));
    
    % Discretrização dos sistemas contínuos
    for cc = 1:P
        % Contador e vetor de tempo do sist. Superdisc.
        kc = k*P + cc;
        tc(kc) = kc*Tc;

        % Geraçãodo PWM(kc)
        if cc <= d(k) 
            PWM(kc) = su*E; 
        end
        if cc > d(k) 
            PWM(kc) = 0; 
        end

        % Saída da planta + entrada PWM
        y(kc+1)=-a1*y(kc)-a0*y(kc-1)+b1*PWM(kc)+b0*PWM(kc-1);       
        
        % Divisor Resistivo
        yd(kc+1) = y(kc+1)*K;
        
        % Condicionamento de sinais
        ys(kc+1) = -as1*ys(kc) - as0*ys(kc-1) + bs1*yd(kc) + bs0*yd(kc-1); 
        
        % Offset
        yo(kc+1) = ys(kc+1) + offsetCS;
    end

    %Conversor ADC
    yA(k+1) = yo(kc+1);                    % Amostragem
    for i = (kc+1):(kc+1+P) 
        yR(i) = yA(k+1); 
    end
    
    yQ(k+1) = round(yR(kc+1)*Q/EAD)/Q*EAD; % Quantização 
    ym(k+1) = (yQ(k+1) - offsetCS)/K;      % Valor Original
end

%% Graficos

y(k+1)=[];
yd(k+1)=[];
ys(k+1)=[];
yo(k+1)=[];
ym(k+1)=[];
yA(k+1)=[];
yQ(k+1)=[];

plot(tc,y)
hold on
plot(t,x)
hold on
plot(t,ym,'--','Color','y')
set(findall(gcf,'Type','line'),'LineWidth',2)
grid on
legend('y - saida da planta','x - sinal de entrada', 'ym - saída ADC')

figure
plot(t,e,'--','Color',[0.3010 0.7450 0.9330])
hold on
plot(t,uPID,':')
set(findall(gcf,'Type','line'),'LineWidth',2)
grid on
legend('e - sinal de erro','PID - sinal de controle')

figure
plot(tc,y)
hold on
plot(t,uPID,':')
set(findall(gcf,'Type','line'),'LineWidth',2)
grid on
legend('y - saida da planta','PID - sinal de controle')

figure
plot(tc,y)
hold on
plot(tc,ys,'green')
set(findall(gcf,'Type','line'),'LineWidth',2)
grid on
legend('y - saida da planta', 'ys - saída condicionamento')

figure
plot(t,uP, 'Color', [0.4940 0.1840 0.5560])
hold on
plot(t,uI,'--', 'Color','black')
hold on
plot(t,uD, 'Color',[0.9290 0.6940 0.1250])
set(findall(gcf,'Type','line'),'LineWidth',2)
grid on
legend('P - Controle Proporcional','I - Controle Integral','D - Controle Derivativo')

figure
plot(tc,yo, 'Color', [0.6350 0.0780 0.1840])
hold on
plot(tc,ys,'green')
set(findall(gcf,'Type','line'),'LineWidth',2)
xlim([0 0.04])
grid on
legend('yo - offset','ys - saída condicionamento')

figure
plot(t,yQ, 'Color', [0.4660 0.6740 0.1880])
hold on
plot(t,ym, '--', 'Color', 'yellow')
set(findall(gcf,'Type','line'),'LineWidth',2)
grid on
legend('yQ - Quantização ADC','ym - Saída ADC')

figure
plot(tc,PWM, 'Color', [0.8500 0.3250 0.0980])
hold on
plot(t,ym, 'o', 'Color', 'yellow')
set(findall(gcf,'Type','line'),'LineWidth',2)
grid on
legend('PWM','ym - Saída ADC')




