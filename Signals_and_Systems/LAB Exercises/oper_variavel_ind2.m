clear all;

clc;

n= -20:20

fn = 4*sin(4*pi*n/19) % sinal original

fn_r = 4*sin(4*pi*(-n)/19) % sinal refletido

fn_d = 4*sin(4*pi*(n-3)/19) %sinal deslocado em 3 para a direita

fn_c = 4*sin(4*pi*(2*n)/19) %sinal comprimido em 2 vezes

stem(n,fn)

title('Sinal original');

figure % comando para apresentar as figuras em janelas separadas

stem(n,fn_r);

title('Sinal refletido');

figure % comando para apresentar as figuras em janelas separadas

stem(n,fn_d);

title('Sinal deslocado em 3 para a direita');

figure % comando para apresentar as figuras em janelas separadas

stem(n,fn_c);

title('Sinal comprimido em 2 vezes');