#include <stdio.h>
#include <stdlib.h>

/*
*/
int main (void)
{
    char Continuar,String[50];
    int i,Espaco,Indice,Vet[50];

    do
    {
        system("cls");


        printf("Informe um texto: ");
        fflush(stdin);
        gets(String);

        i=Indice=0;

        while(String[i] != '\0')
        {
            if(String[i] == ' ')
            {
                Espaco=0;
                while(String[i] == ' ')
                {
                    Espaco++;
                    i++;
                }
                Vet[Indice] = Espaco;
                Indice++;
            }
             i++;
        }


        for(i=0;i<Indice;i++)
        {
            printf(" %d \t",Vet[i]);
        }



        printf("________________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');

}
