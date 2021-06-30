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
T=0.1e-3; % Per. de amost. Sist. Discreto
s=tf('s');

%% Parametros do modulador PWM
E=24;
NbitsPWM=8;
P=2^NbitsPWM;
Vmax=30; % Tensão máxima na planta


%% Parâmetros do sinal de referência
Aref=12; % Amplitude da referência
Oref=6; % Offset da referência
ACref=2*50;% Amostras por ciclo da ref.
NC=4; % Número de ciclos
N=NC*ACref;% Número de pontos totais
kq=0;

%% Definição dos parâmetros do conv.A/D
EAD=3; % Entrada do conversor A/D
NbitsAD=10; % Num. de bits do conv. A/D
Q=2^NbitsAD; % Num. de niveis conv. A/D
offsetCS=0.5;
K=EAD/Vmax; % Ganho transdut.(div.res.)

%% Definição e discretização da planta

Tc=T/P; % Periodo de amostragem
Pc=9e6/(s^2+3e3*s+9e6); %Planta contínua
Pd=c2d(Pc,Tc); %Planta discreta
[npd,dpd]=tfdata(Pd,'v');%Coefic. da ED
a1=dpd(2);
a0=dpd(3);
b1=npd(2);
b0=npd(3);

%% Discretiz. do condicion. de sinais
Sc=36e6/(s^2+3e3*s+36e6);
Sd=c2d(Sc,Tc);
[nsd,dsd]=tfdata(Sd,'v');
as1=dsd(2);
as0=dsd(3);
bs1=nsd(2);
bs0=nsd(3);

%% Ganhos do controlador
K1=0.11;
K2=0.25;

%% Inicialização dos vetores de simulação
t=zeros(1,N);
x=zeros(1,N);
e=zeros(1,N);
u=zeros(1,N);
d=zeros(1,N);
tc=zeros(1,N*P);
PWM=zeros(1,N*P);
y=zeros(1,N*P);
yt=zeros(1,N*P);
yr=zeros(1,N*P);
ys=zeros(1,N*P);
yo=zeros(1,N*P);
yA=zeros(1,N);
yR=zeros(1,N*P);
yQ=zeros(1,N);
ym=zeros(1,N);

%% INICIO DA SIMULACAO
for k=2:N
    
    % Vetor de tempo disc.para graficos
    t(k)=k*T;

    % Geração do sinal de referência
        if kq <= ACref/2
            x(k) = Aref+Oref;
        else
            x(k)=Oref;
        end
        kq=kq+1;

        if kq==ACref
            kq=0;
        end

    % Malha de Controle
    e(k)=x(k)-ym(k);
    
    u(k)=u(k-1)+K1*e(k)-K1*K2*e(k-1);
    
    
    d(k)=abs(u(k))*P/E;
    su=sign(u(k));

        % Superdiscr. da etapa 'continua'
        for cc=1:P
            % Contador e vetor de tempo do sist. Superdisc.
            kc=k*P+cc;
            tc(kc)=kc*Tc;
            % Geraçãodo PWM(kc)
            if cc<=d(k) 
                PWM(kc)=su*E+1*randn; 
            end
            if cc>d(k) 
                PWM(kc)=0; 
            end

            y(kc+1)=-a1*y(kc)-a0*y(kc-1)+b1*PWM(kc)+b0*PWM(kc-1); % Planta com entrada PWM
            yr(kc+1)=y(kc+1)+0.1*randn; % Ruido de medida
            yt(kc+1)=yr(kc+1)*K; % Transdutor (div. res.)                 %yr(kc+1)*K;
            ys(kc+1)=-as1*ys(kc)-as0*ys(kc-1)+bs1*yt(kc)+bs0*yt(kc-1); % Condic. de sinais
            yo(kc+1)=ys(kc+1)+0.01*randn+offsetCS; % Ruido no CCS
        end % Fim da simulacao 'continua'

    % Simulacao do conversor A/D
    yA(k+1)=yo(kc+1); % Amostragem –último valor ‘instantâneo’
    for i=(kc+1):(kc+1+P) 
        yR(i)=yA(k+1); 
    end % Retenção (kc+1 ?kc+1+P)
    yQ(k+1)=round(yR(kc+1)*Q/EAD)/Q*EAD; % Quantização ADC n bits Q=2^n
    ym(k+1)=(yQ(k+1)-offsetCS)/K; % Ajuste para valor original
    
    
end % Fim da simulacao discreta
%tc(kc+1) = 1
%% Graficos
figure; hold on;
plot(t,x,'LineStyle',':','LineWidth',2);
plot(tc,'LineWidth',2);
grid on
legend('Referencia','','Saída')

figure; hold on;
plot(tc,yt); plot(tc,ys); plot(tc,yo);
set(findall(gcf,'Type','line'),'LineWidth',2)
grid on
legend('Ytransdutor','Yfiltrado','Yoffset')