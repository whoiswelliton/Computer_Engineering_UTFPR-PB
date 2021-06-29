#include <stdio.h>
#include <stdlib.h>

/*
Ler um número e apresentar o seu módulo (número sem sinal), isto é, se o número é negativo apresentá-lo como
positivo.
*/
int main (void)
{
    float Num,Num2;
    char Continuar;
    do
    {
        system("cls");
        printf("\n________________________________________________________________________________\n");
        printf("Informe um Numero: ");
        scanf("%f",&Num);

        system("cls");

        if(Num < 0)
        {
            Num2 = Num*-1;
            printf("\nO Numero positivo sera: %.2f",Num2);
        }
        else
        {
            printf("\nO Numero positivo sera: %.2f",Num);
        }



        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');

}
