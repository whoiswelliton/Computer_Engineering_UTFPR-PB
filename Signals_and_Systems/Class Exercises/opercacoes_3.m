clc;
clear all;
close all;

t=-7:0.001:15;

xt=heaviside(t-1)+(t-2).*heaviside(t-2)-(t-3).*heaviside(t-3)-2*heaviside(t-5);

plot(t,xt);

title('Sinal original');

t2=-t; %espelhamento do tempo para geração do sinal refletido

xt_r=heaviside(t2-1)+(t2-2).*heaviside(t2-2)-(t2-3).*heaviside(t2-3)-2*heaviside(t2-5); %sinal refletido

figure;

plot(t,xt_r);

title('Sinal refletido');

t3=t/2-1;

yt=2*(heaviside(t3-1)+(t3-2).*heaviside(t3-2)-(t3-3).*heaviside(t3-3)-2*heaviside(t3-5)); 
figure;
plot(t,yt);
xlabel('tempo (s)');
xlabel('amplitude de yt');
xmin=0;
xmax=15;
ymin=-1;
ymax=5;
axis([xmin xmax ymin ymax]);
grid;