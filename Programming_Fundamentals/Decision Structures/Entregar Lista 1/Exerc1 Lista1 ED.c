#include <stdio.h>
/*
) Ler um número e apresentar o seu módulo (número sem sinal), isto é, se o número é negativo apresentá-lo como positivo.
*/

int main (void)

{
    int Num1;
    printf("Informe o numero desejado: ");
    scanf("%d",&Num1);

    if (Num1 < 0)
    {
    Num1 = Num1 * -1;
    }
    printf("%d em módulo: ",Num1);

}

