#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	int A[5];
	int i=0,C=1,D=1;
	
	for(i=0;i<5;i++)
	{
		scanf("%d",&A[i]);
	}
	for(i=0;i<4;i++)
	{
		if(A[i] < A[i+1])
		{
			D=0;
		}
		else if(A[i] > A[i+1])
		{
			C=0;
		}		
	}
	if(C==1)
	{
		printf("C\n");
	}
	else if(D==1)
	{
		printf("D\n");
	}
	else
	{
		printf("N\n");
	}
	
	return 0;
}
