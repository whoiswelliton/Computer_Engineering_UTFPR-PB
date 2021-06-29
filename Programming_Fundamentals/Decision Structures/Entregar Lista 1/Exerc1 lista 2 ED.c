#include <stdio.h>
#include <stdlib.h>
/*
Ler três valores inteiros, encontrar e mostrar o menor deles.
*/
int main (void)
{
    int Num1,Num2,Num3;

    printf("Informe o primeiro numero: ");
    scanf("%d",&Num1);
    printf("Informe o segundo numero: ");
    scanf("%d",&Num2);
    printf("Informe o terceiro numero: ");
    scanf("%d",&Num3);

    if (Num1 < Num2 && Num3 > Num1)
    {
        printf("O Primeiro numero e o menor: %d\n",Num1);
    }
    else if (Num2 < Num1 && Num2 < Num3)
    {
        printf("O Segundo numero e o menor: %d\n",Num2);
    }
    else if (Num3 < Num1 && Num3 < Num2)
    {
        printf("O Terceiro numero e o menor: %d\n",Num3);
    }

    system("pause");
}
