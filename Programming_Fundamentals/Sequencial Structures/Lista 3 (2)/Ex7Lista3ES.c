#include <stdio.h>
#include <stdlib.h>

/*
Ler um número que representa a quantidade de dias. Informe os anos (com 360 dias), meses (considere-os com 30 dias) e os dias contidos nesse valor.
Exemplo: 390 dias contêm 1 ano(s), 1 mês(es) e 0 dia(s).

*/
int main (void)
{
    char Continuar;
    int Qdias,Dia,Anos,Mes;

    do
    {
        system("cls");
        printf("\n________________________________________________________________________________\n");
        printf("Informe umas Quantidade de dias: ");
        scanf("%d",&Qdias);

        system("cls");

        Anos = Qdias/360;
        Mes = Qdias%360/30;
        Dia = Qdias%30;

        printf("\n%d Dias Contem:",Qdias);
        if(Anos > 0)
        {
            printf("\n%d Ano(s)",Anos);
        }
        if(Mes > 0)
        {
            printf("\n%d Mes(es)",Mes);
        }
        if(Dia)
        {
            printf("\n%d Dia(s)",Dia);
        }

        printf("\n_______________________________________________________________________________\n\n");
        printf("\n                          Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
