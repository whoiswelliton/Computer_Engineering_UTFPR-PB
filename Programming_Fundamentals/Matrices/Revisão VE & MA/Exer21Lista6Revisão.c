#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    char Continuar,String[3][50];
    int i,j,Indice;

    do
    {
        i=j=Indice=0;

        for(i=0;i<3;i++)
        {
            printf("Informe uma string: ");
            fflush(stdin);
            gets(String[i]);

                while(String[i][j] != '\0')
                {
                    if(String[i][j] != ' ' || (String[i][j] != '  ' && String[i][j+1] != ' ' ))
                    {
                        String[i][Indice] = String[i][j];
                        Indice++;
                    }
                    j++;
                }
            String[i][Indice]='\0';
        }
        for(i=0;i<3;i++)
        {
            printf("%s\n",String[i]);
        }



        printf("Para Executar Novamente(S/s para Sim) : ");
        fflush(stdin);
        scanf("%c",&Continuar);
    }while(Continuar == 'S' || Continuar == 's');
}
