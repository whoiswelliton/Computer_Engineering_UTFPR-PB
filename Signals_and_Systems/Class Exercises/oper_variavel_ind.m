clear all;

clc;

t= -10:0.01:10

ft = 4*sawtooth(t) % sinal original

ft_r = 4*sawtooth(-t) % sinal refletido

ft_d = 4*sawtooth(t-2) %sinal deslocado em 2 para a direita

ft_c = 4*sawtooth(2*t) %sinal comprimido em 2 vezes

plot(t,ft)

title('Sinal original');

figure % comando para apresentar as figuras em janelas separadas

plot(t,ft_r);

title('Sinal refletido');

figure % comando para apresentar as figuras em janelas separadas

plot(t,ft_d);

title('Sinal deslocado em 2 para a direita');

figure % comando para apresentar as figuras em janelas separadas

plot(t,ft_c);

title('Sinal comprimido em 2 vezes');