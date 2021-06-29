#include <stdio.h>
#include <stdlib.h>
#include <Pause.h>

/*
Faca um programa para calcular a quantidade necessária de latas de tinta para pintar uma parede com X metros
de largura por H metros de altura. Também é informada a altura e largura da porta e das janelas e a quantidade
 de janelas. As janelas possuem o mesmo tamanho. O usuário informa o consumo de tinta por metro quadrado e a
 quantidade de litros de tinta de uma lata. Indicar a quantidade inteira para o número de latas de tinta
 necessário (arredondar o valor para o próximo inteiro).
*/
int main (void)
{
    char Continuar;
    do
    {
        system("cls");
        printf("\n________________________________________________________________________________\n");
        printf(" ");
        printf("__________________________________________________________________________________\n");

        printf("_________________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
    Pause();
}
