#include <stdio.h>
#include <stdlib.h>
/*
Ler dois valores que representam os limites de um intervalo. Percorrer o intervalo em ordem crescente.
Apresentar os pares com x valores por linha e calcular a média dos pares e não divisíveis por 5 e divisíveis por 3 desse intervalo.
*/
int main (void)
{
    int Cont,Lim1,Lim2,Pares=0,Linhas,Qtlinhas=0;
    float Media;

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
    for(Cont=Lim2;Cont<=Lim1;Cont++)
    {
        Qtlinhas++;
        printf(" %d\t",Cont);
        if(Qtlinhas % Linhas == 0)
        {
            printf("\n");
        }
        if(Cont %2 == 0 && Cont % 5 != 0 && Cont % 3 == 0)
        {
            Pares++;
        }
    }
    if(Pares > 0)
    {
        Media = (float)Cont / Pares;
        printf("Media dos Pares nao divisiveis por 5 e divisivei por 3: %.2f \n\n",Media);
    }

    system("pause");
}
