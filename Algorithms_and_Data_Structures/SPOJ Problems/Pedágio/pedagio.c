#include <stdio.h>

int main (void)
{
	int l,d,p,k,r,y;
	
	scanf("%d %d",&l,&d);
	scanf("%d %d",&k,&p);
	
	r = (l/d);
	y = l*k + r*p;
	
	printf("%d\n",y);

	return 0;
}

