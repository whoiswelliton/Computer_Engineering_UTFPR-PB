#include <stdio.h>
#include <stdlib.h>
/*
4) Construa um algoritmo que, dado um conjunto de valores inteiros e positivos, determine qual o menor e o maior
valor do conjunto. O final do conjunto de valores é conhecido através do valor -1, que não deve ser considerado.
*/
int main (void)
{
    char Continuar;
    int Num,Maior,Menor;

    printf("Informe um valor inteiro e positivo: ");
    scanf("%d",&Num);
    Maior = Num;
    Menor = Num;

    do
    {
        system("cls");
        do
        {
            printf("Informe um valor inteiro e positivo: ");
            scanf("%d",&Num);
            if (Num > 0)
            {
                if (Num < Menor)
                {
                    Menor = Num;
                }
                else if (Num > Maior)
                {
                    Maior = Num;
                }
            }
        }while(Num != -1);

        printf("O Maior numero do conjunto e: %d\n",Maior);
        printf("O Menor numero do conjunto e: %d\n",Menor);

        printf("\nExecutar novamente (S/s para Sim): ");
        getchar();
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');

    system("pause");
}
