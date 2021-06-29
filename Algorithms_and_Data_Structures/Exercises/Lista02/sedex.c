#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (void)
{
	int D,A,B,C;
	double p;
	
	scanf("%d",&D);
	scanf("%d %d %d",&A,&B,&C);

	if(D<=A && D<=B && D<=C)
	{
		printf("S\n");
	}
	else
	{
		printf("N\n");
	}
	

	return(0);
}
