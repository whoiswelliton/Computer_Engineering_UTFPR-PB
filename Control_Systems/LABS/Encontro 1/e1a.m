%FUNÇÃO DE TRANSFERÊNCIA

num = [1 7 10 -4 0];
den = [1 6 0 -48 -64];

TF = tf(num,den);
figure (1);
step (TF);
grid; hold on;
title('Modelo no dominio da frequencia'); 

%ESPAÇO DE ESTADOS

clc; 
clear all;  
close all;        

A=[0 1 0.5 0.5; 2 2 1 0; 4 4 -2 0; 8 16 0 0]; 
B=[1; 0; 4; 8];  
C=[-1 0 0 0];  
D=[1];   

F = ss(A,B,C,D)   
step(F);  