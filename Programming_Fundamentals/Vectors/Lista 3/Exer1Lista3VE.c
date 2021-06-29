#include <stdio.h>
#include <stdlib.h>
#include "Pause.h"
#include "Vetores1.h"

/*
1) Fazer um programa para:
Gerar aleatoriamente um vetor com 11 elementos entre 10 e 20.  Em seguida percorrer o vetor
e mostrar a quantidade de divisores de cada um dos valores armazenados. Utilizar uma função
para mostrar os divisores e contar a quantidade. A função mostra os divisores e devolve a
quantidade de divisores, isto é, o seu retorno é essa quantidade. Ao final mostrar o número
 que possui a maior quantidade de divisores e essa quantidade.
*/
int main (void)
{
    int  Qtdiv=0,i,Cont,Soma=0,Tamanho,LI,LS;
    char Continuar;
    do
    {
        system("cls");
        Tamanho=11;
        LI = 10;
        LS = 20;
        int Vetor[11];

        VetorLim (Vetor,Tamanho,LI,LS);

        printf("____________________________[VETORES E SEUS DIVISORES]__________________________\n");


        for(i=0;i<11;i++)
        {
            Qtdiv=0;
            printf("%d = ",Vetor[i]);
            for(Cont=1;Cont<=Vetor[i];Cont++)
            {
                if(Vetor[i] % Cont == 0)
                {
                    printf("%d, ",Cont);
                    Qtdiv++;
                }
            }
            printf("  Possui %d Divisores\n",Qtdiv);
        }

        printf("________________________________________________________________________________\n");
        printf("\nExecutar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
    Pause();
}
