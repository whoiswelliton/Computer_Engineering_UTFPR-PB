s = tf('s');
Gs1k = 10000/(s + 10000);

step(Gs1k)
title('1k')
xlabel('tempo')
ylabel('deslocamento')
grid
figure
Gs10k = 1000/(s + 1000);
step(Gs10k)
title('10k')
xlabel('tempo')
ylabel('deslocamento')
grid

a1k = (11702.127 + 13605.4)/2;
Gs= a1k /(s + a1k);
figure
step(Gs)
title('1k - Pratica')
xlabel('tempo')
ylabel('deslocamento')
grid

a10k = (1222.22 + 1388.88)/2;
Gs= a10k /(s + a10k);
figure
step(Gs)
title('10k - Pratica')
xlabel('tempo')
ylabel('deslocamento')
grid