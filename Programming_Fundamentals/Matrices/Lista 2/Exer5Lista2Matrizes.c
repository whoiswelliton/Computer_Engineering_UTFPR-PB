#include <stdio.h>
#include <stdlib.h>

/*
*/
int main (void)
{
    int Matriz[100][10],i,j,Gabarito[5],Acertos[100];

    char Continuar;
    do
    {
        system("cls");

        for(i=0;i<100;i++)
        {
            Acertos[i]=0;
        }

        Gabarito[0]=1;
        Gabarito[1]=2;
        Gabarito[2]=3;
        Gabarito[3]=4;
        Gabarito[4]=5;
        Gabarito[5]=6;
        Gabarito[6]=7;
        Gabarito[7]=8;
        Gabarito[8]=9;
        Gabarito[9]=10;


        printf("________________________________________________________________________________\n");
        printf("Alunis e suas notis - CASSILDIS\n\n");
        for(i=0;i<100;i++)
        {
            for(j=0;j<10;j++)
            {
                Matriz[i][j] = rand() % (10+1);
                printf("%5d",Matriz[i][j]);

                if(Matriz[i][j] == Gabarito[j])
                {
                    Acertos[i]++;
                }
            }
            printf("  Acertos = %d\n",Acertos[i]);

        }




        printf("________________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
