#include <stdio.h>
#include <stdlib.h>

/*
Faça um programa para calcular a quantidade de fita necessária, em centímetros, para amarrar um pacote com
 duas voltas, sendo uma pela largura e outra pelo comprimento do pacote. Serão fornecidas a largura,
 a altura e o comprimento do pacote. Para amarrar as pontas da fita são necessários 15 cm de fita em
 cada ponta. A Figura ilustra a maneira como a fita é passada no pacote.
*/
int main (void)
{
    char Continuar;
    int Largura,Altura,Comprimento,Total;

    do
    {
        system("cls");
        printf("\n________________________________________________________________________________\n");
        printf("Informe a Largura do pacote: ");
        scanf("%d",&Largura);
        printf("Informe a Altura do pacote: ");
        scanf("%d",&Altura);
        printf("Informe o comprimento do pacote: ");
        scanf("%d",&Comprimento);

        system("cls");

        Total = (((Altura+Comprimento)*2) + ((Largura+Altura)*2)) + 15;

        printf("\nO Tamanho da fita utilizada deve ser: %dcm ",Total);

        printf("\n_______________________________________________________________________________\n\n");
        printf("\n                          Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
