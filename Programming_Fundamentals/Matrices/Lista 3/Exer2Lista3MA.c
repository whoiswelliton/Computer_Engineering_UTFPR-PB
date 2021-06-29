#include <stdio.h>
#include <stdlib.h>

/*
*/
int main (void)
{
    char Continuar,Matriz[10][31],Nomes[10][31];
    int i,j,Indice;
    do
    {
        system("cls");
        i=0;
        j=0;

        for(i=0;i<10;i++)
        {
            printf("Informe um nome: ");
            fflush(stdin);
            gets(Matriz[i]);
        }

        for(i=0;i<10;i++)
        {
            j=Indice=0;
            while(Matriz[i][j] != '\0')
            {
                if(Matriz[i][j] == 'a' || Matriz[i][j] == 'e' || Matriz[i][j] == 'i' || Matriz[i][j] == 'o' || Matriz[i][j] == 'u')
                {
                    Nomes[i][Indice] = Matriz[i][j];
                    Indice++;
                }
                j++;
            }
            Nomes[i][Indice] = '\0';

        }
        for(i=0;i<10;i++)
        {
            printf(" %s \n",Nomes[i]);

        }



        printf("_______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
