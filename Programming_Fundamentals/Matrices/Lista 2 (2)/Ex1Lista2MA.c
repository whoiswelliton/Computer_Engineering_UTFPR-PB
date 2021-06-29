#include <stdio.h>
#include <stdlib.h>

/*
Gerar uma matriz de 5x5 com números aleatórios entre 10 e 100, mostrar essa matriz. Somar a diagonal
principal e a secundária. Mostrar a matriz e essas somas.
*/
int main (void)
{
    int Num[5][5],Soma,Soma2,i,j;
    char Continuar;
    do
    {
        Soma=0,Soma2=0;
        system("cls");
        printf("\n____________________________________________________________________________\n");
        printf("MATRIZ:\n");


        for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
            {
                Num[i][j] = rand() % (91+10);
                printf(" %d ",Num[i][j]);

                if(i == j)
                {
                    Soma = Soma + Num[i][j];
                }
                else if(i == 4-j)
                {
                    Soma2 = Soma + Num[i][j];
                }

            }
            printf("\n");
        }
        printf("\n______________________________________________________________________________\n");

        printf("\nSoma da diagonal principal: %d",Soma);
        printf("\nSoma da diagonal secundaria: %d",Soma2);


        printf("\n______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
