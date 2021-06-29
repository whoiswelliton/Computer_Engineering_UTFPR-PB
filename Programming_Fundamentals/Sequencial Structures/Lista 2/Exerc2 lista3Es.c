#include <stdio.h>
#include <stdlib.h>
/*
Faça um programa para calcular a quantidade de barbante necessária, em centímetros, para amarrar
um pacote com duas voltas de barbante, sendo uma pela largura e outra pelo comprimento do pacote.
Serão fornecidas a largura, a altura e o comprimento do pacote. Para amarrar as pontas do barbante
são necessários 10 cm de barbante em cada ponta.
*/

int main (void)
{
    int Largura,Altura,Comprimento,BarbanteN;

    printf("Informe o valor da largura do pacote: ");
    scanf("%d",&Largura);
    printf("Informe o valor da Altura do Pacote: ");
    scanf("%d",&Altura);
    printf("Informe o valor do comprimento do pacote: ");
    scanf("%d",&Comprimento);

    BarbanteN = 4*Altura+2*Comprimento+2*Largura+20;

    printf("O comprimento do barbante e de: %d\n",BarbanteN);

    system("pause");
}
