#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

int main (void)
{
    int Vet[50],Vet2[50],i,j, Cont;
    char Continuar;

    do
    {
        system("cls");
        i=j=0;

        srand(time(NULL));

        printf("\nVetor gerado:\n");
        for(i=0; i<50; i++)
        {
            Vet[i] = (rand () % (500-100))  +100 ;
            printf("%d\t",Vet[i]);
        }


        printf("\nVetor Nao Repetido:\n");

        for(i=0; i<50; i++)
        {
            Cont=0;
            for(j=0; j<i ; j++)
            {

                if(Vet[i] == Vet[j])
                {
                    Cont++;
                    break;
                }

            }
            if(Cont==0)
            {
                printf("%d\t",Vet[i]);
            }
        }



        printf("\n\nPara executar novamente: ");
        fflush(stdin);
        scanf("%c",&Continuar);
    }
    while(Continuar == 's' || Continuar == 'S');

}
