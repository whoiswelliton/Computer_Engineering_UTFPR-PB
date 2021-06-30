clc;
close all;

%Filtro RLC
num = [9775171.0654936];
den = [1 4838.7096774194 9775171.0654936]

%Filtro Sallen-Key
num2 = [96711798.839458];
den2 = [1 6673.1141199226 96711798.839458]

G= tf(num,den)
G2= tf(num2,den2)
bode(G,G2),
grid;