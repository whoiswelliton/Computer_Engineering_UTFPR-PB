#include <stdio.h>
#include <string.h>

int main (void)
{
	char string[101];
	int n=0,i=0,t=0,j=0;
	while(scanf(" %s",string) != EOF)
	{
		t = strlen(string);
		for(i=0;i<t;i++)
		{
			if(string[i] == 'o')
			{
				j++;
			}
		}
	}
	printf("%d\n",j);
	return 0;
}
