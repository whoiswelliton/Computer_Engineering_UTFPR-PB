num = [1 7 10 -4 0];
den = [1 6 0 -48 -64];

TF = tf(num,den);
figure (1);
step (TF);
grid; hold on;
title('Modelo no dominio da frequencia');