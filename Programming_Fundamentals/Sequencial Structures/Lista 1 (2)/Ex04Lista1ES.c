#include <stdio.h>
#include <stdlib.h>
#include "Pause.h"
/* Tendo como entrada dois valores inteiros, elaborar um algoritmo para calcular e mostrar:
a) A soma desses números;
a) A subtração do primeiro pelo segundo;
c) A multiplicação entre eles;
d) A divisão inteira do primeiro pelo segundo;
e) A divisão float do primeiro pelo segundo;
e) O resto da divisão do primeiro pelo segundo.
   Entrada:
      Numero 1
      Numero 2
   Processamento
      Media = (Numero 1 + Numero 2)
   Saída
      Media
*/

int main (void)
{
    int Num1,Num2,Soma,Sub1,Mult,div1,Resto;
    float div2;
    char Continuar;

    do
    {
        system("cls");

        printf("________________________________________________________________________________\n");
        printf("Informe o Primeiro Numero: ");
        scanf("%d",&Num1);
        printf("________________________________________________________________________________\n");
        printf("Informe o Segundo Numero: ");
        scanf("%d",&Num2);
        printf("________________________________________________________________________________\n");

        system("cls");

        Soma = Num1 + Num2;
        Sub1 = Num1 - Num2;
        Mult = Num1 * Num2;
        div1 = Num1 / Num2;
        div2 = (float)Num1 / Num2;
        Resto = (int)Num1 % Num2;

        printf("________________________________________________________________________________\n");
        printf("O Resultado da Soma %c: %d",130,Soma);
        printf("\n________________________________________________________________________________\n");
        printf("O Resultado da Subtracao %c: %d",130,Sub1);
        printf("\n________________________________________________________________________________\n");
        printf("O Resultado da Multiplicacao %c: %d",130,Mult);
        printf("\n________________________________________________________________________________\n");
        printf("O Resultado Divisao inteira %c: %d",130,div1);
        printf("\n________________________________________________________________________________\n");
        printf("O Resultado Divisao Float %c: %.2f",130,div2);
        printf("\n________________________________________________________________________________\n");
        printf("O Resto da Divisão %c: %d",130,Resto);
        printf("\n________________________________________________________________________________\n");

        printf("\n\nPara executar Novamente (S/s Para sim):");
        fflush(stdin);
        scanf("%c",&Continuar);
    }while(Continuar == 's' || Continuar == 'S');
    Pause();
}
