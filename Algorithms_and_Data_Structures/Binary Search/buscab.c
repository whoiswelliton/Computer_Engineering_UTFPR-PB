#include <stdlib.h>
#include <stdio.h>
int buscaBinaria (int x, int n, int v[])
{ 
   int e, m, d; 
   e = -1; 
   d = n; 
   while (e < d-1) 
   {  
     m = (e + d)/2;
      if (v[m] < x) 
	e = m;
      else
	d = m; 
   }
   return d;
}

int main (void)
{
    int tam=10,x=10,R=-1;
    int vet[10] = {1,2,3,6,7,8,9,10,10,12};
    R = buscaBinaria(x,tam,vet);
    printf("%d\n",R);
}	
