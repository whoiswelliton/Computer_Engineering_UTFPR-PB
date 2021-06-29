#include <stdio.h>
#include <stdlib.h>
#include "Vetores.h"

int main (void)
{
    char Continuar;
    int i,Vet[10];

    do
    {

        GerarVetor(Vet,10,20);
        MostrarVetor(Vet,10);

        for(i=10;i>=0;i--)
        {
             if(i >= 5 && i < 10)
             {
                 printf("%4d\t",Vet[i]);
             }
             else if(i < 5)
             {
                 printf("%4d\t",Vet[i]);
             }
        }

        printf("\n\nPara Executar Novamente(S/s para Sim) : ");
        fflush(stdin);
        scanf("%c",&Continuar);
    }while(Continuar == 'S' || Continuar == 's');
}
