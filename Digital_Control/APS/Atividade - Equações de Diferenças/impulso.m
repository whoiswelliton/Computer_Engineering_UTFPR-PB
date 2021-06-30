%% Impulso

clc;
N = 100;        % qtd de pontos de simulação
A = 5;          % amplitude da senoide
Ts = 1e-1;      % período de amostragem
NA = 50;        % numero de amostras/ciclo
NC = 2;         % número de ciclos
To = NA*Ts;     % per^íodo fundamental
fo = 1/To;      % frequncia fundamental
NT = NA*NC;     % número total de pontos
TT = NT*Ts;     % tempo total do gráfico

t=0:Ts:TT;
y = zeros(1,N+2); %inicialização de y
x = zeros(1,N);   %inicialização de x

%Laço de repetição
%Contador iniciando em 3 devido ao deslocamento y(n-2) 
for n=3:N 
    if n == 3  
        x(n)=A;
    else
        x(n)=0; end
    
    %Equação de diferenças y(n) obtida
    y(n) = (8*y(n-1) - 3*y(n-2) + 4*x(n-1) + x(n-2))/10;
    
    %Teste com outros coeficientes 
    %y(n) = (6*y(n-1) - 1*y(n-2) + 3*x(n-1) + 0.8*x(n-2))/10;
end
figure
%Plotando os 3 gráficos
subplot(2,2,1); 
stem(x); xlim([0 100]);
title('Entrada X[n]');
subplot(2,2,2); 
stem(y, 'r'); xlim([0 100]);
title('Saída Y[n]');
subplot(2,2,[3 4]);
title('Equação de diferenças');
hold on; stem(x); stem(y,'r');xlim([0 100]);
grid;