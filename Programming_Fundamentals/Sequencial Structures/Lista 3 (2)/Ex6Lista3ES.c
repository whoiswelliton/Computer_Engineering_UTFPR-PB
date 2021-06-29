#include <stdio.h>
#include <stdlib.h>

/*
Suponha que um caixa disponha apenas de cédulas de R$ 100, 10 e 1. Escreva um programa para ler o valor de uma conta e o valor fornecido pelo usuário para
 pagar essa conta, e calcule e troco. Calcular e mostrar a quantidade de cada tipo de cédula que o caixa deve fornecer como troco. Mostrar,
 também o valor da compra e do troco.

*/
int main (void)
{
    char Continuar;
    float Ced1,Ced2,Ced3,Conta,Troco,Pago;

    do
    {
        system("cls");
        printf("\n________________________________________________________________________________\n");
        printf("Informe o Valor total da Conta: ");
        scanf("%f",&Conta);
        printf("\n________________________________________________________________________________\n");
        printf("Informe o Quanto vai ser pago: ");
        scanf("%f",&Pago);

        system("cls");

        Troco = Pago - Conta;
        if(Troco < 0)
        {
            printf("\n                      Conta Paga Parcialmente,SEM  TROCO!");
            printf("\n________________________________________________________________________________\n");
            printf("\n                            Ainda Deve %.2f",Troco*-1);
        }
        else
        {

            Ced1= (int)Troco/100;
            Ced2= (int)Troco%100/10;
            Ced3= (int)Troco%10;

            printf("\n\nSeu troco %c: R$ %.2f",130,Troco);
            printf("\n\nTroco =");
            if(Ced1 > 0)
            {
                printf("\n\n%.0f Notas de 100",Ced1);
            }
            if(Ced2 > 0)
            {
                printf("\n%.0f Notas de 10",Ced2);
            }
            if(Ced3 > 0)
            {
                printf("\n%.0f Notas de 1",Ced3);
            }

        }


        printf("\n_______________________________________________________________________________\n\n");
        printf("\n                          Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
