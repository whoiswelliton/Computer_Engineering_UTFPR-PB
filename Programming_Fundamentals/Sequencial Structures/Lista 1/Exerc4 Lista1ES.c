#include <stdio.h>
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

int main(void)
{
    printf("Soma Dos Valores \n");

    int Numero1;
    int Numero2;
    float Media;

    printf("Informe o Primeiro Valor: ");
    scanf("%d",&Numero1);
    printf("Informe o Seegundo Valor: ");
    scanf("%d",&Numero2);


    Media = Numero1 + Numero2


    printf("A Soma é: %f",Media);

}

