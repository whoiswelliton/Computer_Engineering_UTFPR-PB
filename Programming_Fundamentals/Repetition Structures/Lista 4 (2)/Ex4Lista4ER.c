#include <stdio.h>
#include <stdlib.h>

/*
Elaborar um programa que leia os limites inferior e superior de um intervalo e imprimir todos os
números pares no intervalo e a soma de todos os valores do intervalo. Imprimir o intervalo do valor
maior para o menor. O usuário pode informar os valores em qualquer ordem, ou seja, não
necessariamente primeiro o menor ou o maior.
*/
int main (void)
{
    int Lim1,Lim2,Soma=0,Cont;
    char Continuar;
    do
    {
        system("cls");
        printf("\n______________________________________________________________________________\n");
        printf("Informe o Primeiro Limite: ");
        scanf("%d",&Lim1);
        printf("\n______________________________________________________________________________\n");
        printf("Informe o Segundo Limite: ");
        scanf("%d",&Lim2);

        if(Lim1 > Lim2)
        {
            Cont = Lim1;
            Lim1 = Lim2;
            Lim2 = Cont;
        }
        printf("\nPares: ");
        for(Cont=Lim2;Cont>=Lim1;Cont--)//ordem decrescente
        {
            if(Cont % 2 == 0)
            {
                printf("%d\t",Cont);
            }
            Soma = Soma + Cont;
        }
        printf("\n\nA Soma de todos os valores do intervalo: %d ",Soma);

        printf("\n_______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
