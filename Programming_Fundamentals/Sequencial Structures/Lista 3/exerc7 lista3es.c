#include <stdio.h>
#include <stdlib.h>
/*
Ler um número que representa a quantidade de dias. Informe os anos (com 360 dias), meses
(considere-os com 30 dias) e os dias contidos nesse valor.
Exemplo: 390 dias contêm 1 ano(s), 1 mês(es) e 0 dia(s).
*/
int main (void)
{
    long int Anos, Meses, Dias;

    printf("Informe a quantidade de dias: ");
    scanf("%li",&Dias);

    Anos = Dias/365;
    Meses = Dias%365/12;
    Dias = Dias%365%12;

    printf("Anos: %li\n",Anos);
    printf("Meses: %li\n",Meses);
    printf("Dias: %li\n",Dias);

    system("pause");
}

