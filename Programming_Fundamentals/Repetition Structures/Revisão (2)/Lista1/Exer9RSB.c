#include <stdio.h>
#include <stdlib.h>
/*
Ler dois valores que representam os limites de um intervalo. Percorrer esse intervalo em ordem decrescente.
O usuário pode informar os valores em ordem crescente ou decrescente. Mostrar os valores com x números por linha.
X é informado pelo usuário.
*/
int main (void)
{
    int Lim1,Lim2,Cont,Linhas,Qtlinhas=0;

    printf("Informe o primeiro limite : ");
    scanf("%d",&Lim1);
    printf("Informe o segundo limite : ");
    scanf("%d",&Lim2);
    printf("Informe Quantas linhas para o resultado: ");
    scanf("%d",&Linhas);

    if(Lim1 < Lim2)
    {
        Cont = Lim1;
        Lim1 = Lim2;
        Lim2 = Cont;
    }
    printf("Valores do Intervalo: \n");
    for(Cont=Lim1;Cont>=Lim2;Cont--)
    {
        Qtlinhas++;
        printf(" %d\t",Cont);
        if(Qtlinhas % Linhas == 0)
        {
            printf("\n");
        }

    }
    system("pause");
}
