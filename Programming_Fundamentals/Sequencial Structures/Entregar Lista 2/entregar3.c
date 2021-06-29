#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    float dist, consumo, gasto, precolt, lts;

    printf("informe a distancia percorida: ");
    scanf("%f",&dist);
    printf("informe a consumo: ");
    scanf("%f",&consumo);
    printf("informe a preco do litro de combutivel: ");
    scanf("%f",&precolt);

    gasto=(dist/consumo)*precolt;
    lts=dist/consumo;

    printf("maria gatara %.2f litros com um custo total de %.2f reais",lts, gasto);
}
