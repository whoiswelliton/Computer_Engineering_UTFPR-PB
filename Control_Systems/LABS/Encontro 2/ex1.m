clc;
close all;

s=tf('s');

Gs=0.9091/(s+1.8182);
R=6*Gs;
step(R);
figure(1)
legend('GS1');
grid;
