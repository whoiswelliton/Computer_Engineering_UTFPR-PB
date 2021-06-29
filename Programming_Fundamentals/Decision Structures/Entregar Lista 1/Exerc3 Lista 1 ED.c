#include <stdio.h>
#include <stdlib.h>
/*
Faca um algoritmo / programa em C que leia o sexo, a idade e o tempo de trabalho de uma pessoa e
determine se ela pode se aposentar. Assuma que homens se aposentam com 45 anos de trabalho ou idade
superior a 70 anos, e mulheres de aposentam com 40 anos de trabalho ou idade superior a 65 anos.
*/
int main (void)
{
    char Sexo;
    int Idade,TempoT;

    printf("Informe o Sexo (M/m para masculino e F/f para feminino): ");
    scanf("%c",&Sexo);
    printf("Informe a Idade: ");
    scanf("%d",&Idade);
    printf("Informe o Tempo de Trabalho: ");
    scanf("%d",&TempoT);

    if ((Sexo=='M' || Sexo == 'm') && (Idade >= 70) || (TempoT >= 45))//masculino
    {
         printf("Ja pode se aposentar\n");
    }
    else if ((Sexo=='F' || Sexo == 'f') && (Idade >= 65) || (TempoT >= 40))
    {
         printf("Ja pode se aposentar\n");
    }
    else
    {
         printf("Nao pode se aposentar ainda");
    }

    system("pause");
}
