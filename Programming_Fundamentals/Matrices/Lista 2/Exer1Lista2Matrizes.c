#include <stdio.h>
#include <stdlib.h>

/*
*/
int main (void)
{
    char Continuar;
    int Numeros[5][5],i,j,SomaP,SomaS,Cont,Cont2;

    do
    {
        SomaP=0;
        SomaS=0;
        system("cls");
        printf("\n_______________________________________________________________________________\n\n");
        printf("\nMatriz:\n\n");
        for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
            {
                Numeros[i][j] = rand() % (91 + 10);
                printf(" %d ",Numeros[i][j]);
                if(i == j)
                {
                    SomaP+=Numeros[i][j];
                }
                else if(i == 5-i-1)
                {
                    SomaS+=Numeros[i][j];
                }

            }
            printf("\n");
        }



        printf("\nSoma da diagonal principal = %d \n",SomaP);
        printf("\nSoma da diagonal secundaria = %d \n",SomaS);

        printf("\n_______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
