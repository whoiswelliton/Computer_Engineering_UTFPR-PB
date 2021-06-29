#include <stdio.h>
#include <stdlib.h>

/*
*/
int main (void)
{
    char Continuar,Matriz[3][50];
    int i,j,Indice;

    do
    {
        system("cls");

        for(i=0;i<3;i++)
        {
            printf("Informe um nome:");
            fflush(stdin);
            gets(Matriz[i]);

            Indice=j=0;

            while (Matriz[i][j] != '\0')
            {
                if(Matriz[i][j] != ' ' ||  (Matriz[i][j] != '  ' && Matriz[i][j+1] != ' ' ))
                {
                    Matriz[i][Indice] = Matriz[i][j];
                    Indice++;
                }
                  j++;
            }


            Matriz[i][Indice]='\0';

        }
        for(i=0;i<3;i++)
        {
            printf("%s\n",Matriz[i]);
        }


        printf("\n\n________________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
