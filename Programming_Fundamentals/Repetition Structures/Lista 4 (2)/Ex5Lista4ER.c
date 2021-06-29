#include <stdio.h>
#include <stdlib.h>

/*
Construir um programa que determine para uma turma de n alunos:
	a) a idade média dos alunos com altura menor que 1,65 metros;
	b) o percentual de pessoas do sexo feminino;
	c) a altura média dos alunos com menos que 18 anos.
	O valor n pode ser informado pelo usuário, assim seriam iterações contadas, ou pode ser
	estabelecida uma condição para finalizar, por exemplo, um número negativo para a idade.
*/
int main (void)
{
    int N,Qtd1=0,Qtd2=0,Qtd3=0,Qtd4=0,Idade;
    float Altura,Media,Media2,Soma=0,Soma2=0,Perc;
    char Continuar,Sexo;
    do
    {
        system("cls");
        printf("\n________________________________________________________________________________\n");
        printf("Informe a Quantidade de Alunos: ");
        scanf("%d",&N);

        do
        {
            system("cls");
            printf("Informe a Altura do Aluno: ");
            scanf("%f",&Altura);
            printf("Informe o Sexo do mesmo Aluno (M/F): ");
            scanf("%c",&Sexo);
            getchar();
            printf("Informe a Idade do Aluno: ");
            scanf("%d",&Idade);

            if(Altura < 1.65)
            {
                Soma = Soma + Idade;

                Qtd2++;
            }
            if(Sexo == 'F' || Sexo == 'f')
            {
                Qtd3++;
            }
            if(Idade < 18)
            {
                 Soma2 = Soma2 + Idade;

                 Qtd4++;
            }

            Qtd1++;

        }while(Qtd1 != N);

        if(Qtd2 > 0)
        {
            Media = (float)Soma/Qtd3;
            printf("\nA idade media dos alunos com altura menor que 1,65: %.2f",Media);
        }

        if(Qtd3 > 0)
        {
            Perc = (float)(Qtd3*100)/Qtd1;
            printf("\nO percentual de pessoas do sexo feminino: %.2f",Perc);
        }
        if(Qtd4 > 0)
        {
            Media2 = (float)Soma2/Qtd4;
            printf("\nA altura média dos alunos com menos que 18 anos: %.2f",Media2);
        }

        printf("\n________________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
