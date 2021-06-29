#include <stdio.h>
#include <stdlib.h>

/*
7) Apresentar os N primeiros números pares e divisíveis por 3 informados pelo usuário. Se o usuário informar
um número negativo transformá-lo em positivo antes de utilizar.
Por exemplo:
Informe a quantidade de números pares a serem mostrados:
3
mostrar:
Os 3 primeiros números pares são:  6 12 18
*/
int main (void)
{
    int Num,Qtd=0,Cont;
    char Continuar;
    do
    {
        Cont=6;
        Num=0;
        system("cls");
        printf("\n_______________________________________________________________________________\n");
        printf("Informe a quantidade de numeros pares e divisiveis por 3:");
        scanf("%d",&Num);

        if(Num < 0)
        {
            Num = Num *-1;
        }

            for(Cont=6;Cont<=1000;Cont++)
            {
                if(Cont % 2 == 0 && Cont % 3 == 0)
                {
                    printf("%d  ",Cont);
                    Qtd++;
                    if(Qtd == Num)
                    {
                        break;
                    }
                }
            }

        printf("\n______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
