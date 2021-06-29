#include <stdio.h>
#include <stdlib.h>
#include "Pause.h"
#include "Vetores1.h"

/*
*/
int main (void)
{
    char Continuar;
    int Tam,QtdeLinhas=0,Quantidades[3],i;
    do
    {
        system("cls");
            //inicializar o vetor com zeros
            for(i=0;i<3;i++)
            {
                Quantidades[i]=0;
            }
        do
        {
            printf("Inforem o tamanho do vetor : ");
            scanf("%d",&Tam);

        }while(Tam < 0);
        do
        {
            printf("Inforem a quantidade de caracteres por linha : ");
            scanf("%d",&QtdeLinhas);

        }while(QtdeLinhas < 0);

        char String[Tam];

        GerarVetorChar (String,Tam);

        MostrarVetorAlfa(String,QtdeLinhas);

        i=0;
        while(String[i] != '\0')
        {
            if(String[i]=='a' || String[i]=='e' || String[i]=='i' || String[i]=='o' || String[i]=='u')
            {
                Quantidades[0] = Quantidades[0] + 1;
            }
            else if(String[i] >= 48 && String[i] <= 57)
            {
                Quantidades[1]++;
            }
            else
            {
                Quantidades[2]++;
            }
            i++;
        }
        printf("\nQuantidade de vogais: %d",Quantidades[0]);
        printf("\nQuantidade de digitos: %d",Quantidades[1]);
        printf("\nQuantidade de outros caracteres: %d\n",Quantidades[2]);

        printf("\nExecutar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
    Pause();
}
