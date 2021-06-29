#include <stdio.h>
#include <stdlib.h>
#include "Pause.h"

/*
Ler dez números inteiros. Validar as entradas para que sejam informados valores positivos.
E em listagens separadas:
a) mostrar os pares;
b) mostrar os divisíveis por 3 e por 5.
c) mostrar os valores menores que 10 e os maiores que 100.
d) mostrar os valores maiores que 10 e menores que 100.
O programa permanecerá em execução até que seja escolhida a opção sair ou alguma equivalente.
*/
int main (void)
{
    char Continuar;
    int Vet[10];//armaznar 10 valores  inteiros
    int i;//indice do vetor


    do
    {
        system("cls");

        for(i=0;i<10;i++)//percentual o vetor pelo indice
        {
            do
            {
                printf("Informe um valor positivo: ");
                scanf("%d",&Vet[i]);

            }while(Vet[i] < 0);
        }
        printf("______________________________________________________________________________");
        printf("\nPares: \n");
        for(i=0;i<10;i++)
        {
            if(Vet[i] % 2 == 0)
            {
                printf("%d\t",Vet[i]);
            }
        }
        printf("_______________________________________________________________________________");
        printf("\nDivisiveis por 3 e por 5: \n");
        for(i=0;i<10;i++)
        {
            if(Vet[i] % 3 == 0 && Vet[i] % 5 == 0)
            {
                printf("%d\t",Vet[i]);
            }
        }
        printf("_______________________________________________________________________________");
        printf("\nMenores que 10 e maiores que 100: \n");
        for(i=0;i<10;i++)
        {
            if(Vet[i] < 10 || Vet[i] > 100)
            {
                printf("%d\t",Vet[i]);
            }
        }
        printf("_______________________________________________________________________________");
        printf("\nMenores que 100 e maiores que 10: \n");
        for(i=0;i<10;i++)
        {
            if(Vet[i] < 100 && Vet[i] > 10)
            {
                printf("%d\t",Vet[i]);
            }
        }
        printf("\n");
        printf("_______________________________________________________________________________");
        printf("\n                    Executar Novamente (S/s para Sim):");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
    Pause();
}
