clear all;
close all; 
clc;                                                                 

input = load('dados.mat');    %importando os dados do sinal do arquivo .mat

%Plotando o sinal de entrada de tempo discreto 
subplot(2,1,1);
stem(-300:1:299,input.x,'LineStyle','none');
title('Sinal de Entrada Amostrado Completo'); ylabel('x[n]');xlabel('n');

%Plotando apenas 1 período do sinal de entrada 
subplot(2,1,2);
stem(-300:1:299,input.x,'LineStyle','none');
xlim([0 300]); title('Apenas Um Período do Sinal de Entrada');
ylabel('x[n]');xlabel('n');

%Definindo alguns parâmetros úteis
FS = 18000;                                      % Frequência de Amostragem              
T = 1/FS;                                                % Período do Sinal
L = length(input.x);                               % Quantidade de Amostras
N = L/2;                                             % Amostras por Período
t = -N:1:N-1;              %Invervalo total de onde podemos variar a Função

%t = (0:L-1)*T;
%w0 = 2*pi/N;

%% -------------ANÁLISE DO SINAL DE TEMPO DISCRETO PELA DTFS--------------

CK = zeros(1, L);         %inicializa um vetor de zeros do tamanho do sinal
   
%Implementação da equação de Análise da DTFS
for k = t
    %PNTR = k+1+N;                          %ponteiro para simplificar a EQ
    for n = 0:N-1
        CK(1,k+1+N) = CK(1,k+1+N) + input.x(n+1)*exp((-1i*2*pi*k*n)/N);
    end
    CK(1,k+1+N) = CK(1,k+1+N)*(1/N);
end 

ind = abs(CK) < 10e-10; 
CK(ind) = 0;                              %zerando valores próximos de zero

ampCK = abs(CK);                        %recebe os valores absolutos dos CK
phzCK = zeros(1,L);  
phzCK = unwrap(angle(CK))*180/pi;              %recebe os argumentos dos CK

%%
% [Módulo dos Coeficientes Ck em função de k]
figure
subplot(2,1,1);
stem(t,ampCK)
xlim([0 300]); 
title("Módulo dos Coeficientes Ck em função de k");
xlabel('k'); ylabel('$|\tilde{X}[k]|$','Interpreter','latex');

% [Fase dos Coeficientes 'Ck' em função de k]
subplot(2,1,2);
stem(t,phzCK);
xlim([0 300]);
title("Fase dos Coeficientes Ck em função de k");
xlabel('k');ylabel('$\angle\tilde{X}[k]$','Interpreter','latex');

%%
% [Módulo dos Coeficientes Ck no Espectro de Amplitude]
figure
P2 = abs(CK);
P1 = P2(1:N/2+1);
P1(2:end-1) = 2*P1(2:end-1);
f1 = FS*(0:(N/2))/N;

subplot(2,1,1);
stem(f1,P1*(1/N));
xlim([0 500]);              %limitando o range de frequências a ser exibido
title('Módulo dos Coeficientes Ck no Espectro de Amplitude')
xlabel('f (Hz)');ylabel('$|\tilde{X}[k]|$','Interpreter','latex');
yticks([-pi -pi/2 0 pi/2 pi]);
yticklabels({'-\pi','-\pi/2','0','\pi/2','\pi'});

% [Fase dos Coeficientes Ck no Espectro de Fase]
P4 = phzCK;
P3 = P4(1:N/2+1);
P3(2:end-1) = 2*P3(2:end-1);

subplot(2,1,2);
stem(f1,P3);
xlim([0 500]);
title('Fase dos Coeficientes Ck no Espectro de Fase')
xlabel('f (Hz)');ylabel('$\angle\tilde{X}[k]$','Interpreter','latex');
yticks(-pi:-pi/2:0);
yticklabels({'-\pi','-\pi/2','0'});

%% -------------SÍNTESE DO SINAL DE TEMPO DISCRETO PELA DTFS--------------

XK = zeros(1, L); 

%Implementação da equação de Síntese da DTFS
for k = t
    PNTR2 = k+1+N;
    for n=0:N-1
        XK(1,PNTR2) = XK(1,PNTR2) + CK(n+1)*exp((1i*2*pi*k*n)/N);
    end 
end

figure
stem(t,XK,'LineWidth',0.5,'MarkerFaceColor','Black',...
'MarkerEdgeColor','Black');
title("Síntese do Sinal pela DTFS");
ylabel('x[n]'); xlabel('n');

%% -------------ANÁLISE DO SINAL DE TEMPO DISCRETO PELA FFT---------------

FS2 = 300;
Y = fft(input.x);                        %comando da Fast Fourier Transform
L2 = 0:length(input.x)-1;

ind2 = abs(Y) < 10e-10; 
Y(ind2) = 0;                              %zerando valores próximos de zero
       
phz2CK = zeros(1,L);            
phz2CK = unwrap(angle(Y))*180/pi;

%% 
% [Módulo e Fase dos Coeficientes Xk em função de k]
figure
subplot(2,1,1)
stem(L2/2,abs(Y))
title("Módulo dos Coeficientes Xk em função de k");
xlabel('k'); ylabel('$|\tilde{X}[k]|$','Interpreter','latex');

