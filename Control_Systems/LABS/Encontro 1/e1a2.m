A = [0 1 0 0 ; 3.22 1 -2.22 0 ; 0 0 0 1 ; 1.11 0 -1.61 0];
B = [0; 0; 0; 0.5];
C = [0 0 1 0];
D = 0;

X2 = ss(A,B,C,D);
figure (2)
step(0.1*X2)
grid; hold on;
title('Modelo no espaço de estados');