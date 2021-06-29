#include <stdio.h>
#include <stdlib.h>


/*
Ler três valores inteiros, encontrar e mostrar o número do meio.
*/
int main (void)
{

    int N1,N2,N3,Menor,Meio,Maior;
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

        if(N1 > N2 && N1 > N3)
        {
            Maior = N1;

            if(N2 > N3)
            {
                Meio = N2;
                Menor = N3;
            }
            else
            {
                Meio = N3;
                Menor = N2;
            }
        }
        else if (N2 > N1 && N2 > N3)
        {
            Maior = N2;

            if(N1 > N3)
            {
                Meio = N1;
                Menor = N3;
            }
            else
            {
                Meio = N3;
                Menor = N1;
            }
        }
        else if (N3 > N1 && N2 < N3)
        {
            Maior = N3;

            if(N2 > N1)
            {
                Meio = N2;
                Menor = N1;
            }
            else
            {
                Meio = N1;
                Menor = N2;
            }

        }

        printf("\n\nEm Ordem Crecente: %d, %d, %d ",Menor,Meio,Maior);

        printf("\n\n________________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');

}
