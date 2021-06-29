#include <stdio.h>
#include <stdlib.h>

/*
Uma pessoa aplicou R$ 100,00 com rendimento de 5% ao mês. Quantos meses serão necessários para que o
capital investido ultrapasse a R$ 200,00.
*/
int main (void)
{
    int Qtd=0;
    float Apli = 100,Rend;
    char Continuar;
    do
    {
        system("cls");
        do
        {
            Apli = Apli + (100*5/100);
            Qtd++;
        }while(Apli < 200);

        printf("\nDemorou %d meses para que ultrapasse 200 reais",Qtd);


        printf("\n____________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
