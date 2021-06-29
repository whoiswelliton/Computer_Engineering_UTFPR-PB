int buscaBinaria (int x, int n, int v[])
{ 
   int e, m, d; 
   e = -1; 
   d = n;  // atenção!
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
	
