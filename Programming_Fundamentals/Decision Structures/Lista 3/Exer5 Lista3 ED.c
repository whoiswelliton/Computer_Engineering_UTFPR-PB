#include <stdio.h>
#include <stdlib.h>
/*
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
b) menor que 10, mostrar a divisão real (float) do mesmo por 3.
*/
int main (void)
{
    int Num,Dezenas,Div;
    float Dezenas2;

    printf("Informe um numero com mais de 2 digitos: ");
    scanf("%d",&Num);

    if(Num % 2 == 0)
    {
        Dezenas = (int)Num/10;
        printf("%d Dezenas\n",Dezenas);


        Dezenas2 = Num/10;
        Div = Dezenas2 % 3;
        printf("Parte inteira: %f\n",Div);


    }





    system("pause");
}
