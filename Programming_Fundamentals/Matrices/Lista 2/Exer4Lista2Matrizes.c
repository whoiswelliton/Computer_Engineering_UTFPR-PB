#include <stdio.h>
#include <stdlib.h>

/*
*/
int main (void)
{
    int People[5][10],i,j,indicei,indicej,Maior,Soma,Qto;
    float Media;
    char Continuar;
    do
    {
        system("cls");
        Maior=0;
        indicei=0;
        indicej=0;
        Qto=0;
        Soma=0;

        for(i=0;i<5;i++)
        {
            for(j=0;j<10;j++)
            {
                People[i][j] = rand();
                printf("%8d",People[i][j]);

                if(People[i][j] > Maior)
                {
                    Maior = People[i][j];

                    indicei= i+1;
                    indicej= j+1;
                }
                Qto++;
                Soma+=People[i][j];
            }
        }

        if(Qto > 0)
        {
            Media=(float)Soma/Qto;
            printf("\nMedia das Populacoes: %.2f",Media);
        }

        printf("\n");
        printf("\nMaior Populacao: %d",Maior);




        printf("\n\n________________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
