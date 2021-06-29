#include <stdio.h>
#include <math.h>

int main(){
	int iDiscos, iTeste=1;
	while(scanf("%d",&iDiscos), iDiscos>0)
	printf("\nTeste %d\n%d\n",
	 iTeste++, (int)
	  pow(2,iDiscos)-1);
	return 0;
}
