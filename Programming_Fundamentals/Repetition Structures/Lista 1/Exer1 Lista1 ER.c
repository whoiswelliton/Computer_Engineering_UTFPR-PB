#include <stdio.h>
#include <stdlib.h>
/*
Apresentar os números entre 20 e 35. Com uma variável auxiliar e depois com o próprio Cont do for.
*/

int main (void)
{
    int Cont;// contará as repetiçoes do for
    int Num=20;// varialvel a ser mostrado o conteudo
            // inicializar com valor 20
    printf("Mostrar o conteudo de uma variavel somente declarada\n");
    printf("Num: %d\n",Num);

    for(Cont=1;Cont<=16;Cont++)
    {
        printf("%d\t",Num);
        Num=Num+1;//Num++;
    }
    printf("\n\n");
    for(Cont=20;Cont<=35;Cont++)
    {
        printf("%d\t",Cont);
    }

    system("pause");
}
