#include <stdio.h>
#include <stdlib.h>
/*
*/
int main (void)
{
    int Num,Maior,Menor;
    char Continuar;
    do
    {
        printf("\n______________________________________________________________________________\n");
        printf("Informe um Numero: ");
        scanf("%d",Num);
        system("cls");

        Maior = Menor = Num;

        while(Num != -999)
        {
            system("cls");
            printf("\n_____________________________________________________________________________\n");
            printf("Informe um Numero: ");
            scanf("%d",Num);

            if(Num > Maior)
            {
                Maior = Num;
            }
            else if(Num < Menor)
            {
                Menor = Num;
            }

        }
        if(Maior != -999)
        {
            printf("\nO Maior Numero informado %c: %d",130,Maior);
            printf("\nO Menor Numero informado %c: %d",130,Menor);
        }

        printf("\n_________________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');

}
