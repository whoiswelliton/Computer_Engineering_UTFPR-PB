#include <stdio.h>
#include <stdlib.h>

/*Escrever um programa que leia vários números inteiros. O valor informado 0 indica o final da leitura.
No final imprimir a média dos números múltiplos de 3 informados. O valor que indica o final da leitura
não deve ser considerado. Validar para que não seja realizada uma divisão por zero.
*/
int main (void)
{
    int Soma=0;
    int Qtd=0;
    float Media;
    int Num;
    char Continuar;
    do
    {
        system("cls");
        printf("\n_____________________________________________________________________________\n");
        system("cls");
        while(Num != 0)
        {
            printf("\n_____________________________________________________________________________\n");
            printf("\nInforme um Numero: ");
            scanf("%d",&Num);
            system("cls");
            if(Num!= 0)
            {
                if(Num % 3 == 0)
                {
                    Soma = Num + Soma;
                    Qtd++;
                }
            }
        }
        if(Qtd != 0)
        {
            Media = (float)Soma/Qtd;
            printf("\nA Media final = %.1f",Media);
        }

        printf("\n_______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
