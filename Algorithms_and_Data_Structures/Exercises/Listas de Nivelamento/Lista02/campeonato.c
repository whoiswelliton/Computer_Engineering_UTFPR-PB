#include <stdio.h>

int main (void)
{
	int cv,ce,cs,fv,fe,fs;
	int sc, sf;

	scanf("%d %d %d %d %d %d",&cv,&ce,&cs,&fv,&fe,&fs);
	
	sc = cv*3 + ce*1;
	sf = fv*3 + fe*1;
	
	if(sc > sf)
	{
		printf("C\n");
	}
	else if(sf > sc)
	{
		printf("F\n");
	}
	else
	{
		if(cs > fs)
		{
			printf("C\n");
		}
		else if(fs > cs)
		{
			printf("F\n");
		}
		else
		{
			printf("=\n");
		}
			
	}
	return 0;
}
