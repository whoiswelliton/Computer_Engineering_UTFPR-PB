#include <stdio.h>
#include <stdlib.h>
int main (void)
{
	int N,Cont,Fat=1;
	scanf("%d",&N);
    for(Cont=N;Cont>1;Cont--)
    {
        Fat = Fat * Cont;
    }
    printf("%d\n",Fat);
	return 0;
}
