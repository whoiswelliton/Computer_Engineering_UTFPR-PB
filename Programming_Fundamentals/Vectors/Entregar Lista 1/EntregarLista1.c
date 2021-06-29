#include <stdio.h>
#include <stdlib.h>
#include <Pause.h>

/*
*/
int main (void)
{
    char Continuar,Opcao;
    do
    {
        system("cls");
	printf("Opcao: ");




        printf("\nExecutar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
    Pause();
}
