#include <stdio.h>

int main(){

	int n;
	int t, v;
	int contkm=0;
	int i;

	scanf (" %d", &n);

	for (i=0; i<n; i++){

		scanf (" %d %d", &t, &v);
		contkm+=t*v;

	}
	printf ("%d\n", contkm);
	return 0;

}
