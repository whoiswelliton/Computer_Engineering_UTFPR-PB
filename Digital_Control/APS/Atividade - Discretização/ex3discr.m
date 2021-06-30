%% Simulacao em Malha Fechada - Exercicio

%% Definições Iniciais
clear; clc; close all;

NAC = 2*50;
NC = 5; 
N = NC*NAC;
T = 0.1e-3;     %tempo da amostragem/chaveamento
s = tf('s');
z = tf('z',T);

%N=200; %Numeros de pontos

%% Inicialização dos Vetores

kq = 0; 
K1 = 0.11;
K2 = 0.25;

t = zeros(1,N);  %variavel de tempo
x = zeros(1,N);  %referencia
e = zeros(1,N);  %erro
u = zeros(1,N);  %saida controlador
y = zeros(1,N);  %saida planta
ym = zeros(1,N); %saida sensor
yt = zeros(1,N);
yr = zeros(1,N);


%% Planta e Coeficientes da Equação de Diferenças

%Planta Contínua P(s) / Função de Transferência em Tempo Contínuo (CTTF)
Pc = 9e6 / (s^2 + 3e3*s + 9e6); 
%Planta Discreta P(z) / Função de Transferência em Tempo Discreto (DTTF) 
Pd = c2d(Pc,T);

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
Sd = c2d(Sc,T);

%Coeficientes ED
[nsd,dsd] = tfdata(Sd,'v');
as1 = dsd(2); 
as0 = dsd(3);
bs1 = nsd(2); 
bs0 = nsd(3);

%% Simulação

for k = 2:N
    t(k) = k*T;
    kq = kq + 1;
    
    %sinal de referencia
    if kq <= NAC/2
        x(k) = 5;
    else
        x(k) = 0;
    end
    
    if kq == NAC
        kq = 0; 
    end
    
    %erro = referencia + saida sensor
    e(k)= x(k)-ym(k);
    
    %saida do controlador 
    u(k) = u(k-1) + K1*(e(k)-K2*e(k-1));
    
    %saida da planta
    y(k+1)= -a1*y(k) - a0*y(k-1) + b1*u(k) + b0*u(k-1);

    %adicionando ruído ao sistema
    yr(k+1) = y(k+1) + 0.01*5*randn;
    
    %saida do sensor
    ym(k+1)= -as1*ym(k) - as0*ym(k-1) + bs1*yr(k) + bs0*yr(k-1);
end

%% Gráficos das variáveis

y(k+1)=[];
yr(k+1)=[];
ym(k+1)=[];

subplot(211)
plot(t,yr)
hold on
plot(t,x,'--')
set(findall(gcf,'Type','line'),'LineWidth',2)
grid on
legend('yr - saida da planta + ruido','x - sinal de entrada')

subplot(212)
plot(t,yr)
hold on
plot(t,ym,'--')
set(findall(gcf,'Type','line'),'LineWidth',2)
grid on
legend('yr - saida da planta + ruido','ym - saida do sensor')