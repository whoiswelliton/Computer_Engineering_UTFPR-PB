#include <stdio.h>
#include <stdlib.h>

/*
Elaborar um programa que efetue a leitura sucessiva de valores numéricos e apresente no final a
soma dos valores informados, a média e o total de valores lidos. O programa deve fazer as leituras
dos valores enquanto o usuário estiver fornecendo valores positivos. Ou seja, o programa deve parar
quando o usuário informar um valor negativo e esse valor não deve ser considerado nos cálculos.
*/
int main (void)
{
    int Soma=0,Num,Qtd=0;
    float Media;
    char Continuar;

    do
    {
        do
        {
            system("cls");
            printf("\n______________________________________________________________________________\n");
            printf("Informe um Numero: ");
            scanf("%d",&Num);
            if(Num > 0)
            {
                Soma = Soma + Num;
                Qtd++;
            }
        }while(Num > 0);

        if(Qtd > 0)
        {
            Media = (float)Soma/Qtd;

            printf("\nA Media total de todos os valores informados %c: %.2f",130,Media);
        }

        printf("\n______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
