#include <stdio.h>
#include <stdlib.h>
/*
Escreva um algoritmo que leia um número e verifique se ele se encontra fora do intervalo entre 5 e 20.
Mostre uma mensagem conforme o caso.
*/
int main (void)
{
    int Num;

    printf("Informe um numero: ");
    scanf("%d",&Num);

    if (Num <5 || Num > 20)
    {
        printf("%d esta fora do intervalo\n",Num);
    }
    else
    {
        printf("%d esta no intervalo 5 e 20\n",Num);
    }

    system("pause");
}
