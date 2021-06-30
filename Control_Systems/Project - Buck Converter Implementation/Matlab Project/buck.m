clear all; 
close all;
clc;
 
s=tf('s');
 
DC = 50/100;
Vin = 24;
ZL = 0.3;
Ro = 12;
L = 1.163e-3;
C = 2.16e-6;
k=1;
PI = (1)/(s);
G = (Vin / (L*C)) / (s^2 + s*((1/(C*Ro))+ ZL/L) + (1/(L*C)) );
T = feedback(k*PI*G,1)
figure
rlocus(G);
figure
rlocus(T)
figure
step(T)