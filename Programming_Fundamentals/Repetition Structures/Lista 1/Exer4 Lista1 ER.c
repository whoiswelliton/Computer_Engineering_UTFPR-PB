#include <stdio.h>
#include <stdlib.h>
/*
Apresentar os números entre 10 e 0, ou seja, em ordem decrescente.
*/
int main (void)
{
    int Cont;

    for(Cont=10;Cont>=0;Cont=Cont-1)
    {
        printf("%d\t",Cont);
    }
    printf("\n");
    system("pause");
}
