#include <stdio.h>
#include <stdlib.h>
#include "Vetores.h"

int main (void)
{
    char Continuar,String[50];
    int i,j,Qto,Vet[50];

    do
    {
        i=Qto=0;

        printf("Informe uma string: ");
        fflush(stdin);
        gets(String[i]);

        while(String[i] != '\0')
        {
            if(String[i] == ' ')
            {
                Qto++;
            }

        }
        GerarVetor(Vet,Qto,Qto);
        MostrarVetor(Vet,Qto);


        printf("Para Executar Novamente(S/s para Sim) : ");
        fflush(stdin);
        scanf("%c",&Continuar);
    }while(Continuar == 'S' || Continuar == 's');
}


