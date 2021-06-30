clc;
close all;

%s=tf('s');

G = 1219512195.122/(s^2 + 2200*s + 1219512195.122);

h = bodeplot (G);
legend('RLC Filter');
figure(2)
grid;