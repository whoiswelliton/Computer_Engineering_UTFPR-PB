%%
s = tf('s');
Gs1k = 12653.76/(s + 12653.76);
step(Gs1k)

title('1k')
xlabel('tempo')
ylabel('deslocamento')
grid

figure
%%
Gs10k = 1305.55/(s + 1305.55);
step(Gs10k)

title('10k')
xlabel('tempo')
ylabel('deslocamento')
grid

