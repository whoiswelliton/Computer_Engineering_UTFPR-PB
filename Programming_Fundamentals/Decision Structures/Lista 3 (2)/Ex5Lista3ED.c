#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/*
Ler um número inteiro.
Se o número lido é par:
a) Obter e mostrar a quantidade de dezenas que esse número possui.
b) Dividir o resto, retiradas as dezenas, por 3 e mostrar somente a parte inteira do resultado dessa divisão.
c) Somar os dígitos do número lido e mostrar.
Por exemplo:
Informado: 125
Dezenas: 12
Divisão: 5 (o resto) dividido por 3
Parte inteira: 2
Soma dos dígitos de 125: 8 (1+2+5)
Se o número lido é impar, verificar se o mesmo é:
	a) maior que 10, se for mostrar a sua raiz quadrada;
b) menor ou igual a 10, mostrar a divisão real (float) do mesmo por 3.

*/
int main (void)
{
    float Num,dez,inteira,Soma,D,C,U,raiz,div;
    char Continuar;
    do
    {
        system("cls");
        printf("\n_______________________________________________________________________________\n");
        printf("Informe um Numero com ate 3 digitos: ");
        scanf("%f",&Num);

        system("cls");

        if((int)Num % 2 == 0)
        {
            dez = (int)Num % 10;
            inteira = ((int)Num % 10)/ 3;
            C = (int)Num/100;
            D = (int)Num % 100 / 10;
            U = (int)Num % 10;
            Soma = C + D + U;

            printf("\nO Numero possui %.0f dezenas\n",dez);
            printf("\nParte inteira do resto, retiradas as dezenas, dividido por 3: %.2f \n",inteira);
            printf("\nSoma dos digitos: %.0f",Soma);
        }
        else
        {
            if(Num <= 10 && Num > 0)
            {
                div = Num/3;
                printf("\nDivisao real por 3 : %.2f");
            }
            else
            {
                raiz = sqrt(Num);
                printf("\nA raiz quadrada do numero e: %.2f",raiz);
            }
        }
        printf("\n_______________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');

}
