#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	int A[5];
	int i=0,j=0,k=0;
	
	for(i=0;i<5;i++)
	{
		scanf("%d",&A[i]);
	}
	i=0;
	while(A[k] == A[k+1] && k!=4)
	{
		k++;
		if(k==4)
		{	
			printf("N\n");
		}
	}
	while(A[i] <= A[i+1] && i!=4 && k!=4)
	{
		i++;
		if(i==4)
		{	
			printf("C\n");
		}
	}
	while(A[j] >= A[j+1] && j!=4 && i!=4 && k!=4)
	{
		j++;
		if(j==4)
		{	
			printf("D\n");
		}
	}
	
	if(i!=4 && j!=4 && k!=4)
	{
		printf("N\n");
	}
		
	return 0;
}
