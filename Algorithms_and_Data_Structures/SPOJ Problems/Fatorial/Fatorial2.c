#include <stdio.h>
#include <stdlib.h>
int fatorial (int N)
{
    int Fat = 1;
    while(N != 0)
    {
            Fat = Fat *N;
            N--;
    }
    return(Fat);
}
int main (void)
{
	int N;
	scanf("%d",&N);
	if(N=!0)
	{
	    fatorial(N);
	    printf("%d\n",fatorial(N));
	}
	else
	{
	    printf("0");
    }
	return 0;
}
