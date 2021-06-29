#include <stdio.h>
#include <stdlib.h>

/*
 Um determinado material radioativo perde metade de sua massa a cada 50 segundos.  Dada a massa inicial,
 em gramas, fazer um programa que determine o tempo necessário para que essa massa se torne menor que 0,05
 gramas. Escreva a massa inicial, a massa final e o tempo calculado em horas, minutos e segundos. A massa
 inicial informada pelo usuário tem que ser maior que zero. Validar essa entrada, isto é, ficar repetindo
 a leitura da massa inicial até que o usuário informe um valor válido, ou seja, maior que zero.
*/
int main (void)
{
    float Massa,Seg,H,M,S;
    int Qtd=0;
    char Continuar;
    do
    {
        system("cls");

        do
        {
            printf("\n_______________________________________________________________________________\n");
            printf("Informe a massa: ");
            scanf("%f",&Massa);
            if(Massa < 0)
            {
                printf("Informe um valor positivo.");
            }

        }while(Massa < 0);


        do
        {
            Massa = (float)Massa/2;
            Qtd++;

        }while(Massa > 0.05);

        Seg = Qtd*50;

        H= (int)Seg/3600;
        M= (int)Seg%3600/60;
        S= (int)Seg%60;

        printf("O Processo demorou %.0f Horas, %.0f Minutos e %.f Segundos",H,M,S);

        printf("\n______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
