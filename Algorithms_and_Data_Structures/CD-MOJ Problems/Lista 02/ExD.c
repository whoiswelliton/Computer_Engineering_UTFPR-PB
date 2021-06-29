#include<stdio.h>

int main()
{
    int i,N,V,C=1;

    while(scanf("%d",&N)&&N!=0)
    {
        int j=0,Total[N];

        for(i=1;i<=N;i++)
        {
            scanf("%d",&V);
            if(V == i)
            {
                Total[j] = V;
                j++;
            }
        }
        printf("Teste %d\n",C);

        for(i=0;i<j;i++)
        {
            printf("%d\n",Total[i]);
        }
        C++;
    }
    return 0;
}

