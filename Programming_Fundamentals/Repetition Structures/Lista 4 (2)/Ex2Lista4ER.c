#include <stdio.h>
#include <stdlib.h>

/*
Elaborar um programa para apresentar todos os números divisíveis por 4 e menores que 200.
Apresentar os números com 8 valores por linha.
*/
int main (void)
{
    int Cont,Qtd=0;
    char Continuar;
    do
    {
        system("cls");
        printf("\n____________________________________________________________________________\n");

        for(Cont=0;Cont<=200;Cont++)
        {
            if(Cont % 4 == 0)
            {
                printf("%d\t",Cont);
                Qtd++;
                if(Qtd % 8 == 0)
                {
                    printf("\n");
                }
            }

        }

        printf("\n______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
