%Representação por série trigonometrica de Fourier
%aula 18/11/2015

clc;
clear all;
close all;

T=5;
w0=2*pi/T;

t=-10:0.001:10;

a0=18/5;

a1=6/(1*pi)*sin(3*1*w0);
b1=6/(1*pi)*(1-cos(3*1*w0));
c1=sqrt(a1^2+b1^2)

a2=6/(2*pi)*sin(3*2*w0);
b2=6/(2*pi)*(1-cos(3*2*w0));
c2=sqrt(a2^2+b2^2)

a3=6/(3*pi)*sin(3*3*w0);
b3=6/(3*pi)*(1-cos(3*3*w0));
c3=sqrt(a3^2+b3^2)

a4=6/(4*pi)*sin(3*4*w0);
b4=6/(4*pi)*(1-cos(3*4*w0));
c4=sqrt(a4^2+b4^2)

a5=6/(5*pi)*sin(3*5*w0);
b5=6/(5*pi)*(1-cos(3*5*w0));
c5=sqrt(a5^2+b5^2)

a6=6/(6*pi)*sin(3*6*w0);
b6=6/(6*pi)*(1-cos(3*6*w0));
c6=sqrt(a6^2+b6^2)

xt=a0+a1*cos(1*w0*t)+b1*sin(1*w0*t)+a2*cos(2*w0*t)+b2*sin(2*w0*t)+a3*cos(3*w0*t)+b3*sin(3*w0*t)+a4*cos(4*w0*t)+b4*sin(4*w0*t)+a5*cos(5*w0*t)+b5*sin(5*w0*t)+a6*cos(6*w0*t)+b6*sin(6*w0*t);

plot(t,xt);
grid;
figure
plot(t,a1*cos(1*w0*t)+b1*sin(1*w0*t),t,a2*cos(2*w0*t)+b2*sin(2*w0*t),t,a3*cos(3*w0*t)+b3*sin(3*w0*t),t,a4*cos(4*w0*t)+b4*sin(4*w0*t),t,a5*cos(5*w0*t)+b5*sin(5*w0*t),t,a6*cos(6*w0*t)+b6*sin(6*w0*t));
grid;



