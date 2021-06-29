#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    char Continuar;
    int LimSup;
    int LimInf;
    int Cont;
    int Soma;
    int Qtde;
    float Media;
    int Valoresmostrados;

    do//repetir um programa
    {
        Soma = 0;
        Qtde = 0;
        Valoresmostrados=0;

        printf("informe o limite superior: ");
        scanf("%d",&LimSup);
        printf("informe o limite inferior: ");
        scanf("%d",&LimInf);

        if(LimSup < LimInf)
        {
            Cont = LimSup;
            LimSup = LimInf;
            LimInf = Cont;
        }

        for(Cont=LimSup;Cont>=LimInf;Cont--)
        {
            printf("%d\t",Cont);
            Valoresmostrados++;
            if(Valoresmostrados % 8 ==0)
            {
                printf("\n");
            }
            if (Cont % 3 == 0 && Cont % 5 == 0)
            {
                Soma = Soma + Cont;
                Qtde++;
            }
        }
        if (Qtde > 0)
        {
            Media = (float) Soma / Qtde;
            printf("\nMedia: %.2f\n",Media);
        }

        printf("\nExecutar novamente (s/S para sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 'S' || Continuar == 's');

    printf("pause");
}
