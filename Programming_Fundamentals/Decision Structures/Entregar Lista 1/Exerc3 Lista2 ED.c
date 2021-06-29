#include <stdio.h>
#include <stdlib.h>
/*
Ler três valores inteiros e colocá-los em ordem crescente.
*/

int main (void)
{
    int Num1,Num2,Num3;
    int Menor,Maior,Meio;

    printf("Informe o primeiro numero: ");
    scanf("%d",&Num1);
    printf("Informe o segundo numero: ");
    scanf("%d",&Num2);
    printf("Informe o terceiro numero: ");
    scanf("%d",&Num3);

    //menor
    if(Num1 <= Num2 && Num1 <= Num3)
    {
        Menor = Num1;
    }
    else if (Num2 <= Num3)
    {
        Menor = Num2;
    }
    else
    {
        Menor = Num3;
    }

    //maior
    if(Num1 >= Num2 && Num1 >= Num3)
    {
        Maior = Num1;
    }
    else if (Num2 >= Num3)
    {
        Maior = Num2;
    }
    else
    {
        Maior = Num3;
    }

    //meio
    if((Num1>=Num2&&Num1<=Num3)||(Num1<=Num2&&Num1>=Num3))
    {
        Meio = Num1;
    }
    else if((Num2>=Num1&&Num2<=Num3)||(Num2<=Num1&&Num2>=Num3))
    {
        Meio = Num2;
    }
    else
    {
        Meio = Num3;
    }
    printf("Numeros ordenados: %d, %d, %d\n",Menor,Meio,Maior);

    system("pause");
}
