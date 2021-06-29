#include <stdio.h>
#include <stdlib.h>
/*
Utilizando uma estrutura de repetição, apresentar todos os números da sequência a seguir:
 0, 0.25, 0.5, 0.75, 1.0, 1.25, 1.5, 1.75, 2.0, 2.25, 2.5, 2.75, 3.0, 3.25, 3.5, 3.75, 4.0.
*/
int main (void)
{
    float Cont;
    int Colunas;

    for(Cont=0;Cont<=10;Cont+=0.25)
    {
        printf("² %.2f °\t",Cont);
    }
    system("pause");
}
