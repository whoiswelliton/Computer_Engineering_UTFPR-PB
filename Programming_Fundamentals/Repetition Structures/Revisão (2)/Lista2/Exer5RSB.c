#include <stdio.h>
#include <stdlib.h>
/*
Construa um programa que, dado um conjunto de valores inteiros e positivos,
determine qual o menor e o maior valor do conjunto. O final do conjunto de valores
 é conhecido através do valor –1, que não deve ser considerado.
*/
int main (void)
{
    int Num,Maior,Menor;

    printf("Informe um valor: ");
    scanf("%d",&Num);
    Maior=Menor=Num;

    do
    {
        printf("Informe um valor: ");
        scanf("%d",&Num);
        if(Num > 0)
        {
            if(Num < Menor)
            {
                Menor = Num;
            }
            else if (Num > Maior)
            {
                Maior = Num;
            }
        }

    }while(Num != -1);

    if(Menor != -1)
    {
        printf("O maior valor : %d \n",Maior);
        printf("O menor valor : %d \n",Menor);
    }
    system("pause");
}
