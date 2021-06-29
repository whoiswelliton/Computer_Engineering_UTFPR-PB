#include <stdio.h>
#include <stdlib.h>

/*
Fazer um programa que faça o levantamento dos candidatos que se inscreveram em uma empresa.
Considerando que para cada candidato a empresa tenha obtido as seguintes informações:
	. idade
	. sexo (M ou F)
	. possui curso superior (S ou N)
	Faça um programa para determinar:
a) a quantidade de candidatos;
b) a quantidade de candidatas;
c) a idade média dos homens sem curso superior;
d) a menor idade entre as mulheres com curso superior;
Estabelecer uma condição para finalizar a entrada de dados do programa. Por exemplo, idade negativa.
Se idade negativa não ler as informações de sexo e se possui curso superior.
*/
int main (void)
{
    int Qcm,Qcf,Idade,IDmedia,Menor,Soma;
    char Continuar,Sexo,Curso;
    do
    {
        system("cls");

        do
        {
            printf("\n_____________________________________________________________________________________\n");
            printf("Informe a sua Idade: ");
            scanf("%d",&Idade);
            system("cls");

            do
            {
                printf("\n_____________________________________________________________________________________\n");
                printf("Informe seu Sexo (M/m ou F/f): ");
                scanf("%c",&Sexo);
                system("cls");

                if(Sexo == 'M' || Sexo == 'm')
                {
                    Qcm++;
                }

                if(Sexo == 'F' || Sexo == 'f')
                {
                    Qcf++;
                }

                do
                {
                    printf("\n_____________________________________________________________________________________\n");
                    printf("Tem Curso Superior Comleto (S/s uo N/n): ");
                    scanf("%c",&Curso);
                    system("cls");

                    if(Sexo == 'M' || Sexo == 'm' && Curso == 'N' || Curso == 'n')
                    {

                    }

                    if(Sexo == 'F' || Sexo == 'f' && Curso == 'S' || Curso == 's')
                    {
                        Idade = Menor;


                    }


                }while(Curso != 'S' || Curso != 's' ||Curso != 'N' ||Curso != 'n')

            }while(Sexo != 'M' ||Sexo != 'm' ||Sexo != 'F' ||Sexo != 'f')

        }while(Idade < 18 && Idade > 100)

        printf("_____________________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');

}
