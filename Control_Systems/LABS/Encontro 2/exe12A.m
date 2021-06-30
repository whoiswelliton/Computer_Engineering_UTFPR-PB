clc;
clear all;
close all;

s=tf('s')
Gs=2*(3/2)/(s + 2);

step(2*Gs);
grid;
