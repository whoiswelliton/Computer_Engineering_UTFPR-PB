#include <stdio.h>
#include <stdlib.h>
/*
Construir um programa que determine para uma turma de n alunos:
	a) a idade média dos alunos com altura menor que 1,65 metros;
	b) o percentual de pessoas do sexo feminino;
	c) a altura média dos alunos com menos que 18 anos.
	O valor n pode ser informado pelo usuário, assim seriam iterações contadas, ou pode ser estabelecida
	 uma condição para finalizar, por exemplo, um número negativo para a idade.
*/
int main (void)
{
    int Alunos,Imedia,Amedia,Cont,Altura,Idade;
    char Sexo;
    float Perc;
    int qtdef=0,qtmenor=0,SomaA=0;

    printf("Informe o Numero de Alunos: ");
    scanf("%d",&Alunos);

    for(Cont=1;Cont<Alunos;Cont++)
    {
        printf("Informe a altura: ");
        scanf("%d",&Altura);
        printf("Informe a Idade: ");
        scanf("%d",&Idade);
        printf("Informe o Sexo: ");
        fflush(stdin);
        scanf("%c",&Sexo);

        if(Altura<1.65)
        {
            Imedia+=Cont;
        }
        if(Sexo == 'F' || Sexo == 'f')
        {
            qtdef++;
        }
        if (Idade<18)
        {
            qtmenor++;
            SomaA+=Altura;
        }


    }

    Total = 100%
    Perc = (qtdef*100/Alunos)
    Imedia=


    printf("A idade media dos alunos menores que 1.65 : %d",Imedia);

    system("pause");
}
