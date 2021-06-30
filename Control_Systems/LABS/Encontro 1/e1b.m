%Modelo linearizado no espaço de estados
  A = [0 1 0 0 ; 3.22 1 -2.22 0 ; 0 0 0 1 ; 1.11 0 -1.61 0];
  B = [0; 0; 0; 0.5];
  C = [0 0 1 0];
  D = 0;

  X2 = ss(A,B,C,D);
  figure (3)
  step(0.1*X2)
  grid; hold on;
  title('Modelo no espaço de estados');

 %Modelo no dominio da frequencia
   num = [1 1 3.22];
   den = [2 2 9.66 3.22 5.44];

   TF = tf(num,den);
   figure (4);
   step (0.1*TF);
   grid; hold on;
   title('Modelo no dominio da frequencia');