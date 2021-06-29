#include <stdio.h>
#include <stdlib.h>
/*
A pessoa A tem 1,50 metros e cresce 2 centímetros por ano, enquanto a pessoa B tem 1,10 metros e
 cresce 3 centímetros por ano. Construa um algoritmo que calcule e imprima quantos anos serão
  necessários para que B seja maior que A.
*/
int main (void)
{
    float PA=1.50;
    float PB=1.10;
    int Anos=0;
    float Cont;

    do
    {
        PA = PA + 0.02;
        PB = PB + 0.03;
        Anos++;
    }while(PA >= PB);

    printf("Vai demorar %d Anos\n",Anos);
    system("pause");
}
