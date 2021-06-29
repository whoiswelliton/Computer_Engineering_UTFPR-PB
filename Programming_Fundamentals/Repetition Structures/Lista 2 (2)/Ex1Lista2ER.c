#include <stdio.h>
#include <stdlib.h>


/*
Apresentar a tabuada de um número informado pelo usuário.
*/
int main (void)
{
    int Num,Cont,Tabu;
    char Continuar;
    do
    {
        system("cls");
        printf("\n____________________________________________________________________________\n");
        printf("\nInforme um Numero: ");
        scanf("%d",&Num);

        system("cls");

        for(Cont=1;Cont<=100;Cont++)
        {
            Tabu = Cont*Num;
            printf("%d x %d = %d \t",Num,Cont,Tabu);
        }


        printf("\n______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');

}
