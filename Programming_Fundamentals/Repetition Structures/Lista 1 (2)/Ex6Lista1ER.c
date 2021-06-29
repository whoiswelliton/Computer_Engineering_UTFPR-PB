#include <stdio.h>
#include <stdlib.h>

/*
Ler dois números que representam os limites de um intervalo e ler o incremento.
Mostrar os números desse intervalo de acordo com o incremento indicado.
O usuário pode informar os valores que representam os limites do intervalo em ordem crescente ou decrescente.
*/
int main (void)
{
    float Cont,Lim1,Lim2,Inc;

    char Continuar;
    do
    {
        system("cls");
        printf("\n________________________________________________________________________________\n");
        printf("Informe o primeiro limite: ");
        scanf("%f",&Lim1);
        printf("Informe o segundo limite: ");
        scanf("%f",&Lim2);
        printf("Informe o incremento: ");
        scanf("%f",&Inc);

        system("cls");

        if(Lim1 < Lim2)
        {
            for(Cont=Lim1;Cont<=Lim2;Cont=Cont+Inc)
            {
                printf("%.1f\t",Cont);
            }
        }
        else
        {
            for(Cont=Lim2;Cont<=Lim1;Cont=Cont+Inc)
            {
                printf("%.1f\t",Cont);
            }
        }

        printf("\n________________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
