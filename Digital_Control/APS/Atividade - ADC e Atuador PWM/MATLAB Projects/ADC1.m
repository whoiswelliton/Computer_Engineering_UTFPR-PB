%% SISTEMA DE CONTROLE DIGITAL
% - Referência Digital
% - Controlador Digital
% - Modulador PWM
% - Planta 'contínua'
% - Ruído de medição
% - Condicionamento de sinais
% - Conversor A/D
% - Filtro Digital


clear
clc
close all
T = 0.1e-3; % Per. de amost. Sist. Discreto / Tempo da amostragem / Chaveamento
s = tf('s'); 

%% Parametros do modulador PWM

E = 24;
NbitsPWM = 8;
P = 2^NbitsPWM; % num de níveis do PWM
Vmax = 30; % Tensão máxima na planta

%% Parâmetros do sinal de referência

Aref = 12; % Amplitude da referência
Oref = 6; % Offset da referência
ACref = 2*50; % Amostras por ciclo da ref. (NAC)
NC = 2; % Número de ciclos
N = NC*ACref; % Número de pontos totais
kq = 0;

%% Definição dos parâmetros do conv.A/D

EAD = 3; % Entrada do conversor A/D
NbitsAD = 10; % Num. de bits do conv. A/D
Q = 2^NbitsAD; % Num. de niveis conv. A/D
offsetCS = 0.5;
K = EAD / Vmax; % Ganho transdut.(div.res.)


%% Planta e Coeficientes da Equação de Diferenças

% Periodo de amostragem
Tc = T/P; 
%Planta Contínua P(s) / Função de Transferência em Tempo Contínuo (CTTF)
Pc = 9e6 / (s^2 + 3e3*s + 9e6); 
%Planta Discreta P(z) / Função de Transferência em Tempo Discreto (DTTF) 
Pd = c2d(Pc,Tc);

%Coeficientes ED
[npd,dpd] = tfdata(Pd,'v')
a1 = dpd(2); 
a0 = dpd(3);
b1 = npd(2); 
b0 = npd(3);

%% Condicionamento de Sinais e Coeficientes da Equação de Diferenças

%Sensor Contínuo P(s) 
Sc = 36e6 / (s^2 + 3e3*s + 36e6);    
%Sensor Discreto
Sd = c2d(Sc,Tc);

%Coeficientes ED
[nsd,dsd] = tfdata(Sd,'v')
as1 = dsd(2); 
as0 = dsd(3);
bs1 = nsd(2); 
bs0 = nsd(3);

%% Ganhos do controlador

K1 = 0.11;
K2 = 0.25;

Kp = 0.25;
Ki = 0.125;
Kd = 1;

%% Inicialização dos Vetores

t = zeros(1,N);  %variavel de tempo
x = zeros(1,N);  %referencia
e = zeros(1,N);  %erro
d = zeros(1,N);

tc = zeros(1,N*P);
PWM = zeros(1,N*P);

u = zeros(1,N);       %controlador ANTIGO
uP = zeros(1,N);       %Controle Proporcional
uI = zeros(1,N);       %Controle Integral
uD = zeros(1,N);       %Controle Derivativo
uPID = zeros(1,N);

y = zeros(1,N*P);  %saida planta
yt = zeros(1,N*P);
yr = zeros(1,N*P); %planta + ruído
ys = zeros(1,N*P);
yo = zeros(1,N*P);
yA = zeros(1,N);
yR = zeros(1,N*P);
yQ = zeros(1,N);
ym = zeros(1,N); %saida sensor


%% Simulação

for k = 2:N
    % Vetor de tempo disc. para graficos
    t(k) = k*T;
    kq = kq + 1;
    
    % Geração do sinal de referência
    if kq <= ACref/2
        x(k) = Aref + Oref;
    else
        x(k) = Oref;
    end
    
    %kq = kq+1;
        
    if kq == ACref
        kq = 0;
    end
    
    % Malha de Controle
    
    e(k)= x(k) - ym(k); %erro = referencia + saida sensor (será filtro)
    
    %u(k) = u(k-1) + K1*e(k)-K1*K2*e(k-1);  %saida do controlador 
    
    uP(k) = Kp*e(k);                %Controle Proporcional
    uI(k) = uI(k-1) + Ki*e(k);        %Controle Integral
    uD(k) = Kd*(e(k) - e(k-1));       %Controle Derivativo
    uPID(k) = uP(k) + uI(k) + uD(k);    %Controle PID
    
    d(k) = abs(uPID(k))*P/E;
    su = sign(uPID(k)); 
    
    % Superdiscr. da etapa 'continua'
    for cc = 1:P
        % Contador e vetor de tempo do sist. Superdisc.
        kc = k*P + cc;
        tc(kc) = kc*Tc;

        % Geraçãodo PWM(kc)
        if cc <= d(k) 
            PWM(kc) = su*E + 1*randn; 
        end
        if cc > d(k) 
            PWM(kc) = 0; 
        end

        % Saída da planta (Vo) com entrada PWM
        y(kc+1)=-a1*y(kc)-a0*y(kc-1)+b1*PWM(kc)+b0*PWM(kc-1);       
        
        % Ruido de medida
        yr(kc+1) = y(kc+1) + 0.1*randn;
        %yr(kc+1) = y(kc+1) + 0.01*3*randn;
        
        % Transdutor (div. res.)
        yt(kc+1) = yr(kc+1)*K;
        
        % Condic. de sinais
        ys(kc+1) = -as1*ys(kc) - as0*ys(kc-1) + bs1*yt(kc) + bs0*yt(kc-1); 
        
        % Ruido no CCS
        yo(kc+1) = ys(kc+1) + 0.01*randn + offsetCS;
    end
    % Fim da simulacao 'continua'
    
    % Simulacao do conversor A/D
    
    yA(k+1) = yo(kc+1);                     % Amostragem – último valor ‘instantâneo’
    for i = (kc+1):(kc+1+P) 
        yR(i) = yA(k+1); 
    end % Retenção (kc+1 ?kc+1+P)
    
    yQ(k+1) = round(yR(kc+1)*Q/EAD)/Q*EAD;    % Quantização ADC n bits Q=2^n
    ym(k+1) = (yQ(k+1) - offsetCS)/K;          % Ajuste para valor original
    
    
    
 
end

%% Graficos

y(k+1)=[];
yr(k+1)=[];
yt(k+1)=[];
ys(k+1)=[];
yo(k+1)=[];
ym(k+1)=[];



subplot(511)
plot(tc,yr)
hold on
plot(t,x,'--')
set(findall(gcf,'Type','line'),'LineWidth',2)
grid on
legend('yr - saida da planta','x - sinal de entrada')

subplot(512)
plot(t,e,'--','Color',[0.3010 0.7450 0.9330])
hold on
plot(t,uPID,':')
set(findall(gcf,'Type','line'),'LineWidth',2)
grid on
legend('e - sinal de erro','u - sinal de controle')

subplot(513)
plot(tc,yr)
hold on
plot(t,uPID,':')
set(findall(gcf,'Type','line'),'LineWidth',2)
grid on
legend('yr - saida da planta','u - sinal de controle')

subplot(514)
plot(tc,yr)
hold on
plot(t,x,'--')
hold on
plot(t,ym)
set(findall(gcf,'Type','line'),'LineWidth',2)
grid on
legend('yr - saida da planta','x - sinal de entrada','ym - saida do sensor')

subplot(515)
plot(t,uP)
hold on
plot(t,uI,'--')
hold on
plot(t,uD)
set(findall(gcf,'Type','line'),'LineWidth',2)
grid on
legend('uP','uI','uD')
