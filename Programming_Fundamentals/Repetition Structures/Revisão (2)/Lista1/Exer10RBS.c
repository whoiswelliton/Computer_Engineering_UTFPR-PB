#include <stdio.h>
#include <stdlib.h>
/*
Ler caracteres. Prosseguir a leitura até ser informado o caractere '0'. Calcular o percentual de 'C' ou 'c' e de 'A' ou 'a'
 informados.
*/
int main (void)
{
    char Letras;
    float Percent;
    int Total,AouC;

    do
    {

        printf("Informe uma Letra: ");
        scanf("%c",&Letras);
        Total++;
        getchar();
        if(Letras == 'C'||Letras =='c'||Letras =='A'||Letras =='a')
        {
            AouC++;
        }
    }while(Letras != '0');

    Percent=AouC*100.0/Total;

    printf("O Percentual total é: %.2f%% \n",Percent);

    system("pause");
}

