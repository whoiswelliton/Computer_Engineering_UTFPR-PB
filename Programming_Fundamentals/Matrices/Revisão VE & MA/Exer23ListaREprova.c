#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

int main (void)
{
    char Continuar;
    float Vet[24],Temp,Maior;
    int i,Cont;

    do
    {
        system("cls");
        srand(time(NULL));

        i=Cont=0;

        printf("Informe uma Temperatura: ");
        scanf("%f",&Temp);

        printf("\n\nTabela de Temperaturas Diarias:\n\n");
        for(i=0;i<24;i++)
        {
            Vet[i] = (rand() %(42 - 34)) + 34;
            printf("%.0f\t",Vet[i]);
        }

        Maior = -1;
        for(i=0;i<24;i++)
        {
            if(Temp <= Vet[i])
            {
                Cont++;
            }

            if(Temp == Vet[i])
            {
                printf("%.0f\t",Vet[i]);
            }

            if (Maior < Vet[i])
            {
                Maior = Vet[i];
            }

            if(Maior > Vet[i])
            {
                 printf(" A maior Temperatura e %.f as %d Horas\n",Maior,i);
            }

        }



        printf("\n\nPara executar novamente: ");
        fflush(stdin);
        scanf("%c",&Continuar);
    }while(Continuar == 's' || Continuar == 'S');

}
