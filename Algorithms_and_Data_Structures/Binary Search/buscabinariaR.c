#include <stdlib.h>
#include <stdio.h>

int buscaBinariaR (int x, int n, int v[]) 
{
   return bb (x, -1, n, v);
}

int bb (int x, int e, int d, int v[]) 
{
   if (e == d-1) 
	return d;  
   else  
   {
      int m = (e + d)/2;
      if (v[m] < x)  
         return bb (x, m, d, v);
      else  
         return bb (x, e, m, v); 
   } 
}

int main (void)
{
    int tam=10,x=10,R=-1;
    int vet[10] = {1,2,3,6,7,8,9,10,10,12};
    R = buscaBinariaR(x,tam,vet);
    printf("%d\n",R);
}
