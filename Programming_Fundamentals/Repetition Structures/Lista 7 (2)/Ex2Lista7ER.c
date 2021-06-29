#include <stdio.h>
#include <stdlib.h>

/*
Escreva um programa que imprima todas as possibilidades de que no lançamento de dois dados a soma das faces
seja um valor informado pelo usuário. O usuário deve informar um valor válido, entre 1 a 12.
Repetir a leitura até que o usuário informe um valor válido. Mostrar da seguinte forma, para, por exemplo,
informado o valor 7:
1 + 6 = 7
2 + 5 = 7
3 + 4 = 7
4 + 3 = 7
5 + 5 = 7
6 + 1 = 7
*/
int main (void)
{
    int Valor,Cont,Cont2;
    char Continuar;
    do
    {
        do
        {
            system("cls");
            printf("\n_______________________________________________________________________________\n");
            printf("Infome um valor de soma de duas casas dos dados: ");
            scanf("%d",&Valor);
            if(Valor < 1 && Valor > 12)
            {
                printf("Informe um valor entre 1 e 12.");
            }

        }while(Valor < 1 && Valor > 12);

        for(Cont=1;Cont<=6;Cont++)
        {
            for(Cont2=0;Cont2<=6;Cont2++)
            {
                if(Cont + Cont2 == Valor)
                {
                    printf("%d + %d = %d \n",Cont,Cont2,Valor);
                }

            }
        }



        printf("\n______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
