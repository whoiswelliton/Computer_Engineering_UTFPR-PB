#include <stdio.h>
#include <stdlib.h>

/*
Construa um algoritmo que, dado um conjunto de valores inteiros e positivos, determine qual o menor e o maior
valor do conjunto. O final do conjunto de valores é conhecido através do valor -1, que não deve ser considerado.
*/
int main (void)
{
    int Num,Maior,Menor;
    char Continuar;
    do
    {
        system("cls");
        printf("\n_______________________________________________________________________________\n");
        printf("Informe um Valor: ");
        scanf("%d",&Num);

        Maior = Num;
        Menor = Num;
        do
        {
            system("cls");
            printf("\n_______________________________________________________________________________\n");
            printf("Informe um Valor: ");
            scanf("%d",&Num);

            if(Num > Maior)
            {
                Maior = Num;
            }
            if(Num < Menor)
            {
                Menor = Num;
            }

        }while(Num != -1);

        printf("\nO maior numero do intervalo: %d",Maior);
        printf("\nO menor numero do intervalo: %d",Menor);

        printf("\n______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
