#include <stdio.h>
#include <stdlib.h>

/*
Ler dois números que representam os limites de um intervalo. Mostrar os ímpares desse intervalo,
em ordem decrescente. O usuário pode informar os valores que representam os limites do intervalo
em ordem crescente ou decrescente.
*/
int main (void)
{
    int Lim1,Lim2,Cont;
    char Continuar;

    do
    {
        system("cls");
        printf("\n________________________________________________________________________________\n");
        printf("Informe o primeiro limite: ");
        scanf("%d",&Lim1);
        printf("Informe o segundo limite: ");
        scanf("%d",&Lim2);

        system("cls");

        if(Lim1 < Lim2)
        {
           for(Cont=Lim2;Cont>=Lim1;Cont--)
            {
                if(Cont % 2 != 0)
                {
                    printf("%d\t",Cont);
                }
            }
        }
        else
        {
            for(Cont=Lim1;Cont>=Lim2;Cont--)
            {
                if(Cont % 2 != 0)
                {
                    printf("%d\t",Cont);
                }
            }
        }

        printf("\n________________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
