#include <stdio.h>
#include <stdlib.h>
/*
Escreva um programa que realize a multipli��o de dois n�meros informados pelo usu�rio atrav�s de somas
sucessivas, ou seja, para fazer A X B basta somar o valor da vari�vel A, B vezes.
*/
int main (void)
{
    int A,B,Soma;

    printf("Informe um numero: ");
    scanf("%d",&A);
    printf("Informe outro numero: ");
    scanf("%d",&B);

    do
    {
        Soma=A*B;
        B--;
    }while(B == 1);

    printf(" A x B = %d\n ",Soma);

    system("pause");
}
