#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

int main (void)
{
    int Vet[10],Vet2[10],i,j,k,Maior, Save;
    char Continuar;

    do
    {
        system("cls");
        i=j=0;

        srand(time(NULL));

        printf("\nVetor gerado:\n");
        for(i=0; i<10; i++)
        {
            Vet[i] = rand () % 25;
            printf("%d\t",Vet[i]);
        }

        Vet[i] = Vet[j];

        printf("\nVetor em ordem Crescente:\n");
        for(i=0; i<10; i++)
        {
           // Maior=-1;

            for(j=0; j<10-1; j++)
            {
                /*printf("\n");
                for(k=0;k<10;k++) printf("%d ",Vet[k]);*/

                if(Vet[j] > Vet[j+1])
                {
                    Save = Vet[j];
                    Vet[j] = Vet[j+1];
                    Vet[j+1] = Save;
                }
            }
        }

        for(i=0;i<10;i++) printf("%d ",Vet[i]);







        printf("\n\nPara executar novamente: ");
        fflush(stdin);
        scanf("%c",&Continuar);
    }
    while(Continuar == 's' || Continuar == 'S');

}
