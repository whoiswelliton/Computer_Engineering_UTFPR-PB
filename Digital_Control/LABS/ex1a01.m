% Limpar as variaveis da memoria
clear;
%% Definição de sinais
%% Valores obtidos diretamente do gráfico
A = 5 % amplitude da senoide
Ts = 2e-3; % periodo de amostragem
NA = 12; % numero de amostras por ciclo
NC = 2; % numero de
%% Valores calculados a partir do gráfico
To = NA*Ts; % periodo fundamental
fo = 1/To; % frequencia fundamental
NT = NA*NC; % numero total de
TT = NT*Ts; % tempo total do gráfico
%% Geração dos sinais em vetores
% representar o intervalo de tempo
t=0:Ts:TT;
% utilizar $x(t)=A sin(2\pi f t)$
x = A*sin(2*pi*fo*t);
plot(t,x,'r:','Linewidth',2)
hold on
stem(t,x,'r')
stairs(t,x,'g-o','Linewidth',2)