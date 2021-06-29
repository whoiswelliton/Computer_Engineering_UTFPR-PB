#include <stdio.h>
#include <stdlib.h>

/*
Ler dois números que representam os limites de um intervalo. Mostrar os pares e divisíveis por três
desse intervalo, em ordem decrescente e em colunas (n números por linha separados por tabulação).
n é informado pelo usuário e deve ser validado para obter uma entrada positiva. Calcular e mostrar
a média dos ímpares e não divisíveis por 7 desse intervalo. Validar para que não seja realizada
uma divisão por zero.
*/
int main (void)
{
    int Lim1,Lim2,Aux=0,N,Cont,Qtd=0,Qtd2=0,Soma;
    float Media;
    char Continuar;
    do
    {
        system("cls");
        printf("\n________________________________________________________________________________\n");
        printf("Informe o primeiro limite: ");
        scanf("%d",&Lim1);
        printf("\n________________________________________________________________________________\n");
        printf("Informe o segundo limite: ");
        scanf("%d",&Lim2);
        printf("\n________________________________________________________________________________\n");
        printf("Informe a quantidade de colunas do resultado: ");
        scanf("%d",&N);

        if(Lim1 < Lim2)
        {
            Aux = Lim1;
            Lim1 = Lim2;
            Lim2 = Aux;
        }

        system("cls");
        printf("\n\nPares e divisiveis por tres desse intervalo:\n");
        for(Cont=Lim1;Cont>=Lim2;Cont--)
        {
            if(Cont %  2 == 0 && Cont % 3 == 0)
            {
                printf("%d\t",Cont);
                Qtd++;
            }
            if(N % Qtd == 0)
            {
                printf("\n");
            }

            if(Cont % 2 != 0 && Cont % 7 != 0)
            {
                Soma = Soma + Cont;
                Qtd2++;
            }
        }
        if(Qtd > 0)
        {
            Media = (float)Soma/Qtd;
            printf("\n\nMedia dos impares e não divisiveis por 7 desse intervalo: %.2f",Media);
        }

        printf("\n________________________________________________________________________________\n\n");
        printf("\n                           Executar Novamente (S/s para Sim): ");
        fflush(stdin);
        scanf("%c",&Continuar);

    }while(Continuar == 's' || Continuar == 'S');

}
