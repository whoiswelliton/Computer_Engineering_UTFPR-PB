#include <stdio.h>
	
void mergesort (int v[], int l, int r)
{
	if(l < r-1)
	{
		int m = (l+r)/2;
	
		mergesort(v,l,m);
		mergesort(v,m+1,r);
		intercala(v,l,m,r);
	}
}

void intercala (int v[], int l, int m, int r)
{
		int i, j, k, *w;                     
	  
	   	i = l; 
		j = m;                           
	   	k = 0;   
		w = (int*)mallocc ((r-l) * sizeof (int));
	
		while (i < m && j < r) 
		{                
	     		if (v[i] <= v[j])
			{
				w[k++] = v[i++];
			}
	     		else  
			{
				w[k++] = v[j++];
			}            
	  	 } 
		while (i < m)  
		{
			w[k++] = v[i++];	
		}   
		while (j < r) 
		{
			w[k++] = v[j++];
		}
		for (i = l; i < r; ++i)
		{
			v[i] = w[i-l];
		}    
		free (w);                    
}



int main (void)
{
	int vet[10000];
	int n,l,r,tam=0,i=0;
	while(scanf("%d",n) != EOF)
	{
		vet[tam] = n;
		tam++;
	}
	l = 0;
	r = tam-1;
	mergesort (vet,l,r);
	
	for(i=0;i<tam;i++)
	{
		printf("%d ",v[i]);
	}	
}


