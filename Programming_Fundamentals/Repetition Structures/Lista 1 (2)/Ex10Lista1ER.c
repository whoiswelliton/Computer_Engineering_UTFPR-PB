#include <stdio.h>
#include <stdlib.h>

/*
Escrever um programa, que leia valores inteiros até ser lido o valor -99. Após finalizada a leitura imprimir a média dos valores lidos.
*/
int main (void)
{

    int Num,Soma=0,Qtde=0;
    float Media;
    char Continuar;
    do
    {
        system("cls");
        printf("\n____________________________________________________________________________\n");
        printf("Informe um numero: ");
        scanf("%d",&Num);
        system("cls");

        while(Num != -99)
        {
            printf("\n________________________________________________________________________\n");
            printf("\nInforme outro numero: ");
            scanf("%d",&Num);
            system("cls");

            if(Num != -99)
            {
                Soma = Soma + Num;
                Qtde++;
            }
        }

        if(Qtde != 0)
        {
            Media = (float)Soma/Qtde;
        }

        printf("\nMedia dos numeros informados: %.1f ",Media);

        printf("\n______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
