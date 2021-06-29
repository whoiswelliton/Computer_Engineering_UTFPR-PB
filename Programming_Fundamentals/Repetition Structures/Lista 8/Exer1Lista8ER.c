#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
1) Fazer um programa que mostre os números que são quadrados perfeitos entre 1 e o
número informado pelo usuário. Mostrar os resultados em colunas, com n valores por
 linha, também informado pelo usuário. Validar para que ambas as entradas sejam
 valores positivos.
Obs.: Um número é quadrado perfeito se ele possui um número inteiro como raiz
quadrada.
*/
int main (void)
{
    char Continuar;
    int Num,Cont;
    int R,Linhas;
    int Qtm;

    do
    {
        system("cls");
        Qtm=0;

        do
        {
            printf("Informe um numero: ");
            scanf("%d",&Num);
            printf("Informe o numero de colunas desejadas para o resultado: ");
            scanf("%d",&Linhas);


            if(Num < 0)
            {
                printf(" Informe um numero positivo (:b) : ");
            }
        }while(Num < 0);

        printf("Sao quadrados perfeitos os numeros: \n\n");

        for(Cont=1;Cont<=Num;Cont++)
        {
            R=sqrt(Cont);
            if(R*R==Cont)
            {
                Qtm++;
                printf("%d \t",Cont);
                if(Qtm % Linhas == 0)
                {
                    printf("\n");
                }
            }
        }
    printf("\nExecutar Novamente (S/s para sim): ");
    getchar();
    scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');

    system("pause");
}
