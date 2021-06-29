#include <stdio.h>
#include <stdlib.h>

/*

*/
int main (void)
{
    char Continuar;
    int Largura,Altura,Comprimento,Total;

    do
    {
        system("cls");
        printf("\n________________________________________________________________________________\n");



        printf("\n_______________________________________________________________________________\n\n");
        printf("\n                          Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
