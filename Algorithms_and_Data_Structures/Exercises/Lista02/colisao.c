#include <stdio.h>

int main (void)
{
	int  xi,yi,xf,yf,ji,ki,jf,kf;

	scanf("%d %d %d %d",&xi,&yi,&xf,&yf);
	scanf("%d %d %d %d",&ji,&ki,&jf,&kf);
	
	if(xf<ji || yf<ki || (xf<ji && yf<ki))
	{
		printf("0\n");
	}
	else if(xi>jf || yi>kf ||(xi>jf && yi>kf))
	{
		printf("0\n");
	}
	else
	{
		printf("1\n");
	}
	
	
	return 0;
}
