#include <stdio.h>
#include <stdlib.h>


/*
Ler um número e imprimir todos os números pares entre 1 e o número lido. Imprimir a soma dos pares,
o produto dos ímpares e divisíveis por 9 e a média de todos os números do intervalo.
Validar para que não seja realizada uma divisão por zero.
*/
int main (void)
{
    float Num,Cont,SomaPares,Qtd,Somatodos,Prodimp;
    float Media;
    char Continuar;
    do
    {
        system("cls");
        printf("\n________________________________________________________________________________\n");
        printf("Informe um Numero: ");
        scanf("%d",&Num);

        system("cls");

        for(Cont=1;Cont<=Num;Cont++)
        {
            if(Cont % 2 == 0)
            {
                printf("%.2f\t",Cont);
                SomaPares = SomaPares + Cont;
            }
            else if(Cont % 2 != 0 && Cont % 9 == 0)
            {
                Prodimp = Prodimp * Cont;
            }
            Somatodos = Somatodos + Cont;
            Qtd++;
        }

        if(Prodimp > 1)
        {
            printf("\nProduto dos impares dividido por 9: %d\n",Prodimp);
        }
        if(Qtd != 0)
        {
            Media=  (float)Somatodos/Qtd;
            printf("\nMedia: %.2f",Media);
        }
        printf("\nSoma dos pares: %.0f\n",SomaPares);

        printf("\n________________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
