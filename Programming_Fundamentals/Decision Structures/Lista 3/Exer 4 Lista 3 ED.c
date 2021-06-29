#include <stdio.h>
#include <stdlib.h>
/*
Elabore um programa que leia o dia e o mês de nascimento de uma pessoa e determine o seu signo
conforme a tabela a seguir:

Intervalo
Signo
de 22/12 até 20/1
Capricórnio
de 21/1 até 19/2
Aquário
de 20/2 até 20/3
Peixes
de 21/3 até 20/4
Áries
de 21/4 até 20/5
Touro
de 21/5 até 20/6
Gêmeos
de 21/6 até 21/7
Câncer
de 22/7 até 22/8
Leão
de 23/8 até 22/9
Virgem
de 23/9 até 22/10
Libra
de 23/10 até 21/11
Escorpião
de 22/11 até 21/12
Sagitário
Se informada uma data que não corresponda aos intervalos indicados, informar que a data está inválida.
*/
int main (void)
{
    int Dia,Mes;

    printf("Informe sua data de nascimento: ");
    scanf("%d/%d/",&Dia,&Mes);

    if ((Dia >=22 && Mes==12) || (Dia <=20 && Mes ==01))
    {
        printf("Signo = Capricornio\n");
    }
    else if ((Dia >=21 && Mes==01) || (Dia <=19 && Mes ==02))
    {
        printf("Signo = Aquario\n");
    }
    else if ((Dia >=20 && Mes==02) || (Dia <=20 && Mes ==03))
    {
        printf("Signo = Peixes\n");
    }
    else if ((Dia >=21 && Mes==03) || (Dia <=20 && Mes ==04))
    {
        printf("Signo = Aries\n");
    }
    else if ((Dia >=21 && Mes==04) || (Dia <=20 && Mes ==05))
    {
        printf("Signo = Touro\n");
    }
    else if ((Dia >=21 && Mes==05) || (Dia <=20 && Mes ==06))
    {
        printf("Signo = Gemeos\n");
    }
    else if ((Dia >=21 && Mes==06) || (Dia <=21 && Mes ==07))
    {
        printf("Signo = Cancer\n");
    }
    else if ((Dia >=22 && Mes==07) || (Dia <=22 && Mes ==8))
    {
        printf("Signo = Leao\n");
    }
    else if ((Dia >=23 && Mes==8) || (Dia <=22 && Mes ==9))
    {
        printf("Signo = Virgem\n");
    }
    else if ((Dia >=23 && Mes==9) || (Dia <=22 && Mes ==10))
    {
        printf("Signo = Libra\n");
    }
    else if ((Dia >=23 && Mes==10) || (Dia <=21 && Mes ==11))
    {
        printf("Signo = Escorpiao\n");
    }
    else if ((Dia >=22 && Mes==11) || (Dia <=21 && Mes ==12))
    {
        printf("Signo = Sagitario\n");
    }
    else if (Mes > 12 || Dia > 30)
    {
        printf("Data Invalida\n");
    }
    system("pause");
}
