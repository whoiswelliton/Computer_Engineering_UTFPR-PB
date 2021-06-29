#include <stdio.h>
int main(void)
{
    int H,N,S,SaldoF;
    scanf("%d",&N);
    scanf("%d",&S);
    int Menor=S;

    while((scanf("%d",&H))!=EOF)
    {
        SaldoF = S + (H);
        if(SF < S)
        {
            Menor = SaldoF;
        }
        else
        {
            Menor = S;
        }
    }
    printf("%d\n",Menor);
    return(0);
}

