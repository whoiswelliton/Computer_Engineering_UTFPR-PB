#include <stdio.h>
#include <stdlib.h>
#include "Pause.h"
#include "Vetores1.h"

/*
*/
int main (void)
{
    int Soma,i,Cont,Tamanho,LI,LS;
    char Continuar;
    do
    {
        system("cls");
        Soma=0;
        Tamanho=5;
        LI = 10;
        LS = 20;
        int Vetor[5];

        VetorLim (Vetor,Tamanho,LI,LS);

        printf("____________________________[VETORES E SEUS DIVISORES]__________________________\n");


        for(i=0;i<5;i++)
        {
            Soma=0;
            printf("%d = ",Vetor[i]);
            for(Cont=1;Cont<=Vetor[i];Cont++)
            {
                if(Cont % 2 == 0)
                {
                    printf("%d, ",Cont);
                    Soma=Soma+Vetor[i];
                }
            }
            printf(" --> Soma = %d\n",Soma);
        }

        printf("________________________________________________________________________________\n");
        printf("\nExecutar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
    Pause();
}
