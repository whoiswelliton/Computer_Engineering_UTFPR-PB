#include <stdio.h>
#include <stdlib.h>
/*
Suponha que um caixa disponha apenas de cédulas de R$ 100, 10 e 1. Escreva um programa para ler o
valor de uma conta e o valor fornecido pelo usuário para pagar essa conta, e calcule e troco.
Calcular e mostrar a quantidade de cada tipo de cédula que o caixa deve fornecer como troco.
Mostrar, também o valor da compra e do troco.
*/
 int main (void)
 {
    long int Nota100, Nota10, Nota1, Conta, ValorF, Troco;

    printf("Informe o valor da conta a ser paga: ");
    scanf("%li",&Conta);
    printf("Informe o valor pago pelo devedor: ");
    scanf("%li",&ValorF);

    Troco = ValorF-Conta;
    Nota100 = Troco/100;
    Nota10 = (int)Troco%100/10;
    Nota1 = (int)Troco%100%10;

    printf("O valor total de troco e de: %li\n",Troco);
    printf("Total de notas de 100 reais: %li\n",Nota100);
    printf("Total de notas de 10 reais: %li\n",Nota10);
    printf("Total de notas de 1 real: %li\n",Nota1);

    system("pause");
 }
