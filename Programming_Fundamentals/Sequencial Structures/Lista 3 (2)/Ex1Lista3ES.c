#include <stdio.h>
#include <stdlib.h>

/*Considerando que para um consórcio sabe-se o número total de prestações, a quantidade de prestações pagas e
 o valor de cada prestação (que é fixo). Escreva um algoritmo que determine o valor total já pago pelo
  consorciado e o saldo devedor.
*/
int main (void)
{
    char Continuar;
    int Pres,Pagas;
    float Valor,Pago,Dev,Total;

    do
    {
        system("cls");
        printf("\n______________________________________________________________________________\n");
        printf("Informe o numero total de pretacoes: ");
        scanf("%d",&Pres);
        printf("Informe o numero total de pretacoes pagas: ");
        scanf("%d",&Pagas);
        printf("Informe o valor de cada pretacao: ");
        scanf("%f",&Valor);

        Total = Pres * Valor;
        Pago = Pagas * Valor;
        Dev = Total - Pago;

        system("cls");

        printf("\nO Valor total das prestacoes %c: %.2f",130,Total);
        printf("\nO Valor total das prestacoes ja pagas %c: %.2f",130,Pago);
        printf("\nO Valor total das prestacoes que ainda faltam %c: %.2f",130,Dev);

        printf("\n\n_______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
