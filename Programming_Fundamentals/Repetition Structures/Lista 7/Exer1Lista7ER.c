#include <stdio.h>
#include <stdlib.h>
/*
Um determinado material radioativo perde metade de sua massa a cada 50 segundos.  Dada a massa inicial, em gramas,
fazer um programa que determine o tempo necessário para que essa massa se torne menor que 0,5 gramas.
 Escreva a massa inicial, a massa final e o tempo calculado em horas, minutos e segundos. A massa inicial
 informada pelo usuário tem que ser maior que zero. Validar essa entrada, isto é, ficar repetindo a leitura
 da massa inicial até que o usuário informe um valor válido, ou seja, maior que zero.
*/
int main (void)
{
    char Continuar;
    float MI,MF;
    int Tempo,H,M,S;

    do
    {
        system("cls");//limpar a tela
        Tempo=0;

        do
        {
            printf("Informe Massa inicial: ");
            scanf("%f",&MI);
            if(MI<0)
            {
                printf("Massa deve ser positiva.\n");
            }

        }while(MI < 0);

        MF=MI;

        do
        {
            MI=MI/2;
            Tempo+=50;

        }while(MI>0.5);

        H = Tempo/3600;
        M = Tempo % 3600/60;
        S = Tempo % 60;

        printf("Para que %f se transforme em %f \n",MI,MF);
        printf("Serao necessarios %d Horas, %d Minutos e %d Segundos\n",H,M,S);
        printf("\n Executar novamente (S/s para sim): ");
        getchar();//funcao que le um char
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');


    system("pause");
}
