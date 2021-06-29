#include <stdio.h>
#include <stdlib.h>
/*Elaborar um algoritmo que lê um valor que se refere a altura de uma pessoa e mostra uma mensagem
conforme a faixa de altura. Utilizar variável do tipo double:
Altura
Informação mostrada
menos que 1,50
“abaixo de um metro e meio”
de 1,50 a 1,80
“entre um metro e meio e um metro e oitenta centímetros”
mais que 1,80
“acima de um metro e oitenta centímetros”
*/
int main (void)
{
    double Altura;

    printf("Informe a Altura: ");
    scanf("%lf",&Altura);

    if (Altura < 1.5)
    {
        printf("Menor que 1,5 metros\n");
    }
    else if (Altura <= 1.8)//Altura>=1.5 && altura<=1.8
    {
        printf("Entre 1,51 e 1,8 metros\n");
    }
    else
    {
        printf("Maior que 1,8 metros\n");
    }

    system("pause");
}


