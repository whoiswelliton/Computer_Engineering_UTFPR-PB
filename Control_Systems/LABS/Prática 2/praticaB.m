%%
s = tf('s');
Gs100 = (100000000000/(s^2+100000*s+100000000000));
step(Gs100)

title('100 Ohms')
xlabel('tempo')
ylabel('deslocamento')
grid

figure

%%
s = tf('s');
Gs50 = (100000000000/(s^2+5092000*s+100000000000));
step(Gs50)

title('50,92 Ohms')
xlabel('tempo')
ylabel('deslocamento')
grid

