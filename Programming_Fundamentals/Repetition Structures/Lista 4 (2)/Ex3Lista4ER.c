#include <stdio.h>
#include <stdlib.h>

/*
Elaborar um programa que efetue a leitura de valores positivos inteiros até que um valor negativo
seja informado. Ao final devem ser apresentados o maior e o menor valor informados pelo usuário.
 O valor negativo, a condição de saída, não deve ser considerado nas comparações para localizar o
  maior e o menor.
*/
int main (void)
{
    int Num,Maior,Menor;
    char Continuar;
    do
    {
        printf("\n_____________________________________________________________________________\n");
        printf("Informe um Valor: ");
        scanf("%d",&Num);

        Maior = Menor = Num;

        do
        {
            system("cls");
            printf("\n_____________________________________________________________________________\n");
            printf("Informe um Valor: ");
            scanf("%d",&Num);

            if(Num > 0)
            {
                if(Num > Maior)
                {
                    Maior = Num;
                }
                else if (Num < Menor)
                {
                    Menor = Num;
                }
            }

        }while(Num > 0);


        printf("\nO Maior Valor e: %d ",Maior);
        printf("\nO Menor Valor e: %d ",Menor);

        printf("\n______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
