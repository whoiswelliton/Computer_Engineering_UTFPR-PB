#include <stdio.h>
#include <stdlib.h>
/*
Escreva um algoritmo para ler o número de votos brancos, nulos (incluem eleitores ausentes) e válidos
de uma eleição. E calcular e mostrar o percentual que cada um (brancos, nulos e válidos) representa em
 relação ao total de eleitores. Lembrar que os valores dos percentuais podem não ser inteiros.
*/

int main (void)
{
    float VBranco, VNulo, VValido;
    float Total;

    printf("Informe o Total de Votos Brancos: ");
    scanf("%f",&VBranco);
    printf("Informe o Total de Votos Nulos: ");
    scanf("%f",&VNulo);
    printf("Informe o Total de Votos Validos: ");
    scanf("%f",&VValido);

    Total=VBranco+VNulo+VValido;
    VBranco=(VBranco*100)/Total;
    VNulo=(VNulo*100)/Total;
    VValido=(VValido*100)/Total;

    printf("O Percentual de Votos Validos é: %.2f%%\n",VValido);
    printf("O Percentual de Votos Brancos é: %.2f%%\n",VBranco);
    printf("O Percentual de Votos Nulos é: %.2f%%\n",VNulo);

    system("pause");
}
