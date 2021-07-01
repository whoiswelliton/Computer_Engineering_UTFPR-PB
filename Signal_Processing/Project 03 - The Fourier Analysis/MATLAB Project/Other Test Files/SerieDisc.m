% Exemplo serie de Fourier em tempo discreto
% video associado: https://youtu.be/MnxffUdZmsI

% LAA 8/09/17

clear
close all

% parametros 
m=3;
N=5;

% frequencia fundamental
wo=2*pi/N;

n=1:20;
x(n)=sin(m*wo*n);

% senoide "continua" para ajudar a guiar o olho no grafico
% esta senoide nao eh usada para mais nada
t=0:pi/100:15;
X=sin(3*wo*t);


figure(1)
subplot(211)
set(gca,'FontSize',18)
stem(n, x)
hold on
stem(0, x(N))
plot(t,X,'k--')
hold off
xlabel('n')
ylabel('x[n]') 
axis([-0.1 length(n)-N -1.2 1.2])


%%
j=sqrt(-1);

% a serie de Fourier (apenas para valores maiores que zero para evitar indices negativos ou nulos no MATLAB)
a=zeros(1,18);
for k=3:5:18
  a(k)=1/(2*j);
end;
for k=2:5:17
  a(k)=-1/(2*j);
end;

% sintese do sinal a partir da soma de fasores de quaisquer 5 valores
% consecutivos de k (>0 e ate 18 neste exemplo);

% escolha o k inicial (note que para qualquer valor de k o sinal sintetizado eh o mesmo):
k=1;

% fasores
f1(n)=a(k)*exp(j*k*wo*n);
k=k+1;
f2(n)=a(k)*exp(j*k*wo*n);
k=k+1;
f3(n)=a(k)*exp(j*k*wo*n);
k=k+1;
f4(n)=a(k)*exp(j*k*wo*n);
k=k+1;
f5(n)=a(k)*exp(j*k*wo*n);

% soma dos fasores para resultar no sinal sintetizado
xs(n)=f1(n)+f2(n)+f3(n)+f4(n)+f5(n);

% soma dos fasores "classicos"
xc(n)=a(3)*exp(j*3*wo*n)+conj(a(3))*exp(-j*3*wo*n);

figure(1)
subplot(212)
set(gca,'FontSize',18)
stem(n, xs)
hold on
stem(0, xs(N))
plot(n, xc,'r+')
plot(0, xc(N),'r+')
plot(t,X,'k--')
hold off
xlabel('n')
ylabel('x[n]') 
axis([-0.1 length(n)-N -1.2 1.2])

% print -dpng SerieDisc.png
