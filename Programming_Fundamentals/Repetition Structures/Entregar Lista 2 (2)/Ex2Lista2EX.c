#include <stdio.h>
#include <stdlib.h>

/*
Elaborar um programa para automatizar o caixa de uma loja.  Leia a quantidade e o valor unitário de cada
produto. Calcule o valor total da compra. Informe esse valor para o usuário e o usuário informa o valor
 para pagamento. O programa calcula o troco e informa-o ao usuário em notas de 10, 5, 1 e os centavos.
 Prosseguir a leitura enquanto a quantidade for maior que zero. Se informado zero ou valor negativo para
  a quantidade não ler o valor unitário.
Observação: fornecer o troco, de 57.30, por exemplo, na forma:

*/
int main (void)
{
    int Qtd1,Qtd2=0;
    float Prod,Soma,C,D,U,Troco,Pago,M;

    char Continuar;
    do
    {
        system("cls");
        printf("\n_________________________________________________________________________\n");
        printf("Quantos Produtos foram Comprados: ");
        scanf("%d",&Qtd1);


        while(Qtd2 != Qtd1)
        {
            printf("\n_________________________________________________________________________\n");
            printf("Informe o valor do Produto: ");
            scanf("%f",&Prod);

            Soma = Soma + Prod;

            Qtd2++;
        }



        system("cls");

        printf("\n_________________________________________________________________________\n");
        printf("O Valor total da Compra: RS %.2f ",Soma);
        printf("\n_________________________________________________________________________\n");
        printf("Quanto em dinheiro voce deseja pagar: ");
        scanf("%f",&Pago);

        system("cls");

        if(Soma > Pago)
        {
            Troco = Soma - Pago;


            C = (int)Troco/100;
            D = (int)Troco%100/10;
            U = (int)Troco%10;
            M = Troco - (int)Troco;

            printf("\nSeu Troco e de: %.2f",Troco);
            printf("\n\nCedulas: %.0f Cedulas de 100 Reais",C);
            printf("\n%.0f cedulas de 10 reais",D);
            printf("\n%0.f cedulas de 1 real",U);
            printf("\n%0.2f Centavos em Moedas",M);

        }
        else if(Pago > Soma)
        {
            Troco = Pago - Soma;

            printf("\nSeu Saldo devedor diminuiu para: %.2f",Troco);
        }
        else
        {
            printf("\nValor Total Pago e sem Troco!");
        }


        printf("\n________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
