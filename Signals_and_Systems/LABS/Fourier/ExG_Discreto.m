clear;
close all;
clear all;

n=-14:14;
N=14;
w0 = 2*pi/14;
xn=0; 


for k = 0:13   
    xn = xn + 1/N*(exp(j*k*w0*(n-1)) + 2*exp(j*k*w0*(n-2)) + 3/2*exp(j*k*w0*(n-3)) + 1*exp(j*k*w0*(n-4)) + 1/2*exp(j*k*w0*(n-5)) + exp(j*k*w0*(n-6)) + 3/2*exp(j*k*w0*(n-7)) + 2*exp(j*k*w0*(n-8)) + 2*exp(j*k*w0*(n-9)) + 2*exp(j*k*w0*(n-10)) + 3/2*exp(j*k*w0*(n-11)) + exp(j*k*w0*(n-12)) + 1/2*exp(j*k*w0*(n-13)));
end


stem(n,xn); 
ylim([0 4]); 
xlim([-15 15]);
