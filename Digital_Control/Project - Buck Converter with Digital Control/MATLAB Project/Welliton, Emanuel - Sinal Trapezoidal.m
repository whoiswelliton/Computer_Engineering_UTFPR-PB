clear all;
clc;
close all;

fs=10000; %freq de amostragem
T0=40e-3; %periodo fundamental
f0=1/T0; %freq fundamental
NP=fs/f0; %qnt de pontos por amostra

Vmin=6;
Vmax=18;
Vdif=Vmax-Vmin;

v = zeros(1,NP);
for k=1:NP
    if(k>0 && k<=50)
        v(k) = Vdif;
    end
    if(k>50 && k<=60)
        v(k) = v(k-1) + (Vmin/10);
    end
    if(k>60 && k<=150)
        v(k) = Vmax;
    end
    if(k>150 && k<=160)
        v(k) = v(k-1) - (Vmin/10);
    end
    if(k>160 && k<=250)
        v(k) = Vdif;
    end
    if(k>250 && k<=260)
        v(k) = v(k-1) - (Vmin/10);
    end
    if(k>260 && k<=350)
        v(k) = Vmin;
    end
    if(k>350 && k<=360)
        v(k) = v(k-1) + (Vmin/10);
    end
    if(k>360 && k<=400)
        v(k) = Vdif;
    end
end
ylim([0 20])
plot(v)