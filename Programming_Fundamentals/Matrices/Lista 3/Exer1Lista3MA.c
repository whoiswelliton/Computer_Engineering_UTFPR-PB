#include <stdio.h>
#include <stdlib.h>

/*
*/
int main (void)
{
    char Continuar,Matriz[5][25],C;
    int i,Qto;

    do
    {
        system("cls");
        Qto=0;

        printf("Informe um Caractere: ");
        scanf("%c",&C);

        for(i=0;i<5;i++)
        {
            printf("\nInforme um Nome: ");
            fflush(stdin);
            gets(Matriz[0]);

            if(Matriz[0][0] == C)
            {
                Qto++;
            }
        }




        printf("\n\nTem %d Nomes que comecam com o caractere Desejado\n\n",Qto);

        printf("_______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
