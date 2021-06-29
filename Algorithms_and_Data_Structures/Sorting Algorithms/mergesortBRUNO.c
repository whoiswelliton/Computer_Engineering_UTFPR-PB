void mergesort (int *v, int l, int r)
{
	int m = (l+r)/2;
	
	mergesort(v,l,m);
	mergesort(v,m+1,r);
	
	intercala(v,l,m,r);
}

void intercala (int *v, int l, int m, int r)
{
	int *novo = mergesort(& v[l], &v[m+1],m-l+1,r-m);
	int i;
	for(i=0; i<r-l;i++)
	{
		v[l++] = novo[i];
	}
	free(novo);
}
