#include <stdio.h>
#include <stdlib.h>

/*
Ler o nome de 5 pessoas e armazená-los em uma matriz. Mostrar os nomes armazenados que iniciam com vogal
 e em seguida os nomes nos índices ímpares.
*/
int main (void)
{
    char Nomes[5][20];
    int i,j;
    char Continuar;

    do
    {
        system("cls");

        for(i=0;i<5;i++)
        {
            printf("Informe um nome: ");
            fflush(stdin);
            gets(Nomes[i]);
        }

        printf("\nNomes indice impar:\n");

        for(i=1;i<5;i=i+2)
        {
            printf("Nome[%d] = %s\n",i,Nomes[i]);
        }

        printf("\nNomes indice par;\n");

        for(i=1;i<5;i=i+2)
        {
            j=0;
            printf("Nome[%d] = ",i);

            while(Nomes[i][j] != '\0')
            {
                printf("%c",Nomes[i][j]);
                j++;
            }
            printf("\n");
        }


        printf("\n______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}

