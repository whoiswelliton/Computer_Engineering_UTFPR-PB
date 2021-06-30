%% Controle Digital - convolucao
clear;
%% Definição de sinais
% Valores obtidos do exercicio

N = 100;  %Qtde de pontos de simulação
A = 5; % amplitude da senoide
Ts = 0.001; % periodo de amostragem
To = 40; % periodo da onda quadrada
D = 0.5; % razao ciclica
NC = 4; % numero de ciclos

% Valores calculados a partir do gráfico
NA = To/Ts; % numero de amostras/ciclo
NT = NA*NC; % numero total de pontos
TT = NT*Ts; % tempo total do gráfico

% Geração dos sinais em vetores
t=0:Ts:TT;
nq=0;

% Inicializacao dos vetores
h=zeros(1,NT+1);
x=zeros(1,NT+1);
y=zeros(1,NT+1);
k=0;

%% Simulacao
for n=1:NT+1
    h(n) = 2^(-n*Ts); % resp.ao impulso
    nq=nq+1;
    x(n)= A;
    if nq>D*NA % onda retangular
    x(n)=0;
    end
    if nq==NA
    nq=0;
    end
    for k=1:NT+1 % Convolucao
        if (k < n)
            %y(n)= 4x(k)*h(n-1) + x(k)*h(n-2) + 8y(n-1)+ 3y(n-2);

            y(n)=y(n)+x(k)*h(n-k);
        end
    end
end
%% Geração dos Gráficos
figure
subplot(2,2,1); stem(x)
title('Gráfico de X[n]');
subplot(2,2,2); stem(y)
title('Gráfico de Y[n]');
subplot(2,2,[3 4]);
title('Equação de diferençaas');
hold on; stem(x); stem(y);
grid;