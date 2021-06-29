// Esta função recebe um vetor crescente v[0..n-1]
// e um inteiro x e devolve um índice j em 0..n 
// tal que v[j-1] < x <= v[j].

int 
buscaBinaria2 (int x, int n, int v[]) {
   return bb (x, -1, n, v);
}

// Recebe um vetor crescente v[e+1..d-1]
// e um inteiro x tal que v[e] < x <= v[d]
// e devolve um índice j em e+1..d tal que
// v[j-1] < x <= v[j].

static int 
bb (int x, int e, int d, int v[]) 
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

