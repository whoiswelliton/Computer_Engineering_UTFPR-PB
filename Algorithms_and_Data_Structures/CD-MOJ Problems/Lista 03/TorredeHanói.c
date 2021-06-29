#include<stdio.h>
#include<stdlib.h>
#include <math.h>

int main()
{
    int ND,i=0,Hanoi;

    while(scanf("%d",&ND) != 0)
    {
        if(ND <= 30 && ND >= 0)
        {
            i++;
            Hanoi=(int)pow(2,ND)-1;
            printf("\nTeste %d\n",i);
            printf("%d\n",Hanoi);
        }
    }

    return 0;
}
