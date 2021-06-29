#include <stdio.h>
#include <stdlib.h>


/*
Faça um programa que imprima os 'n' (indicado pelo usuário) primeiros números pares.
Mostrar cinco números por linha.
Por exemplo, se o usuário informar 10, mostrar:
0    2    4    6     8 //primeira linha com cinco números
10 12  14  16  18 // segunda linha com cinco números.
*/
int main (void)
{

    int N,Cont,Qtd=0;
    char Continuar;
    do
    {
        system("cls");
        printf("\n_____________________________________________________________________________\n");
        printf("Quantos numero pares deseja ver: ");
        scanf("%d",&N);

        for(Cont=0;Cont<=N*2;Cont++)
        {
            if(Cont % 2 == 0)
            {
                printf("%d \t",Cont);
                Qtd++;

                if(Qtd % 5 == 0)
                {
                    printf("\n");
                }
            }
        }


        printf("\n______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
