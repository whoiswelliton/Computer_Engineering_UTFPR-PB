#include <stdio.h>
#include <stdlib.h>
/*
Utilizando uma estrutura de repetição, apresentar todos os valores numéricos inteiros pares situados na
faixa de 1000 a 1500.
*/
int main (void)
{
    int Cont,Pares;

    for(Cont=1000;Cont<=1500;Cont++)
    {
        if(Cont % 2 == 0)
        {
            printf("ª %d º\t",Cont);
        }
    }
    system("pause");
}