subplot(2,1,2)
stem(L2/2,angle(Y))
title("Fase dos Coeficientes Xk em função de k");
xlabel('k');ylabel('$\angle\tilde{X}[k]$','Interpreter','latex');
yticks([-pi -pi/2 0 pi/2 pi]);
yticklabels({'-\pi','-\pi/2','0','\pi/2','\pi'});

%%
% [Módulo dos Coeficientes Xk no Espectro de Amplitude]
figure
P6 = abs(Y/L);
P5 = P6(1:L/2+1);
P5(2:end-1) = 2*P5(2:end-1);
f2 = FS*(0:(L/2))/L;

subplot(2,1,1);
stem(f2,P5*(1/N));
xlim([0 500]);              %limitando o range de frequências a ser exibido
title("Módulo dos Coeficientes Xk no Espectro de Amplitude")
xlabel('f (Hz)');ylabel('$|\tilde{X}[k]|$','Interpreter','latex');


% [Fase dos Coeficientes Xk no Espectro de Fase]
P8 = phz2CK;
P7 = P8(1:L/2+1);
P7(2:end-1) = 2*P7(2:end-1);

subplot(2,1,2);
stem(f2,P7);
xlim([0 500]);
title("Fase dos Coeficientes Xk no Espectro de Fase")
xlabel('f (Hz)');ylabel('$\angle\tilde{X}[k]$','Interpreter','latex');
yticks([-pi -pi/2 0]);
yticklabels({'-\pi','-\pi/2','0'});

%% -------------SÍNTESE DO SINAL DE TEMPO DISCRETO PELA FFT---------------

YK = zeros(1,L);

%Implementação da equação de Síntese da DTFS
for k = 0:1:L-1
    for n = 0:L-1
        YK(1,k+1) = YK(1,k+1) + Y(n+1)*exp((1i*2*pi*k*n)/L);
    end
    YK(1,k+1) = YK(1,k+1)*(1/L);
end

figure
stem(t,YK,'LineWidth',0.5,'MarkerSize',5,'MarkerFaceColor','red',...
'MarkerEdgeColor','red');
title("Síntese do Sinal pela FFT");
ylabel('x[n]');xlabel('n');

%% -----------------------SOBREPOSIÇÃO DOS 3 SINAIS-----------------------

figure
plot(t,input.x,'o','LineWidth',0.5,'MarkerSize',10);
hold on;
plot(t,XK,'--','LineWidth',5,'Color','black');
hold on;
plot(t,YK,'-','LineWidth',2,'Color','red');
hold off;
title('Sobreposição dos Três Sinais');
legend('Amostrado','Síntese Ck','Síntese FFT');
ylabel('x[n]');xlabel('n');

%% ---------COMPARAÇÃO DOS DOIS SINAS NO DOMÍNIO DA FREQUÊNCIA------------

% [Tabela com os valores encontrados pela DTFS]

VAR = {'K';'Frequencia';'Amplitude';'Fase'};
SMP = [1;2;4;6];
FQ = [f1(1);f1(2);f1(4);f1(6)];
AMP = [P1(1)/N;P1(2)/N;P1(4)/N;P1(6)/N];
ARG = [P4(301);P4(302);P4(304);P4(306)];

TABELA_DTFS = table(SMP,FQ,AMP,ARG,'VariableNames',...
    {'K','Frequencia','Amplitude','Fase'});

fig1 = uifigure;
uit1 = uitable(fig1,'Data',TABELA_DTFS);

%[Tabela com os valores encontrados pela FFT]

SMP2 = [1;3;7;11];
FQ2 = [f2(1);f2(3);f2(7);f2(11)];
AMP2 = [P5(1)/N;P5(3)/N;P5(7)/N;P5(11)/N];
ARG2 = [P8(1);P8(3);P8(7);P8(11)];

TABELA_FFT = table(SMP2,FQ2,AMP2,ARG2,'VariableNames',...
    {'K','Frequencia','Amplitude','Fase'});

fig2 = uifigure;
uit2 = uitable(fig2,'Data',TABELA_FFT);



%% ----------------------SINAL DA FUNÇÃO RECEBIDA-------------------------

input2 = 90 + 180*sin(2*pi*60*n/18000) + 60*sin(2*pi*180*n/18000)...
    + 30*sin(2*pi*300*n/18000);

figure
SK1 = 90 + zeros(1,600);
subplot(2,2,1)
plot(SK1);
xlim([0 600]); ylim([-200 200]);
title('Primeiro Componente Harmônico');

for n = 1:600
    SK2(n)  = 180*sin((2*pi*60*n)/18000);
end
subplot(2,2,2)
plot(SK2);
xlim([0 600]); ylim([-200 200]);
title('Segundo Componente Harmônico');

for n = 1:600
    SK3(n)  = 60*sin((2*pi*180*n)/18000);
end
subplot(2,2,3)
plot(SK3);
xlim([0 600]); ylim([-200 200]);
title('Terceiro Componente Harmônico');

for n = 1:600
    SK4(n)  = 30*sin((2*pi*300*n)/18000);
end
subplot(2,2,4)
plot(SK4);
xlim([0 600]); ylim([-200 200]);
title('Quarto Componente Harmônico');
