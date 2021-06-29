#include <stdio.h>
#include <stdlib.h>

/*
Apresentar os múltiplos de 5, entre 5 e 50.
*/
int main (void)
{
    int Cont;
    char Continuar;
    do
    {
        system("cls");
        printf("\n________________________________________________________________________________\n");

        for(Cont=5;Cont<50;Cont++)
        {
            if(Cont % 5 == 0)
            {
                printf("%d\t",Cont);
            }
        }


        printf("\n________________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
