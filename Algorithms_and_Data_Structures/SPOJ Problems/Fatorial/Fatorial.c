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
    if(N = 0)
    {
        return(1);
    }
}
int main (void)
{
	int N;
	while(scanf("%d",&N))
	{

		fatorial(N);
		printf("%d\n",fatorial(N));
	}
	return 0;
}
