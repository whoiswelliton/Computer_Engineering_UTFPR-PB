#include <stdio.h>
#include <stdlib.h>
/*
Apresentar os múltiplos de 10 entre 1000 e 0 (ordem decrescente). Mostrar os valores separados por
uma marca de tabulação e em colunas com 8 números por linha.
*/

int main (void)
{
    int Cont;
    int Qnt=0;

    for(Cont=1000;Cont>=0;Cont--)
    {
        if (Cont %10==0)
        {
        printf("%d\t",Cont);
        Qnt++;
        if (Qnt %8==0)
        {
            printf("\n");
        }
        }
    }


    system("pause");
}
