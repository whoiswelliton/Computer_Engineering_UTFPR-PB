#include <stdio.h>
#include <stdlib.h>

/*
Apresentar os números primos entre 1 e 100.
*/
int main (void)
{
    int Cont,Cont2;
    char Continuar;
    do
    {
        system("cls");
        printf("\n_______________________________________________________________________________\n");

        printf("\nPrimos entre 1 e 100:\n");
        for(Cont=1;Cont<=100;Cont++)
        {
            for(Cont2=2;Cont2<=Cont/2;Cont2++)
            {
                if(Cont2 % Cont == 0)
                {
                    printf("%d\n",Cont);
                }
            }

        }

        printf("\n______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
