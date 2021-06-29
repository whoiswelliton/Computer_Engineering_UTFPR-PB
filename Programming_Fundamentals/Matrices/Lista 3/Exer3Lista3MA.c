#include <stdio.h>
#include <stdlib.h>

/*
*/
int main (void)
{
    char Continuar,Matriz[10][15];
    int i,j;

    do
    {
        system("cls");

        for(i=0;i<10;i++)
        {
            printf("Informe uma Cidade: ");
            fflush(stdin);
            gets(Matriz[i]);
        }

        for(i=0;i<10;i++)
        {
            if(Matriz[i][0] == 'a' || Matriz[i][0] == 'e' || Matriz[i][0] == 'i' || Matriz[i][0] == 'o' || Matriz[i][0] == 'u')
            {
                printf(" %s \n",Matriz[i]);
            }
        }



        printf("_______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
