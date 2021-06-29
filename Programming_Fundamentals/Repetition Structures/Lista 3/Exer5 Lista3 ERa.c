#include <stdio.h>
#include <stdlib.h>
/*
Ler um número inteiro e determinar se o mesmo é primo. Um número é primo quando é divisível de
maneira exata somente por 1 e por ele mesmo.
*/
int main (void)
{
    printf("\2\n");

    int Num;
    int Qtdedivisores=0;
    int Cont;

    printf("Informe um numero para verificar se primo: ");
    scanf("%d",&Num);

    if (Num >=1 && Num<=3)
    {
        printf("%d e primo\n",Num);
    }
    else
    {
        for(Cont=2;Cont<=Num/2;Cont++)
        {
            if (Num % Cont == 0)
            {
                Qtdedivisores++;
                break;
            }
        }
        if (Qtdedivisores ==0)
        {
            printf("%d E primo\n",Num);
        }
        else
        {
            printf("%d Nao e primo\n",Num);
        }
    }

    system("pause");
}
