#include <stdio.h>
#include <string.h>

int main (void)
{
	char string[101];
	int n=0,i=0,t=0,aux=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf(" %s",string);
		t = strlen(string);
		
		if(t>aux)
		{
			aux=t;	
		}
				
	}
	printf("%d\n",aux);
	return 0;
}
