#include <stdio.h>
#include <stdlib.h>
/*
Faça um programa que imprima os 'n' (indicado pelo usuário) primeiros números pares.
Mostrar cinco números por linha.
Por exemplo, se o usuário informar 10, mostrar:
0    2    4    6     8 //primeira linha com cinco números
10 12  14  16  18 // segunda linha com cinco números.
*/
int main (void)
{
    //repetir o processamento enquanto a quantidade de numeros pares mostrados é menor que aqunatidade informada pelo usuario.
    int Qtparesm=0;
    int Pares,Cont=0;

    printf("Informe a quantidade de pares: ");
    scanf("%d",&Pares);

    do
    {
        if (Cont % 2 == 0)
        {
            printf("%d\t",Cont);
            Qtparesm++;
            if(Qtparesm % 5 ==0)
            {
                printf("\n");
            }
        }
        Cont++;
    }
    while(Qtparesm < Pares);
    printf("\n");
    system("pause");
}
