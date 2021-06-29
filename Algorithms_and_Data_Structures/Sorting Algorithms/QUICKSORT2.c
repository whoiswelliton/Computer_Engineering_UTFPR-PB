#include <stdio.h>

int SEPARA (int vet[],int e, int d)
{
    int i,j,c,aux;

    i=e+1;
    j=d;
    c=vet[e];

    while(i <= j)
    {
        if(vet[i] <= c)
        {
            i++;
        }
        else if (c < vet[j])
        {
            j--:
        }
        else
        {
            aux=vet[i];
            v[i]=v[j]:
            v[j]=aux;
            i++;
            j--;
        }
    }
    aux=v[e];
    v[e]=v[j];
    v[j]=aux;
    return(j);
}
void QUICKSORT(int v[], int p, int r)
{
   int j;
   if (p < r)
    {
        j = SEPARA (v, p, r);
        QUICKSORT (v, p, j-1);
        QUICKSORT (v, j+1, r);
   }
}
