#include <stdio.h>
#include <stdlib.h>
/*
Ler a altura e o sexo de uma pessoa (F ou f para feminino e M ou m para masculino, se outro caractere,
 informar que é inválido e finalizar o programa) e construir um algoritmo que calcule seu peso ideal,
 utilizando as seguintes fórmulas:
a) para homens: (72,7 * h) - 58;
b) para mulheres: (62,1 * h) - 44,7.
Observação, para ler caractere e comparar variável do tipo caractere:
char Pessoa;
scanf(“%c”,&Pessoa);
if (Pessoa == ‘f’ || Pessoa == ‘F’)
*/
int main (void)
{
    float Altura,PesoIdeal;
    char Masculino,Feminino,Sexo;


    printf("Informe o Sexo: ");
    scanf("%c",&Sexo);
    printf("Informe a altura: ");
    scanf("%f",&Altura);

    if (Sexo == 'M' || Sexo == 'm')
    {
        PesoIdeal = (72,7 * Altura) - 58;
        printf("Seu peso ideal e: %f\n",PesoIdeal);
    }
    else if (Sexo == 'F' || Sexo == 'f')
    {
        PesoIdeal = (62,1 * Altura) - 44,7;
        printf("Seu peso ideal e: %f\n",PesoIdeal);
    }
    system("pause");
}
