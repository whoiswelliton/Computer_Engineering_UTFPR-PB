#include <stdio.h>
#include <stdlib.h>
#include "Vetores.h"
#include "Funcoes.h"
/*

*/
int main (void)
{
    char Caracteres[100],Continuar;
    do
    {

        system("cls");
        printf("\n______________________________________________________________________________\n");
        printf("Caracteres:\n");

        GerarVetorChar(Caracteres,100);
        MostrarVetorChar(Caracteres);

        printf("\n______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}




