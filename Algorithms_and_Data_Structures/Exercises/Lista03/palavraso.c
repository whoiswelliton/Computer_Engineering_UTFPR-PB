#include <stdio.h>
#include <string.h>

int main (void)
{
	char string[1000001];
	int i=0,t=0,j=0,n=0;
	while(scanf(" %[^\n]s",string) != EOF)
	{
		t = strlen(string);
		for(i=0;i<t;i++)
		{
			if(string[i] == ' ')
			{
				printf("%c",string[i]);
			}
			else if(j%2 != 0)
			{
				if(string[i] >= 65 && string[i] <= 90)
				{
					if(string[i]+ 13 > 90)
					{
						n = (string[i] + 13) - 90;
						printf("%c",(64 + n));
					}
					else
					{
						printf("%c",string[i] + 13);	
					}
				}
	
				else if (string[i] >= 97 && string[i] <= 122)
				{
					if(string[i]+ 13 > 122)
					{
						n = (string[i] + 13) - 122;
						printf("%c",(96 + n));	
					}
					else
					{
						printf("%c",(string[i]+ 13));
					}	
				} 
				
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
	}
	
	return 0;
}
