#include <stdio.h>

int main(){
	int n,c,e,s;
	int num=0,i,passou=0;
	
	scanf ("%d %d", &n, &c);
	
	for (i=0;i<n;i++){
	  
		scanf ("%d %d", &s, &e);
		num=num+e-s;
		
		if (num>c){
			passou=1;
		}
		
	}
	if (passou==1)
		printf ("S\n");
	
	else
		printf ("N\n");	
	
	return 0;
}