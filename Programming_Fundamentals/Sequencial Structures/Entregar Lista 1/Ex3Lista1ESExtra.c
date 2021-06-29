#include <stdio.h>
#include <stdlib.h>
#include <Pause.h>

/*
Ler a quantidade de kilowatts de energia elétrica consumidos por uma residência.
Calcular e mostrar o valor em reais de cada kilowatts, o valor total a ser pago e o novo valor a ser pago
 por essa residência quando há desconto de 10%. Considere que 100 kilowatts custam 1/7 do salário mínimo.
  Ler o valor do salário mínimo.
*/
int main (void)
{
    char Continuar;
    float K,S,T;

    do
    {
        system("cls");
        printf("\n________________________________________________________________________________\n");
        printf("Informe a quantidade de kilowatts consumidos no mes: ");
        scanf("%f",&K);
        printf("Informe o salaraio minimo da casa: ");
        scanf("%f",&S);
        printf("__________________________________________________________________________________\n");




        printf("_________________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
    Pause();
}
