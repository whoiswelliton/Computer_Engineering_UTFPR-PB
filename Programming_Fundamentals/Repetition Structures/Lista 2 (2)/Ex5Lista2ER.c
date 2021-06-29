#include <stdio.h>
#include <stdlib.h>

/*
Apresentar os números divisíveis por 4 ou múltiplos de 10 entre 500 e 0 e a média desses múltiplos.
*/
int main (void)
{
    int Cont,mult,Soma,Qtd=0;
    float Media;
    char Continuar;
    do
    {
        system("cls");
        printf("\n______________________________________________________________________________\n");

        for(Cont=0;Cont<=500;Cont++)
        {
            if(Cont % 4 == 0 || Cont % 10 == 0)
            {
                Soma = Soma + Cont;
                Qtd++;
                printf("%d\t",Cont);
            }
        }
        if(Qtd > 0)
        {
            Media = (float)Soma/Qtd;
            printf("\nA Media dos numeros: %.1f",Media);
        }


        printf("\n_______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
