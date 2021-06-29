#include <stdio.h>
#include <stdlib.h>

/*
Apresentar os números entre 10 e 0, ou seja, em ordem decrescente.
*/
int main (void)
{
    int Cont;
    char Continuar;
    do
    {
        system("cls");
        printf("\n________________________________________________________________________________\n");

        for(Cont=10;Cont>0;Cont--)
        {
            printf("%d\t",Cont);
        }

        printf("\n________________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
