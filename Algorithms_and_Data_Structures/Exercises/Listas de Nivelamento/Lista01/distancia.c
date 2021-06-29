#include <stdio.h>

int main (void)
{
	int X,Y,Z,W;
	int A,B,Min;
	scanf("%d %d %d %d",&X,&Y,&Z,&W);

		A = abs(Z-X);
		B = abs(W-Y);

		Min = A+B;
	
		printf("%d\n",Min);	
	return 0;	
}
