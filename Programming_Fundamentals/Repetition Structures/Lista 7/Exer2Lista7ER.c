#include <stdio.h>
#include <stdlib.h>
/*
Escreva um programa que imprima todas as possibilidades de que no lançamento de dois dados tenhamos um valor
informado pelo usuário como resultado da soma dos valores de cada face desses dados. O usuário deve informar
um valor válido, entre 1 a 7. Repetir a leitura até que o usuário informe um valor válido. Mostrar da seguinte
forma, para, por exemplo, informado o valor 7:
1 + 6 = 7
2 + 5 = 7
3 + 4 = 7
4 + 3 = 7
5 + 5 = 7
6 + 1 = 7
*/
int main (void)
{

    char Continuar;
    int Num,D1,D2;

    do
    {
        system("cls");
        do
        {
            printf("Informe o valor para soma das faces: ");
            scanf("%d",&Num);
            if (Num<2 || Num>12)
            {
                printf("Valor deve estar entre 2 e 12\n");
            }
        }while(Num<2 || Num>12);

        for(D1=1;D1<=6;D1++)
        {
            for(D2=1;D2<=6;D2++)
            {
                if(D1+D2 == Num)
                {
                    printf("%d + %d = %d\n",D1,D2,Num);
                }
            }
        }

        printf("\nExecutar novamente (S/s para sim); ");
        getchar();
        scanf("%c",&Continuar);


    }while(Continuar == 's' || Continuar == 'S');

    system("pause");
}
