clc;   %limpa a tela 
clear all;  %apaga a memória de variáveis
close all;          %fecha as figuras abertas  

A=[0 1 0.5 0.5; 2 2 1 0; 4 4 -2 0; 8 16 0 0]; %cria a matriz A 
B=[1; 0; 4; 8];  %cria a matriz B 
C=[-1 0 0 0];  %cria a matriz C 
D=1;   %cria a matriz D

F = ss(A,B,C,D)  %cria uma classe de dados do tipo espaço de estados. 
step(F);  %verificação da resposta para entrada degrau 