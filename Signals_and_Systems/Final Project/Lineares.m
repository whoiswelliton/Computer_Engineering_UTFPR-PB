close all;
clear all;
clc;

% Exercicio-1: Obtenha as raízes dos polinômios 
% ideia: armazenar os coeficiente dos polinômios em vetores 
% e usar a função roots que calcula a raízes

% alternativa a
x1 = [6 5 -5 0];
Xr1 = roots(x1)

% alternativa b
x2 = [1 0 0 4 0 0 1];
Xr2 = roots(x2)

% alternativa c
x3 = [1 0 2 -10];
x4 = [2 -10 0];
Xr34 = roots(conv(x3,x4))

% Exercicio-2: Obtenha os polinômios que possuem as seguintes raízes
% ideia: armazera as raízes em vetores e usar a função poly pra achar
% os polinômios

% alternativa a
Xa = [-3 8];
Xra = poly(Xa)

% alternativa b
Xb = [-4 5 2];
Xrb = poly(Xb)

% alternativa c
Xc = [-5 -6+9j -6-9j];
Xrc = poly(Xc)


% Exercicio-3: Expandir as seguintes B(s)/A(s) em frações parciais 
% utilizando o Matlab.
% ideia: usar a função residue para encontra os resíduos (r), pólos (p)
% e termos diretos (k) de uma expansão em frações parciais

%alternativa a
A1 = [128];
A2 = [4 32 64];
[r1,p1,k1] = residue(A1,A2)

%alternativa b
B1 = [1 8];
B1x = [1 2];
B2 = conv(conv(B1x,B1x),conv(B1x,B1x));
[r2,p2,k2] = residue(B1,B2)

%alternativa c
C1x = [1 -1];
C2x = [1 3];
C1 = conv(C1x,C2x);
C3x = [1 6];
C4x = [1 5];
C5x = [1 2];
C2 = conv(conv(C3x,C4x),C5x);
[r3,p3,k3] = residue(C1,C2)

% Exercicio - 4:Criar duas funções senoidais de tempo contínuo 
% com as seguintes características:
% x1(t) com amplitude de 40 e frequência de 30Hz. (Plotar para conferência)
% x2(t) com amplitude de 5 e frequência de 40Hz. (Plotar para conferência)

T1 = 1/30;   %periodo 1
t=-0.1:0.001:0.1;
xa = 40*sin(2*pi*t/T1);
figure;
plot(t, xa);
title('Sinal - xa');
grid;

T2 = 1/40; %periodo 2
xb = 5*sin(2*pi*t/T2);
figure;
plot(t, xb);
title('Sinal - xb');
grid;

% alternativa a
xa = 40*sin(2*pi*(t - pi/4)/T1);
ya = 2*xa;
figure;
plot(t,ya);
title('Sinal - a');
grid;
% alternativa b
xa = 40*sin(2*pi*t/T1);
yb = 3*xa + 4*xb;
figure;
plot(t, yb);
title('Sinal - b');
grid;
% alternativa c
yc = xa.*xb;
figure;
plot(t,yc);
title('Sinal - c');
grid;
% alternativa d
xb = 5*sin(2*pi*(-t)/(2*T2));
yd = -2*xb;
figure;
plot(t,yd);
title('Sinal - d');
grid;
% alternativa e
xa = 40*sin(2*pi*(-3*t + pi/3)/T1);
ye = 3*xa;
figure;
plot(t,ye);
title('Sinal - e');
grid;

% Exercicio - 5: Criar duas funções senoidais de tempo discreto com as seguintes características:
% x1(n) com amplitude de 20 e período de 15 amostras. (Plotar para conferência)
% x2(n) com amplitude de 2 e período de 10 amostras. (Plotar para conferência)
% Plotar os sinais a seguir:

n = -16:16;
T1 = 15; % periodo 1
x1 = 20*sin(2*pi*n/T1);
figure;
stem(n,x1);
title('Sinal - x1');
grid;
T2 = 10; % periodo 2
x2 = 2*sin(2*pi*n/T2);
figure;
stem(n,x2);
title('Sinal - x2');
grid;

% alternativa a

ya = 3*x1;
figure;
stem(n,ya);
title('Sinal - a');
grid;

