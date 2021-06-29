#include <stdio.h>

int main (void)
{
	int L,D;
	int KM,P;
	int Qtd,Custo1,Custo2;

	scanf("%d %d",&L,&D);
	scanf("%d %d",&KM,&P);
	
	Qtd= L/D;
	Custo1= KM*L;
	Custo2= Custo1 + (Qtd*P);
	
	printf("%d\n",Custo2);
	
	return 0;	
}
