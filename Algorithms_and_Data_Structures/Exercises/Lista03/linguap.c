#include <stdio.h>
#include <string.h>

int main (void)
{
	char string[1001];
	int i=0,t=0,j=0;
	scanf(" %[^\n]s",string);
		t = strlen(string);
		for(i=0;i<t;i++)
		{
			if(string[i] == ' ')
			{
				printf("%c",string[i]);
			}
			else if(j%2 != 0)
			{
				printf("%c",string[i]);
			}
			if(string[i] == ' ')
			{
				j=0;
			}
			else
			{
				j++;
			}
			
		}
	printf("\n");
	return 0;
}
