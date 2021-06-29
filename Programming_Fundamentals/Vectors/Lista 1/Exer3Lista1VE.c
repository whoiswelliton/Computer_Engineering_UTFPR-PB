#include <stdio.h>
#include <stdlib.h>
#include "Pause.h"

/*
*/
int main (void)
{
    char Continuar,Nome[100],Caractere;
    int Indice,i,Tam;
    do
    {
        i=0;
        Tam=0;
        system("cls");
        printf("\n Informe um string com até 99 caracteres: ");
        fflush(stdin);
        gets(Nome);//para ler uma string
        printf("\n Informe um caractere: ");
        fflush(stdin);
        scanf("%c",&Caractere);

        while(Nome[i] != '\0')
        {
            Tam++;
            i++;
        }

        printf("A string %s possui %d caracteres\n",Nome,Tam);

        while(Nome[i] != '\0')
        {
            if (Nome[i] == Caractere)
            {
                Indice = i;
            }
            i++;
            if (Indice != -1)
            {
                printf("A Ultima ocorrencia de %c %c no indice %d\n",Caractere,101,Indice);
            }

        }
        //
        i=0;
        while(Nome[i] != '\0')
        {
            if (Nome[i] == Caractere)
            {
                Indice = i;
                break;
            }
            i++;
            if (Indice != -1)
            {
                printf("A primeira ocorrencia de %c %c no indice %d\n",Caractere,101,Indice);
            }

        }

        printf("\nExecutar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
    Pause();
}
