%%
s = tf('s');
Gst = (156200000000/(s^2+100000*s+156200000000));
step(Gst)

title('G(s) Teórico')
xlabel('tempo')
ylabel('deslocamento')
grid

figure

%%
s = tf('s');
Gsp = (114700000000/(s^2+856900*s+114700000000));
step(Gsp)

title('G(s) Prático')
xlabel('tempo')
ylabel('deslocamento')
grid

