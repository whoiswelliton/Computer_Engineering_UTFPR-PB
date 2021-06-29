#include <stdio.h>
#include <stdlib.h>
/*
presentar os N primeiros números pares informados pelo usuário.
Se o usuário informar um número negativo transformá-lo em positivo antes de utilizar.
Por exemplo:
Informe a quantidade de números pares a serem mostrados:
3
mostrar:
Os 3 primeiros números pares são:  2 4 6
*/

int main (void)
{
    char Continuar;
    int Num,Qtpares,Paresm;

    do
    {
        system("cls");

        printf("Informe a quantidade de números pares a serem mostrados: ");
        scanf("%d",&Qtpares);
        Num=2;
        Paresm=0;

        if(Qtpares < 0)
        {
            Qtpares *= -1;
        }

        do
        {
            if(Num % 2 == 0)
            {
                printf("%d\t",Num);
                Paresm++;
            }
            Num++;
        }while(Paresm < Qtpares);








        printf("\nExecutar Novamente (S/s para sim)");
        getchar();
        scanf("%c",&Continuar);

    }while(Continuar == 'S' || Continuar == 's');


    system("pause");
}
