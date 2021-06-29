#include <stdio.h>
/*
Escreva um algoritmo que leia um número e verifique se ele é maior, menor ou igual a 10.
*/
int main (void)
{
    int Num;
    printf("Informe um numero: ");
    scanf("%d",&Num);

    if (Num > 10)
    {
       printf("%d e maior que 10",Num);
    }
    else if (Num <10)
    {
       printf("%d e menor que 10",Num);
    }
    else
    {
       printf("%d e igual a 10",Num);
    }

}


