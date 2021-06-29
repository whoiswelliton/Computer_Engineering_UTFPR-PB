#include <stdio.h>
#include <stdlib.h>
/*
Apresentar os números entre 0 e 4, com intervalo de 0.25 entre eles, ou seja, 0, 0.25, 0.5, 0.75 ... 4.
*/
int main (void)
{
    float Cont;

    for(Cont=0;Cont<=4;Cont=Cont+0.25)
    {
        printf("%.2f\t",Cont);
    }
    printf("\n");
    system("pause");
}