% alternativa b

yb = 4*x1 - 2*x2;
figure;
stem(n,yb);
grid;
title('Sinal - b');

% alternativa c

x1 = 20*sin(2*pi*(-n)/T1);
x2 = 2*sin(2*pi*(-n)/T2);
yc = (2*x1).*x2;
figure;
stem(n,yc);
title('Sinal - c');
grid;

% alternativa d

x2 = 20*sin(2*pi*n/T2);
yd = -3*x1 + 2*x2;
figure;
stem(n,yd);
title('Sinal - d');
grid;

% alternativa e

x1 = 20*sin(2*pi*(-5*n + 3)/T1);
ye = x1;
figure;
stem(n,ye);
title('Sinal - e');
grid;

% Exercicio - 6: Dadas as funções x(t) e y(t) aprensentadas no grafico 

% alternativa a: Representar como um somatório de rampas e degraus e logo em seguida
% plotar para verificação.
t = -1:0.001:7;
xt = heaviside(t) + (t-1).*heaviside(t-1) - 3*(t-2).*heaviside(t-2) + 2*(t-3).*heaviside(t-3) - heaviside(t-3) + (t-3).*heaviside(t-3) -(t-5).*heaviside(t-5) - heaviside(t-5);
figure;
plot(t,xt);
title('Sinal - xt');
grid;
yt = 2*heaviside(t-1) - 2*(t-1).*heaviside(t-1) +2*(t-2).*heaviside(t-2) - heaviside(t-2) +(3/2)*(t-3).*heaviside(t-3) - (3/2)*(t-5).*heaviside(t-5) - 2*heaviside(t-5);
figure;
plot(t,yt);
title('Sinal - yt');
grid;

% alternativa b: Obter e plotar z(t)= x(2t-1)

x1t = heaviside((2*t - 1)) + ((2*t - 1)-1).*heaviside((2*t-1)-1) - 3*((2*t - 1)-2).*heaviside((2*t - 1)-2) + 2*((2*t -1)-3).*heaviside((2*t - 1)-3) - heaviside((2*t - 1)-3) + ((2*t -1)-3).*heaviside((2*t - 1)-3) - ((2*t - 1)-5).*heaviside((2*t - 1)-5)- heaviside((2*t - 1)-5);
z1 = x1t;
figure;
plot(t,z1);
title('Sinal - z1');
grid;
% alternativa c: Obter e plotar z(t)= x(t-1) y(t+1)
t1 = t-1;
t2 = t+1;
x3t = heaviside(t1) + (t1-1).*heaviside(t1-1) - 3*(t1-2).*heaviside(t1-2) + 2*(t1-3).*heaviside(t1-3) - heaviside(t1-3) + (t1-3).*heaviside(t1-3) - (t1-5).*heaviside(t1-5) - heaviside(t1-5);
y3t = 2*heaviside(t2-1) - 2*(t2-1).*heaviside(t2-1)+ 2*(t2-2).*heaviside(t2-2) - heaviside(t2-2)+(3/2)*(t2-3).*heaviside(t2-3) - (3/2)*(t2-5).*heaviside(t2-5) - 2*heaviside(t2-5);
z2 = x3t.*y3t;
figure;
plot(t,z2);
title('Sinal - z2');
grid;

% alternativa d: Obter e plotar z(t)= - x(-2t-1)+ y(t-1)
t1 = -2*t - 1;
t2 = t-1;
x4t = heaviside(t1) + (t1-1).*heaviside(t1-1) - 3*(t1-2).*heaviside(t1-2) + 2*(t1-3).*heaviside(t1-3) - heaviside(t1-3) + (t1-3).*heaviside(t1-3) - (t1-5).*heaviside(t1-5) -heaviside(t1-5);
y4t = 2*heaviside(t2-1) - 2*(t2-1).*heaviside(t2-1) + 2*(t2-2).*heaviside(t2-2) - heaviside(t2-2) + (3/2)*(t2-3).*heaviside(t2-3) - (3/2)*(t2-5).*heaviside(t2-5) - 2*heaviside(t2-5);
z3 = (-x4t) + y4t;
figure;
plot(t,z3);
title('Sinal - z3');
grid;


%\end

