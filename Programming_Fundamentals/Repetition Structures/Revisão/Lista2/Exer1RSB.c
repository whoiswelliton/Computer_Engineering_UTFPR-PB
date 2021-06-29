#include <stdio.h>
#include <stdlib.h>
/*
Escrever um programa, que leia valores inteiros até ser lido o valor -1. Quando isso acontecer o programa
deverá escrever a soma e a média dos valores lidos.
*/
int main (void)
{
    int Num,Qtnum=0,Soma=0;
    float Media;

    do
    {
        printf("Informe um numero: ");
        scanf("%d",&Num);
        Qtnum++;
        fflush(stdin);
        Soma=Soma+Num;
    }while(Num != -1);

    Media=(float)Soma/Qtnum;

    printf("Soma: %d  - Media: %.2f \n",Soma,Media);
    system("pause");
}
