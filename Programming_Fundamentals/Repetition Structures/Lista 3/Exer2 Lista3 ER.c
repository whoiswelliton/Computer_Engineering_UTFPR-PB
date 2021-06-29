#include <stdio.h>
#include <stdlib.h>
/*
Uma pessoa aplicou R$ 100,00 com rendimento de 5% ao mês. Quantos meses serão necessários para que
o capital investido ultrapasse a R$ 200,00.
*/
int main (void)
{
    float Valor=100.00;
    int Meses=0;
    float Cont;

    do
    {
        Valor = Valor + (Valor*0.05);
        Meses++;

    }while (Valor <=200.00);

    printf("Serao nescessarios %d Meses \1 \n",Meses);

    system("pause");
}
