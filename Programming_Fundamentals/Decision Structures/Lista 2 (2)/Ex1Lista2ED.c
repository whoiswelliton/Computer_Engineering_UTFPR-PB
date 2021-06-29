#include <stdio.h>
#include <stdlib.h>

/*
Ler três valores inteiros, encontrar e mostrar o menor deles.
*/
int main (void)
{
    int N1,N2,N3;
    char Continuar;
    do
    {
        system("cls");
        printf("\n________________________________________________________________________________\n");
        printf("Informe o primeiro valor: ");
        scanf("%d",&N1);
        printf("\n________________________________________________________________________________\n");
        printf("Informe o segundo valor: ");
        scanf("%d",&N2);
        printf("\n________________________________________________________________________________\n");
        printf("Informe o terceiro valor: ");
        scanf("%d",&N3);

        if(N1 < N2 && N1 < N3)
        {
            printf("\nO primeiro valor e menor!");
        }
        else if(N2 < N1 && N2 <N3)
        {
            printf("\nO segundo valor e menor!");
        }
        else
        {
            printf("\nO Terceiro valor e menor!");
        }

        printf("\n\n_______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');

}
