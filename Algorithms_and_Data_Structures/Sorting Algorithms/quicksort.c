#include <stdio.h>
#include <string.h>

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
void QUICKSORT(int vet[],int e,int d)
{
    int pivo,i,j,aux;

    pivo=e;

    for(i=e+1;i<=d;i++)
    {
        j=i;
        if(vet[j] < vet[pivo])
        {
            aux=vet[j];
            while(j > pivo)
            {
                vet[j]=vet[j-1];
                j--;
            }
            vet[j]=aux;
            pivo++;
        }
    }
    if(pivo-1 >= e)
    {
        QUICKSORT(vet,e,pivo-1);
    }
    if(pivo+1 <= d)
    {
        QUICKSORT(vet,pivo+1,d);
    }
}
int main (void)
{
    int vet[5];
    vet[0]=5;
    vet[1]=3;
    vet[2]=1;
    vet[3]=0;
    vet[4]=2;

	printf("%d\n",aux);
	return 0;
}
