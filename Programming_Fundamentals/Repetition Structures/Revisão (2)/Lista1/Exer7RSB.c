#include <stdio.h>
#include <stdlib.h>
/*
Ler caracteres e contar quantos são vogais minúsculas. O programa é finalizado quando o usuário informar '0'
(zero).
*/
int main (void)
{
    int Cont=0;
    char Vogais=0;

    do
    {
        printf("Informe somente Vogais: ");
        scanf("%c",&Vogais);

        if(Vogais == 'a'||Vogais =='e'||Vogais =='i'||Vogais =='o'||Vogais =='u')
        {
            Cont++;
        }
        fflush(stdin);

    }while(Vogais != '0');

    printf("\n Total de vogais: ³%d³ ",Cont);

    system("\npause");
}
