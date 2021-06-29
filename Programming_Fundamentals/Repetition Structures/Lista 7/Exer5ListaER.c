#include <stdio.h>
#include <stdlib.h>
/*
5) Escreva um programa que leia o valor de uma aplicação, o percentual de rendimento mensal obtido por esta
aplicação e o período do investimento; e retorne o valor da aplicação ao final do período de investimento.
Obs.: a cada 12 meses o percentual de rendimento deve ser aumentado em 0,25%.
*/
int main (void)
{
    char Continuar;
    float Ap,Apf,Percen;
    int Periodo,Qtperiodo,Cont;

    do
    {
        system("cls");
        Qtperiodo=0;


            printf("Informe o valor da aplicacao: ");
            scanf("%f",&Ap);
            printf("Informe o valor do percentual de rendimento mensal: ");
            scanf("%f",&Percen);
            printf("Informe em meses o periodo do investimento: ");
            scanf("%d",&Periodo);

            for(Cont=1;Cont<=Periodo;Cont++)
            {

                if(Cont % 12 == 0)
                {
                   Percen = Percen + (Percen* 0.25);
                }

                Ap = Ap + (Ap*Percen/100);
            }



        printf("O valor da aplicacao final e: %f \n",Ap);

        printf("\nExecutar novamente (S/s para sim): ");
        getchar();
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');



    system("pause");
}
