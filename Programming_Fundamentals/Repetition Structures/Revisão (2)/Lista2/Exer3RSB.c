#include <stdio.h>
#include <stdlib.h>
/*
Escreva um programa que realize a multiplição de dois números informados pelo usuário
através de somas
sucessivas, ou seja, para fazer A X B basta somar o valor da variável A, B vezes.
*/
int main (void)
{
    int A,B,Soma=0;

    printf("Informe um numero: ");
    scanf("%d",&A);
    printf("Informe outro numero: ");
    scanf("%d",&B);

    do
    {

        Soma=Soma+B;
        A--;
    }while(A >= 1);

    printf(" A x B = %d\n ",Soma);

    system("pause");
}
