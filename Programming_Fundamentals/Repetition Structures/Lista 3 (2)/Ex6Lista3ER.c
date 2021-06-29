#include <stdio.h>
#include <stdlib.h>

/*
Apresentar todos os valores inteiros entre dois valores informados pelo usuário,
a quantidade existentes nesse intervalo, a soma dos ímpares e a média de todos os valores.
O usuário pode informar os valores em ordem crescente ou decrescente. Encontrar o maior e o
menor antes de percorrer o intervalo. Validar para que não seja realizada uma divisão por zero
no cálculo da média.
*/
int main (void)
{
    int Qtd=0,Cont;
    float Media,Soma,Soma2;
    int Lim1,Lim2;
    char Continuar;
    do
    {
        system("cls");
        printf("\n______________________________________________________________________________\n");
        printf("Informe o Primeiro valor do Intervalo: ");
        scanf("%d",&Lim1);
        printf("\n_____________________________________________________________________________\n");
        printf("Informe o Segundo valor do Intervalo: ");
        scanf("%d",&Lim2);

        system("cls");

        if(Lim1 > Lim2)
        {
            Cont = Lim1;
            Lim1 = Lim2;
            Lim2 = Cont;
        }

        printf("\nInteiros: ");
        for(Cont=Lim1;Cont<=Lim2;Cont++)
        {
            printf("%d\t",Cont);
            if(Cont % 2 != 0)
            {
                Soma = Soma + Cont;
            }

            Soma2 = Soma2 + Cont;
            Qtd++;
        }

        printf("\nSoma dos impares: %.2f",Soma);
        printf("\n%d Numeros existentes nesse Intervalo",Qtd);

        if(Qtd > 0)
        {
            Media = (float)Soma2/Qtd;
            printf("Media de todo do intervalo: %.2f",Media);
        }

        printf("\n______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
