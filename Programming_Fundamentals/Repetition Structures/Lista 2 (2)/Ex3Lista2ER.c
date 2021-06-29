#include <stdio.h>
#include <stdlib.h>

/*
 Calcular e mostrar o fatorial de um número informado pelo usuário.
*/
int main (void)
{
    int Num,Fat=1,Cont;
    char Continuar;

    do
    {
        system("cls");
        printf("\n_____________________________________________________________________________\n");
        printf("Informe um Numero: ");
        scanf("%d",&Num);

        for(Cont=1;Cont<=Num;Cont++)
        {
            Fat = Fat*Cont;

            printf("%d = %d\n",Cont,Fat);
        }

        printf("\n______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
