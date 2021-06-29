#include <stdio.h>
#include <stdlib.h>

/*
Faça um algoritmo que leia as 3 notas de um aluno e calcule a sua média ponderada, com os pesos: 2, 3 e 5, respectivamente. E:
a) Se a média obtida está entre 6 a 10 informar que o aluno está aprovado;
b) Se a média obtida está entre 4 e 5.9 informar que o aluno está em recuperação. Nesse caso, ler a nota de recuperação e calcular a média final
(que é a média entre a média anual e a nota de recuperação).
	b.1) Se a média final é menor que 5 informar que o aluno está reprovado após recuperação;
	b.2) Se é igual ou maior que 5 informar que o aluno está aprovado após recuperação;
c) Se a média obtida é menor que 4 informar que o aluno está reprovado antes da recuperação.
*/
int main (void)
{
    float Nota1,Nota2,Nota3,Media,Nota4,MF2;
    char Continuar;
    do
    {
        system("cls");
        printf("\n_______________________________________________________________________________\n");
        printf("Informe a primeira Nota: ");
        scanf("%f",&Nota1);
        printf("\n________________________________________________________________________________\n");
        printf("Informe a segunda Nota: ");
        scanf("%f",&Nota2);
        printf("\n________________________________________________________________________________\n");
        printf("Informe a terceira Nota: ");
        scanf("%f",&Nota3);

        system("cls");

        Media = ((float)Nota1*2 + Nota2*3 + Nota3*5)/10;

        if(Media >= 6 && Media <= 10)
        {
            printf("\nAluno Aprovado!");
        }
        else if(Media >= 4 && Media <= 5.9)
        {
            printf("\nAluno Em Recuperação!");
            printf("\nInforme a nota de Recuperacao: ");
            scanf("%f",&Nota4);

            MF2 = (Media + Nota4) /2;

            if(MF2 < 5 && MF2 >= 0)
            {
                printf("\nAluno Reprovado apos a Recuperacao");
            }
            else if(MF2 >= 5 && MF2 <= 10)
            {
                printf("\nAluno Aprovado apos Recuperacao");
            }

        }
        else
        {
            printf("\nALUNO REPROVADO!");
        }

        printf("\n\n________________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
