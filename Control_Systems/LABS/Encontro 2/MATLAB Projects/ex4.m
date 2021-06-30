clc;
close all;

num = [9775171.0654936];
den = [1 4838.7096774194 9775171.0654936]
G= tf(num,den)
bode(G),
grid;