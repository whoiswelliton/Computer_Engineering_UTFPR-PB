#include <stdio.h>
#include <stdlib.h>
/*
Ler três valores que representam os comprimentos dos lados de um triângulo e determinar se esses
valores podem determinar um triângulo. Para formar um triângulo é necessário que a soma de dois
lados quaisquer seja maior (ou igual no caso de o triângulo ter área zero) ao valor do outro lado.
*/
int main (void)
{
    int A,B,C;

    printf("Informe o valor do primeiro lado: ");
    scanf("%d",&A);
    printf("Informe o valor do segundo lado: ");
    scanf("%d",&B);
    printf("Informe o valor do terceiro lado: ");
    scanf("%d",&C);
    system("pause");

    if (A > B && A > C)
}
