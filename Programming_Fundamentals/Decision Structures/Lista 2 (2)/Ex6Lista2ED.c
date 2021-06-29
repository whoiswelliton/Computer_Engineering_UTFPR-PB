#include <stdio.h>
#include <stdlib.h>


/*
Um hotel cobra R$ 80,00 por diária mais uma taxa de serviços de acordo com:
	R$ 5,50 por diária, se o número de diárias for maior que 15;
	R$ 6,00 por diária, se o número de diárias for igual a 15;
	R$ 8,00 por diária, se o número de diárias for menor que 15.
	Fazer um programa para determinar o valor a ser pago pelo cliente. Se informado zero ou valor
	negativo para a quantidade de diárias não realizar o cálculo.

*/
int main (void)
{
    int Diarias;
    float Valor;
    char Continuar;
    do
    {
        system("cls");
        printf("\n______________________________________________________________________________\n");
        printf("Informe a Quantidade de Diarias: ");
        scanf("%d",&Diarias);

        system("cls");

        if(Diarias > 15)
        {
            Valor = (Diarias*80) + (Diarias*5.50);
            printf("Valor a ser Pago: %.2f ",Valor);
        }
        else if(Diarias < 15)
        {
            Valor = (Diarias*80) + (Diarias*6);
            printf("Valor a ser Pago: %.2f ",Valor);
        }
        else if(Diarias == 15)
        {
            Valor = (Diarias*80) + (Diarias*8);
            printf("Valor a ser Pago: %.2f ",Valor);
        }
        else
        {
            printf("Informe um Valor Positivo");
        }

        printf("\n_______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');

}
