clc
clear all
close all

%% Invariância ao Impulso

f = 250;        %Frequência na banda passante
T = 1/10000;    %Período de amostragem
nc = 3;         %Número de ciclos
N = nc*(1/f)/T; %Número de pontos
A1 = zeros(1,N); %Declaração do vetor de entrada
y = zeros(1,N); %Declaração do vetor de saída
%Forma de onda da entrada

%%
% = 1/(1+1.4137*s + 999.3*(10^-3)*s^2); %FT do PB 2 Ordem

% %Polos
% p1 = -1,111*10^-3 + 1,111j*10^-3;
% p2 = -1,111*10^-3 - 1,111j*10^-3;

%A2 = ztrans(A1);

syms n z;




