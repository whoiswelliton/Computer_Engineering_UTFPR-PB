#include <stdio.h>
#include <stdlib.h>
/*Elaborar um programa para subtrair duas datas, subtrair da data mais recente a mais antiga.
Apresentar o resultado, a diferença, em anos, meses e dias. O usuário pode informar as datas
em ordem crescente ou decrescente, caberá ao programa fazer a verificação. Considere que os
meses possuem 30 dias. Para ler um valor no formato data armazenando-o em três variáveis distintas
é possível utilizar o scanf com a seguinte sintaxe:
	scanf(“%d/%d/%d”,&dia,&mês,&ano);  Observar a barra entre o 1º e o 2º e entre o 2º e o 3º
	símbolos de %
	O usuário digitará a data no formato: 12/12/2008, incluindo as barras, e cada variável terá
	o seu respectivo valor armazenado.
*/
int main (void)
{
    int dia2,mes2,ano2,dia,mes,ano,data1,data2,dife;

    printf("Informe a primeira data - dd/mm/aaaa: ");
    scanf("%d/%d/%d",&dia,&mes,&ano);
    printf("Informe a segunda data -dd/mm/aaaa: ");
    scanf("%d/%d/%d",&dia2,&mes2,&ano2);

    data1= dia+(mes*30)+(ano*360);
    data2= dia2+(mes2*30)+(ano2*360);

    if(data1 > data2)
    {
        dife = data1 - data2;
    }
    else
    {
        dife = data2 - data1;
    }

    ano = dife/360;
    mes = dife%360/30;
    dia = dife%30;

    printf("A diferenca sera de: %d/%d/%d\n ",dia,mes,ano);


    system ("pause");
}
