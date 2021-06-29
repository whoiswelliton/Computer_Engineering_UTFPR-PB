#include <stdio.h>
#include <stdlib.h>


/*
Ler um número inteiro que representa dias.
a) Obter e mostrar a quantidade de semanas que esse número possui.
b) Multiplicar os dias restantes, retiradas as semanas, por 24 e informar o número de horas obtido.
c) Dividir esse número de horas por 8 e mostrar somente a parte inteira do resultado dessa divisão.
d) Calcular e mostrar o percentual que as horas obtidas representam de uma semana.
e) Somar os dígitos do número lido e mostrar.
Por exemplo:
Informado: 125
Semanas: 17
Horas: 6 (o resto da divisão) multiplicado por 24 = 144
Parte inteira da divisão por 8: 18
144 horas representam 85% de uma semana
Soma dos dígitos do número lido: 8
*/
int main (void)
{

    int Dias;
    float Semanas,Horas,Parte,Perce,Soma,A,B,C,D,X;
    char Continuar;
    do
    {
        system("cls");
        printf("\n_______________________________________________________________________________\n");
        printf("Informe um numero inteiro que represente Dias: ");
        scanf("%d",&Dias);
        printf("________________________________________________________________________________\n");

        Semanas = Dias/7;
        X = Dias % 7;
        Horas = (Dias % 7) * 24;
        Parte = (int)Horas/8;
        Perce = (100*Horas)/168;
        A = (int)Dias/1000;
        B = (int)Dias%1000 / 100;
        C = (int)Dias%100/10;
        D = (int)Dias%10;
        Soma =  A+B+C+D;

        system("cls");

        printf("\n Informado : %d",Dias);
        printf("\n Semanas : %.0f",Semanas);
        printf("\n Horas : %0.f dias restantes = %.0f Horas",X,Horas);
        printf("\n Parte inteira da divisao : %.0f",Parte);
        printf("\n %0.f Horas representam = %.2f %c de uma semana",Horas,Perce,37);
        printf("\n Soma dos digitos: %0.f",Soma);


        printf("\n______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');

}
