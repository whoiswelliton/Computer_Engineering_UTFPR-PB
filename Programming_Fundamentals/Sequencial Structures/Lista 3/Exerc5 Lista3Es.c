#include <stdio.h>
#include <stdlib.h>
/*
Ler um número inteiro longo (long int) que representa segundos e convertê-lo para horas,
minutos e segundos. Mostrar a quantidade de horas minutos e segundos obtidos.
Observação:
//declarar uma variável inteiro longo
long int Num;
//ler uma variável inteiro longo
scanf(“%li”,&Num);
//mostrar o conteúdo de uma variável inteiro longo
printf(“valor %li”,Num);
*/
int main (void)
{
    long int Segundos, Minutos, Horas;

    printf("Informe o valor de segundos: ");
    scanf("%li",&Segundos);

    Horas = Segundos/3600;
    Minutos = Segundos%3600/60;
    Segundos = Segundos%3600%60;

    printf("Total de horas e: %li\n",Horas);
    printf("Total de minutos e: %li\n",Minutos);
    printf("Total de segundos e: %li\n",Segundos);

    system("pause");
}
