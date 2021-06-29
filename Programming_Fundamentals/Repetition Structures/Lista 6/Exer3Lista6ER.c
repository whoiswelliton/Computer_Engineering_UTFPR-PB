#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    char Continuar;
    int Num,Qtdepositivos,Soma,Qtdepares;
    float Media;

    do
    {
        Soma=0;
        Qtdepositivos=0;
        Qtdepares=0;

        do
        {
            printf("Informe um numero: ");
            scanf("%d",&Num);
            if (Num > 0)
            {
                Qtdepositivos++;
                if(Num % 2 == 0)
                {
                    Soma = Soma + Num;
                    Qtdepares++;
                }

            }

        }while(Qtdepositivos < 10);

        if(Qtdepares > 0)
        {
            Media = (float) Soma/Qtdepares;
            printf("\Media dos pares: %.2f\n",Media);

        }
        printf("\nExecutar novamente (s/S para sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);
    }while(Continuar=='s' || Continuar == 'S');

}
