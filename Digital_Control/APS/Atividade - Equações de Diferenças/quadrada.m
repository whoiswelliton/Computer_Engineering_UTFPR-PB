%% Sinal de entrada = Sinal Senoidal
clc;

N = 100;        %Qt de de pontos de simulação
A = 5;          % amplitude da senoide
Ts = 1e-1;      % periodo de amostragem
NA = 40;        % numero de amostras/ciclo
NC = 3;         % numero de ciclos
To = NA*Ts;     % periodo fundamental
fo = 1/To;      % frequncia fundamental
NT = NA*NC;     % numero total de pontos
TT = NT*Ts;     % tempo total do gráfico

t = 0:Ts:TT;
x = zeros(1,N);   %inicializacao de x
y = zeros(1,N);   %inicializacao de y
k = 0;            %inicializando k

%Laço de repetição
%Contador iniciando em 3 devido ao deslocamento y(n-2) 
for n=3:N
   
    x(n) = 5;
    k = k+1;
    if k > 20 
        x(n) = 0;
    end
    if k>40
        k=0;
    end
    
    %Equação de diferenças y(n) obtida
    y(n) = (8*y(n-1) - 3*y(n-2) + 4*x(n-1) + x(n-2))/10;
    
    %Teste com outros coeficientes 
    %y(n) = (6*y(n-1) - 1*y(n-2) + 3*x(n-1) + 0.8*x(n-2))/10;
    
end
figure
subplot(2,2,1); stem(x); xlim([0 100]);
title('Entrada X[n]');
subplot(2,2,2); 
stem(y, 'r'); xlim([0 100]);
title('Saída Y[n]');
subplot(2,2,[3 4]);
title('Equação de diferenças');
hold on; stem(x); stem(y,'r');xlim([0 100]);
grid;