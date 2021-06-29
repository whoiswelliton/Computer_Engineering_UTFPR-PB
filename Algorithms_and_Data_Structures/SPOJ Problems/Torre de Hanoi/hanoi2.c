#include <stdio.h>
int qtd=0;
void TorreHanoi(int orig, int dest, int aux, int n)
    {
        if(n==1)
        {
            qtd++;
        }
        else
        {
            TorreHanoi(orig, aux, dest, n-1);
            qtd++;
            TorreHanoi(aux, dest, orig, n-1);
        }

    }
int main()
{
    int n,Qtdtestes=0;
    while(scanf("%d",&n) != EOF)
    {
        Qtdtestes++;
        TorreHanoi('A','B','C',n);
        printf("\nTeste %d\n",Qtdtestes);
        printf("%d\n",qtd);
        qtd=0;
    }
    return 0;
}


