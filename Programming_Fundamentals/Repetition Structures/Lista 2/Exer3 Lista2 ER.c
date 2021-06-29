#include <stdio.h>
#include <stdlib.h>
/*
Calcular e mostrar o fatorial de um número informado pelo usuário.
*/
int main (void)
{
    double Num1,Cont,Fat=1;

    printf("Inforem um numero: ");
    scanf("%lf",&Num1);

    for (Cont=Num1;Cont>0;Cont--)
    {
        Fat=Fat*Cont;
    }
    printf("O Fatorial do numero e: %lf\n",Fat);

    system("pause");
}
