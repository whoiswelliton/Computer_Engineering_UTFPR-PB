#include <stdio.h>
#include <stdlib.h>
#include "Pause.h"
#include "Vetores1.h"

/*
*/
int main (void)
{
    char Continuar;
    int Tam;
    int QtdeLinhas;

    do
    {
        system("cls");
        do
        {
            printf("Inforem o tamanho do vetor : ");
            scanf("%d",&Tam);
        }while(Tam < 0);
        do
        {
            printf("Inforem a quantidade de caracteres por linha : ");
            scanf("%d",&QtdeLinhas);
        }while(QtdeLinhas < 0);

        char String[Tam];//Vetor de caracteres com tam Caracteres
        GerarVetorAlfa(String,Tam);

        MostrarVetorAlfa (String,QtdeLinhas);

        printf("\nExecutar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
    Pause();
}
