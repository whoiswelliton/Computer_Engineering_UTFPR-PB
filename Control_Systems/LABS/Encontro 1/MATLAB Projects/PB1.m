%Modelo linearizado no espaço de estados
  A = [0 1 0 0 0; -1 -2 0 1 0; 0 0 0 1 0; 0 1 -2 -1 2; 0 0 2 0 -3];
  B = [0; 0; 0; 1; 0];
  C = [0 0 1 0 0];
  D = [0];

  X2 = ss(A,B,C,D);
  figure (3)
  step(4.5*X2)
  grid; hold on;
  title('Modelo no espaço de estados');

 %Modelo no dominio da frequencia
   num = [1 5 7 3];
   den = [1 6 13 13 9 2];

   TF = tf(num,den);
   figure (4);
   step (4.5*TF);
   grid; hold on;
   title('Modelo no dominio da frequencia');
