#include <stdio.h>
#include <stdlib.h>

/*
Apresentar os números entre 20 e 35.
*/
int main (void)
{
    int Cont;
    char Continuar;

    do
    {
        system("cls");
        printf("\n________________________________________________________________________________\n");

        for(Cont=20;Cont<35;Cont++)
        {
            printf("%d\t",Cont);
        }

        printf("\n________________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
