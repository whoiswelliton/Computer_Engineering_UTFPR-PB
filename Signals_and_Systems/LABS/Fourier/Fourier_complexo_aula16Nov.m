clc;
clear all;
close all;

t=-10:0.001:10;

w0=2*pi/5;


X0=18/5;
X1=3*(exp(-6/5*j*pi)-1)/(-j*pi);
X1n=3*(exp(6/5*j*pi)-1)/(j*pi);


X2=3*(exp(-12/5*j*pi)-1)/(-2*j*pi);
X2n=3*(exp(12/5*j*pi)-1)/(2*j*pi);

X3=3*(exp(-18/5*j*pi)-1)/(-3*j*pi);
X3n=3*(exp(18/5*j*pi)-1)/(3*j*pi);

X4=3*(exp(-24/5*j*pi)-1)/(-4*j*pi);
X4n=3*(exp(24/5*j*pi)-1)/(4*j*pi);

X5=3*(exp(-30/5*j*pi)-1)/(-5*j*pi);
X5n=3*(exp(30/5*j*pi)-1)/(5*j*pi);



xt=X0*exp(j*0*w0*t)+X1*exp(j*1*w0*t)+X1n*exp(j*(-1)*w0*t)+X2*exp(j*2*w0*t)+X2n*exp(j*(-2)*w0*t)+X3*exp(j*3*w0*t)+X3n*exp(j*(-3)*w0*t)+X4*exp(j*4*w0*t)+X4n*exp(j*(-4)*w0*t)+X5*exp(j*5*w0*t)+X5n*exp(j*(-5)*w0*t);



plot(t,xt);

figure
plot(t,X0*exp(j*0*w0*t),t,X1*exp(j*1*w0*t)+X1n*exp(j*(-1)*w0*t),t,X2*exp(j*2*w0*t)+X2n*exp(j*(-2)*w0*t),t,X3*exp(j*3*w0*t)+X3n*exp(j*(-3)*w0*t))

grid;