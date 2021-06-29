#include <stdio.h>

int main (void)
{
	float  A,G,Ra,Rg;
	float P1,P2;

	scanf("%f %f %f %f",&A,&G,&Ra,&Rg);
	
	P1 = Ra/A;
	P2 = Rg/G;
	
	if(P1 > P2)
	{
		printf("A\n");
	}
	else if(P2 >= P1)
	{
		printf("G\n");
	}
	
	return 0;
}
