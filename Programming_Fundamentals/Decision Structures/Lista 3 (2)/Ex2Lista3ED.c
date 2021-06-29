#include <stdio.h>
#include <stdlib.h>


/*
Elaborar um programa para ler o código de um produto e o classificá-lo de acordo com a tabela a seguir:

código
classificação
1
Alimento não-perecível
2 a 4
Alimento perecível
5 e 6
Vestuário
7
Higiene pessoal
8 a 15
Limpeza e utensílios domésticos
Qualquer outro código (negativo ou positivo)
Inválido

*/
int main (void)
{

    int Codigo;
    char Continuar;
    do
    {
        system("cls");
        printf("\n_______________________________________________________________________________\n");
        printf("\nInforme o codigo do produto: ");
        scanf("%d",&Codigo);

        system("cls");

        if(Codigo == 1)
        {
            printf("\nAlimento Nao-Perecevil");
        }
        else if(Codigo >= 2 && Codigo <= 4)
        {
            printf("\nAlimento Perecivel");
        }
        else if(Codigo >= 5 && Codigo <= 6)
        {
            printf("\nVestuario");
        }
        else if(Codigo == 7)
        {
            printf("\nHigiene Pessoal");
        }
        else if(Codigo >= 8 && Codigo <= 15)
        {
            printf("\nLmipeza e Utensilios Domesticos");
        }
        else
        {
            printf("\nCodigo Invalido!");
        }

        printf("\n_______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
