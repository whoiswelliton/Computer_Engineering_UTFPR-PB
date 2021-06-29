#include <stdio.h>
#include <stdlib.h>

/*
Ler dois números positivos que representam os limites inferior e superior de um intervalo.
Validar a entrada para que sejam informados números positivos. É mais adequado validá-los separadamente.
Fazer a média dos múltiplos de 3 e de 5 desse intervalo. Verificar para que no cálculo da média não seja
feita divisão por zero.
*/
int main (void)
{
    int Lim1,Lim2,Qtd=0,Aux=0,Cont,Soma=0;
    float Media;
    char Continuar;

    do
    {
        system("cls");

        do
        {
            printf("\n________________________________________________________________________________\n");
            printf("Informe o primeiro numero: ");
            scanf("%d",&Lim1);
            if(Lim1 < 0)
            {
                printf("Informe um valor Poisitvo.");
            }
        }while(Lim1 < 0);
        do
        {
            printf("\n________________________________________________________________________________\n");
            printf("Informe o segundo numero: ");
            scanf("%d",&Lim2);
            if(Lim2 < 0)
            {
                printf("Informe um valor Poisitvo.");
            }
        }while(Lim2 < 0);



        if(Lim1 > 0 && Lim2 > 0)
        {
            if(Lim1 > Lim2)
            {
                Aux = Lim1;
                Lim1 = Lim2;
                Lim2 = Aux;

            }
            for(Cont=Lim1;Cont<=Lim2;Cont++)
            {
                if(Cont % 3 == 0 && Cont % 5 == 0)
                {
                    Soma = Soma + Cont;
                    Qtd++;
                }
            }

        }
        else
        {
            printf("\nInforme valores positivos para os limites.");
        }

        if(Qtd > 0)
        {
            Media = (float)Soma/Qtd;
            printf("\n\nA Media dos divisores de 3 e 5 = %.2f",Media);
        }

        printf("\n_______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
