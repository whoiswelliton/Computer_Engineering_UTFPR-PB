#include<stdio.h>

int main()
{
    int N,J,Z,i,C=1;

    while(scanf("%d",&N)&&N!=0)
    {
        int f=0,Total[N];

        for(i=0;i<N;i++)
        {
            scanf("%d %d",&J,&Z);

            if(J > Z)
            {
                f = (J+f) - Z;
            }
            else
            {
                f = J -(Z + (f*-1));
            }

            Total[i] = f;
        }
        printf("Teste %d\n",C);

        for(i=0;i<N;i++)
        {
            printf("%d\n",Total[i]);
        }
        C++;
    }
    return 0;
}
