# include <stdio.h>
# include <stdlib.h>
/*
Considerando que para um consórcio sabe-se o número total de prestações, a quantidade de prestações
pagas e o valor de cada prestação (que é fixo). Escreva um programa que determine o valor total já
pago pelo consorciado e o saldo devedor.
*/
int main (void)
{
    float NumP,PrestP,ValorP,ValorT,Saldo;

    printf("Informe a quantidade de prestacoes: ");
    scanf("%f",&NumP);
    printf("Informe a quantidade de prestacoes pagas: ");
    scanf("%f",&PrestP);
    printf("Informe o valor de cada Prestacao: ");
    scanf("%f",&ValorP);

    ValorT = PrestP*ValorP;
    Saldo = NumP*ValorP-ValorT;

    printf("O Valor Total ja pago é: %.2f\n",ValorT);
    printf("O Saldo devedor e de: %.2f\n",Saldo);

    system("pause");
}
