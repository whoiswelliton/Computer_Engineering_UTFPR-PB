#include <stdio.h>
#include <stdlib.h>

/*
Ler a quantidade de kilowatts de energia elétrica consumidos por uma residência.
Calcular e mostrar o valor em reais de cada kilowatts, o valor total a ser pago e o novo valor a ser pago
 por essa residência quando há desconto de 10%. Considere que 100 kilowatts custam 1/7 do salário mínimo.
  Ler o valor do salário mínimo.
*/
int main (void)
{
    char Continuar;
    float K,S,T,C;

    do
    {
        system("cls");
        printf("\n________________________________________________________________________________\n");
        printf("Informe a quantidade de kilowatts consumidos no mes: ");
        scanf("%f",&K);
        printf("Informe o salario minimo da casa: ");
        scanf("%f",&S);
        printf("__________________________________________________________________________________\n");

        C = (S/7)/100;

        T = C * K;

        system("cls");

        printf("\nO valor total consumido no mes foi: %.2f",T);

        printf("\n________________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
