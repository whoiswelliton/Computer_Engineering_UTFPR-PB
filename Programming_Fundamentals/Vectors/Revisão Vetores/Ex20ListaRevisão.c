#include <stdio.h>
#include <stdlib.h>

/*
*/
int main (void)
{
    int i;
    char Continuar,String[50];
    do
    {
        system("cls");

        i=0;

        printf("\n\nInforme um String: ");
        fflush(stdin);
        gets(String);

        while(String[i] != '\0')
        {
            if(String[i] == ' ')
            {
                i++;
            }
            else if(String[i] != ' ')
            {
                printf("%c",String[i]);
            }
            else if (String[i-1] == ' ');
            {
                printf("%c",String[i]);
            }
            i++;
        }

        printf("\n______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
