#include <stdio.h>

int main (void)
{
	int n;
	int i=0;
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		if(i%2==0)
		{
			printf("THUMS THUMS THUMS\n");
			
		}
		else
		{
			printf("THUMS THUMS THUMS THUMS THUMS THUMS\n");
		}
	}
	return 0;
	
}
