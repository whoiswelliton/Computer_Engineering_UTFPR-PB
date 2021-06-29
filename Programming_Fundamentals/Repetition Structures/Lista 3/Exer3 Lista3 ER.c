#include <stdio.h>
#include <stdlib.h>
/*
Uma pessoa realizou um empréstimo bancário de R$ 10.000,00 que deverão ser pagos em 24 meses com juros
de 2% ao mês, incluídos já na primeira parcela. Determine e apresente o valor da última parcela e o
montante pago ao final do empréstimo.
*/
int main (void)
{
    int Cont;
    float Total = 0;
    float ValorP=10.00000/24;

    for(Cont=1;Cont<=24;Cont++)
    {
        ValorP = ValorP + ValorP*0.02;
        Total = Total + ValorP;
    }

    printf("O valor da ultima parcela e de: %f \1\2\n",ValorP);
    system("pause");
}
