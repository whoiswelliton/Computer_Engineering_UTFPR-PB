#include <stdio.h>
#include <stdlib.h>
/*
Mostrar os números entre 10 e 0 (ordem decrescente) com intervalo de 0.5.
*/
int main (void)
{
  int Cont;

    for(Cont=10;Cont>=0;Cont=Cont-0.5)
    {
        printf("%d\t",Cont);
    }
    printf("\n");
    system("pause");
}

