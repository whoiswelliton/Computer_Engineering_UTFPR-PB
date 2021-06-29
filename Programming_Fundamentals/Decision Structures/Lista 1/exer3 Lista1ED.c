#include <stdio.h>
/*
Elaborar um algoritmo que leia uma letra. Se informado ‘F’ ou ‘f’ mostrar a mensagem “pessoa física”,
se informado ‘J’ ou ‘j’ mostrar a mensagem “pessoa jurídica” ou "tipo de pessoa inválido" para qualquer
 outro caractere.
*/
int main (void)
{
    char Tipo;

    printf("Informe o tipo de empresa: ");
    scanf("%c",&Tipo);

    if (Tipo == 'f' || Tipo 'F')
    {
       printf(" pessoa fisica");
    }
    else if (Tipo == 'j' || Tipo == 'J')
    {
       printf("pessoa jurídica");
    }
    else// qualquer outro caractere
    {
      printf("tipo invalido");
    }
}
