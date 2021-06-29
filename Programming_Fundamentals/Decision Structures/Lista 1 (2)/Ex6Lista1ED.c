#include <stdio.h>
#include <stdlib.h>

/*
Elaborar um algoritmo que lê um valor que se refere a altura de uma pessoa e mostra uma mensagem conforme a faixa de altura. Utilizar variável do tipo double:
*/
int main (void)
{
    float Altura;
    char Continuar;
    do
    {
        system("cls");
        printf("\n_______________________________________________________________________________\n");
        printf("Informe um Altura de uma Pessoa: ");
        scanf("%f",&Altura);

        system("cls");

        if(Altura < 1.50 && Altura > 0)
        {
            printf("\nAbaixo de um metro e meio");
        }
        else if(Altura >= 1.50 && Altura <= 1.80)
        {
            printf("\nEntre um metro e meio e um metro e oitenta centimetros");
        }
        else
        {
            printf("\nAcima de um metro e oitenta centimetros");
        }

        printf("\n\n________________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');

}
