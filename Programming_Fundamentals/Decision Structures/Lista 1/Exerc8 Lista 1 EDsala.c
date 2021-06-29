#include <stdio.h>
#include <stdlib.h>
/*Faça um algoritmo que leia as 3 notas de um aluno e calcule a sua média ponderada, com os pesos:
 2, 3 e 5, respectivamente. E:
a) Se a média obtida está entre 6 a 10 informar que o aluno está aprovado;
b) Se a média obtida está entre 4 e 5.9 informar que o aluno está em recuperação. Nesse caso,
ler a nota de recuperação e calcular a média final (que é a média entre a média anual e a nota de
 recuperação).
	b.1) Se a média final é menor que 5 informar que o aluno está reprovado após recuperação;
	b.2) Se é igual ou maior que 5 informar que o aluno está aprovado após recuperação;
c) Se a média obtida é menor que 4 informar que o aluno está reprovado antes da recuperação.
*/
int main (void)
{
    int Nota1,Nota2,Nota3;
    int NotaRec;
    float Media,MediaF;

    printf("Informe a primeira nota: ");
    scanf("%d",&Nota1);
    printf("Informe a segunda nota: ");
    scanf("%d",&Nota2);
    printf("Informe a terceira nota: ");
    scanf("%d",&Nota3);

    Media = ((float)Nota1*2 + Nota2*3 + Nota3*5)/10;

    if (Media >= 6)
    {
        printf("Aprovado\n");
    }
    else if (Media >=4 && Media <=6)
    {
        printf("Em Recuperação\n");
        printf("Informe a nota da recuperação: ");
        scanf("%d",&NotaRec);
        MediaF = (Media + NotaRec)/2;

        if (MediaF >= 5)
        {
            printf("Aprovado apos recuperacao\n");
        }
        else
        {
            printf("Reprovado apos recuperacao\n");
        }
    }
    else
    {
        printf("Reprovado\n");
    }

    system("pause");
}
