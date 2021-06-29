#include <stdio.h>

int main (void)
{
	int N,Valor;

	scanf("%d",&N);
	
	if(N<=10)
	{
		Valor = 7;
	}		
	else if(N>10 && N<=30)
	{
		Valor = 7 + (N-10)*1;
	}
	else if(N>30 && N<=100)
	{
		Valor = 27 + (N-30)*2;
	}
	else if(N>100)
	{	
		Valor = 167 +(N-100)*5;			
	}
	
	printf("%d\n",Valor);
	return 0;
}
