#include <stdio.h>
#include <stdlib.h>
#include <Pause.h>

/*
Escreva um algoritmo para ler o salário mensal de um funcionário e o percentual de reajuste.
 Calcular e mostrar o valor do novo salário.
*/
int main (void)
{
    char Continuar;
    float S,C,V,T,S1;
    do
    {
        system("cls");
        printf("\n_____________________________________________________________________________\n");
        printf("Informe o Salario fixo do Vendedor: ");
        scanf("%f",&S);
        printf("Informe quantos carros foram vendidos pelo vendedor: ");
        scanf("%f",&C);
        printf("Informe o valor total das vendas: ");
        scanf("%f",&V);

        S1 = V/C;
        T = S + (S1+S1*(5/100));


        printf("\nO Salario Final com reajustes %c: %.2f",130,T);

        printf("\n______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
    Pause();
}


