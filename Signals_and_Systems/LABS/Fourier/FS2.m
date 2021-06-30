%operações com as variáveis dependentes
clc; %limpa a tela
clear all; %limpa a memória
close all; %fecha todos os gráficos abertos

f1=60 %freq do sinal 1
T1=1/f1;
t=0:T1/200:3*T1;

ft1=4*sin(2*pi*f1*t);


plot(t,ft1);
title('Função Senoidal 1');
xlabel('tempo (s)');
ylabel('amplitude');
grid;

f2=180 %freq do sinal 2
T2=1/f2;
ft2=1/2*sin(2*pi*f2*t);

figure;
plot(t,ft2);
title('Função Senoidal 2');
xlabel('tempo (s)');
ylabel('amplitude');
grid;

figure;
plot(t,ft1,t,ft2);
title('Função Senoidais');
xlabel('tempo (s)');
ylabel('amplitude');
legend('função 1','função 2');
grid;

FR1=2*ft1+3*ft2;
figure;
plot(t,FR1);
title('Função Resultante');
xlabel('tempo (s)');
ylabel('amplitude');

FR2=ft1.*ft2; %mult elemento/elemento
figure;
plot(t,FR2);
title('Função Resultante 2');
xlabel('tempo (s)');
ylabel('amplitude');







