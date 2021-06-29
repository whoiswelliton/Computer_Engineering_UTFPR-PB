#include <stdio.h>
#include <stdlib.h>

/*
*/
int main (void)
{

    char Continuar,Nomes[5][30];
    int i,j;
    do
    {

        system("cls");

        for(i=0;i<5;i++)
        {
                printf("\nInforme seu nome: ");
                fflush(stdin);
                gets(Nomes[i]);
        }
        printf("Nomes com indices impares:\n");
        for(i=0;i<5;i++)
        {
            if(i % 2 != 0)
            {
                printf("   %d = %s\n",i,Nomes[i]);
            }
        }

        printf("\nNomes nos indices pares: \n");
        for(i=0;i<5;i++)
        {
            if(i % 2 == 0)
            {
                j=0;
                while(Nomes[i][j] != '\0')
                {
                    printf("%c",Nomes[i][j]);
                    j++;
                }
                printf("\n\n");
            }
        }


        printf("_________________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');

}
