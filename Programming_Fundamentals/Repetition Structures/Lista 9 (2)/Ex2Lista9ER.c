#include <stdio.h>
#include <stdlib.h>

/*
Ler a idade, o tipo (E estudante e P professor) de cinco pessoas. Se o tipo for professor solicitar
o salário. Fazer a média dos salários informados. Se o tipo for estudante solicitar se o mesmo
recebe mesada. Contar quantos recebem e quantos não recebem mesada. Garantir que o usuário informe
 uma idade válida, ou seja, positiva, que o tipo seja E ou P e que recebe mesada seja S ou N.
 Validar essas entradas. Isso no sentido de ficar solicitando essas entradas até que sejam válidas.
 Validar para que não seja realizada uma divisão por zero.
*/
int main (void)
{
    float S,S1,Qtd=0,Qtd1=0,Qtd2=0,Qtd3=0,Media;
    int Idade;
    char Continuar,Tipo,M;
    do
    {
        fflush(stdin);
        do
        {
            system("cls");
            do
            {
                printf("\n________________________________________________________________________________\n");
                printf("Informe a Sua Idade: ");
                scanf("%d",&Idade);
                if(Idade < 10 && Idade > 100)
                {
                    printf("\nInforme uma Idade Valida!");
                }

            }while(Idade < 10 && Idade > 100);

            do
            {
                printf("\n________________________________________________________________________________\n");
                printf("Professor ou Estudante (P/p ou E/e): ");
                scanf("%c",&Tipo);

                if(Tipo != 'P' || Tipo != 'p' || Tipo != 'E' || Tipo != 'e')
                {
                    printf("\nInforme uma categoria Valida!");
                }

            }while(Tipo != 'P' || Tipo != 'p' || Tipo != 'E' || Tipo != 'e');


            if(Tipo == 'P' || Tipo == 'p')
            {
                do
                {
                    printf("\n________________________________________________________________________________\n");
                    printf("Informe o seu Salario: ");
                    scanf("%f",&S);
                    if(S < 0)
                    {
                       printf("\nInforme um Salario Positivo!");
                    }

                }while(S < 0);
                Qtd3++;

                S1 = S1 + S;
            }

            else if(Tipo == 'E' || Tipo == 'e')
            {
                do
                {
                    printf("\n________________________________________________________________________________\n");
                    printf("Voce Recebe Mesada (S/s ou N/n): ");
                    scanf("%c",&M);
                    if(M != 'S' || M != 's' || M != 'N' || M != 'n')
                    {
                        printf("\nInforme Um Caractere Valido!");
                    }

                }while(M != 'S' || M != 's' || M != 'N' || M != 'n');


                if(M == 'S' || M == 's')
                {
                    Qtd1++;
                }
                else
                {
                    Qtd2++;
                }
            }
            Qtd++;

        }while(Qtd != 5);

        system("cls");

        if(Qtd > 0)
        {
            Media = (float)S1/Qtd3;
            printf("\nA Media total do salario dos professores e de: %.2f",Media);
        }
        if(Qtd2 > 0 || Qtd1 >0)
        {
            printf("\n %d Alunos recebem Mesada e %d nao recebem",Qtd1,Qtd2);
        }

        printf("_________________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');
}
