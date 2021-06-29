#include <stdio.h>
#include <stdlib.h>

/*
 Utilizando uma estrutura de repetição, ler 3 pares de valores informados pelo usuário. Para cada par de
 valores, dividir o primeiro valor informado pelo segundo e apresentar o resultado com duas casas decimais.
  Se o usuário informar zero para o valor que será o divisor, mostrar uma mensagem que não é possível efetuar
   a divisão.
*/
int main (void)
{
    float Num1,Num2,Div;
    int Qtd=0;
    char Continuar;
    do
    {
        system("cls");

        do
        {
            printf("\n_______________________________________________________________________________\n");
            printf("Informe o primeiro numero: ");
            scanf("%f",&Num1);
            printf("Informe o segundo numero: ");
            scanf("%f",&Num2);

            if(Num2 != 0)
            {
                Div = (float)Num1/Num2;

                printf("\nDivisao = %.2f",Div);
            }

            Qtd++;

        }while(Qtd < 3);

        printf("\n_______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
