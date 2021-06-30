clc;
close all;

s=tf('s')

%% EXERCÍCIO 1

Gs=0.9091/(s+1.8182);
R=6*Gs;
step(R);
grid;


%% EXERCÍCIO 2 - MALHA ABERTA

Gs1=(4)*3/(2*s + 4);

step(1*Gs1);
legend('M.A.');
grid;

%% EXERCÍCIO 2 - MALHA FECHADA

Gs2=(4)*3/(2*s + 4);
Ts = feedback(Gs2,1) 
step(Ts,Gs2)
legend('M.F.');
grid;

%% EXERCÍCIO 3

Gs3= (0.4283)/(s + 0.571);
opt = stepDataOptions('StepAmplitude',40);
figure(13)

step(Gs3,opt);
grid;
