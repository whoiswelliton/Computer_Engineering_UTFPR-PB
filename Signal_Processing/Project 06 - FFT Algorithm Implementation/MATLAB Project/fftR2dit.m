% Função FFT Radix 2 Decimação no Tempo (DIT)   
% Processamento de Sinais
% Welliton Jhonathan Leal Babinski 

%Sinal não periódico de entrada
%x = [2; 4; 5 ;6 ;9 ;8 ;7; 2 ;12 ;13; 14 ;2; 12; 7; 2; 14];

function [y] = fftR2dit(x)                                            
tic                                                                         % iniciando a contagem do tempo

p = nextpow2(length(x));                                                    % checando o tamanho do vetor de entrada
x = [x zeros(1,(2^p)-length(x))];                                           % complementando o vetor com zeros se necessário
N = length(x);                                                              % calculando o tamanho do array
R = log2(N);                                                                % calculando o número de estágios de conversão
Metade = 1;                                                                 % Setando o valor de "Metade" inicial
x = bitrevorder(x);                                                         % colocando os samples em ordem de bit-reversa

for stage = 1:R                                                             % Estágios da transformada
    for index = 0:(2^stage):(N-1)                                           % serie de cálulas (butterflies) pra cada estágio
        for n = 0:(Metade-1)                                                % criando a célula (butterfly) e salvando os resultados
            pos = n + index + 1;                                            % indexando a amostra
            pow = (2^(R-stage))*n;                                          % parte da potência do multiplicador complexo
            WN = exp((-1i)*(2*pi)*pow/N);                                   % Multiplicador complexo
            a = x(pos) + x(pos+Metade).*WN;                                 % criando a primeira parte da célula 
            b = x(pos) - x(pos+Metade).*WN;                                 % criando a segunda parte da célula 
            x(pos) = a;                                                     % salvando o cálculo da primeira parte
            x(pos + Metade) = b;                                            % salvando o cálculo da segunda parte
        end
    end
    Metade = 2 * Metade;                                                    %calculando o próximo valor "Metade"
end
y = x;  
toc                                                                         %finalizando a contagem do tempo

L = 0:length(x)-1;
figure                                                                      %plotando os módulos das amostras
subplot(2,1,1)
stem(L,abs(y))
title("Módulo com Algoritmo de Decimação no Tempo FFT Radix-2");
xlabel('k');

subplot(2,1,2)                                                              %plotando as fases das amostras
stem(L,angle(y))
title("Fase com Algoritmo de Decimação no Tempo FFT Radix-2");
xlabel('k');
end