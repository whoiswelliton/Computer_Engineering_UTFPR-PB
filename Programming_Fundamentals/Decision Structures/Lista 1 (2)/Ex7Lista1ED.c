#include <stdio.h>
#include <stdlib.h>

/*
Elaborar um algoritmo que lê dois valores, verifica se o primeiro é múltiplo do segundo e escreve a mensagem ‘São múltiplos’ ou ‘Não são múltiplos’
dependendo da condição. Verificar para que não seja realizada uma divisão por zero. Nesse caso, informar que não é possível realizar uma divisão por zero.
*/
int main (void)
{
    int Num1,Num2;
    char Continuar;
    do
    {
        system("cls");
        printf("\n________________________________________________________________________________\n");
        printf("Informe o primeiro numero: ");
        scanf("%d",&Num1);
        printf("\n________________________________________________________________________________\n");
        printf("Informe o segundo numero: ");
        scanf("%d",&Num2);
        system("cls");

        if(Num1 % Num2 == 0)
        {
            printf("Sao multiplos!");
        }
        else
        {
            printf("Não sao multiplos!");
        }

        printf("\n_________________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
