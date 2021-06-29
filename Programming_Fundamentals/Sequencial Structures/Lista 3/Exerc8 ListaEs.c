#include <stdio.h>
#include <stdlib.h>
/*
Leia um número do tipo float. Obtenha e mostre o resto da divisão da parte inteira desse número por
cinco. A parte decimal multiplique-a por 10 e em seguida mostre o resto da divisão desse número por 3.
Exemplo: Informado: 11.756
	Inteiro: 11
	Resto da dividido por 5: 1
	Parte decimal: 0.756
Parte decimal multiplicada por 10: 7
	Resto da divisão por 3 da parte decimal multiplicada por 10: 1

*/
int main (void)
{
    float Num, Dnum, DnumM10, Dnum3;
    int Inum, Inum5;

    printf("Informe o valor desejado: ");
    scanf("%f",&Num);

    Inum = (int)Num;
    Inum5 = Inum%5;
    Dnum = Num-Inum;
    DnumM10 = Dnum*10;
    Dnum3 = (int)DnumM10%3;


    printf("Informado: %f\n",Num);
	printf("Inteiro: %d\n",Inum);
	printf("Resto da dividido por 5: %d\n",Inum5);
	printf("Parte decimal: %f\n",Dnum);
    printf("Parte decimal multiplicada por 10: %f\n",DnumM10);
	printf("Resto da divisão por 3 da parte decimal multiplicada por 10: %f\n",Dnum3);

    system("pause");
}
