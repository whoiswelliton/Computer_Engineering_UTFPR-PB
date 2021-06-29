#include <stdio.h>
#include <stdlib.h>
/*
Elaborar um programa para apresentar todos os números divisíveis por 4 e menores que 200.
Apresentar os números com 8 valores por linha.
*/
int main (void)
{
    int Num=0,Cont,Qnt;

    for(Cont=0;Cont<=200;Cont++)
    {
        if (Cont %4 ==0)
        {
            printf("%d\t",Cont);
            Num++;//mostrado mais um multiplo de quatro
            if (Num %8 ==0)
            {
                printf("\n");
            }
        }
    }
    system("pause");
}
