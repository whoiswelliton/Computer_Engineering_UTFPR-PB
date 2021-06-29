void quicksort_it (int v[], int p, int r)
{
   int j, *pilhap, *pilhar, t;

   pilhap = malloc ((r-p+1) * sizeof (int));
   pilhar = malloc ((r-p+1) * sizeof (int));

   pilhap[0] = p; pilhar[0] = r; t = 0; 
   
   while (t >= 0) 
   {      
       p = pilhap[t]; r = pilhar[t]; --t;
      	if (p < r) 
	{
		 j = separa (v, p, r);    
		 ++t; pilhap[t] = p; pilhar[t] = j-1; 
		 ++t; pilhap[t] = j+1; pilhar[t] = r; 
       }
   }
}
int separa (int v[], int p, int r) 
{
   int c = v[p], i = p+1, j = r, t;         // 1
   while (1) {                              // 2
      while (i <= r && v[i] <= c) ++i;      // 3
      while (c < v[j]) --j;                 // 4
      if (i >= j) break;                    // 5
      t = v[i], v[i] = v[j], v[j] = t;      // 6
      ++i; --j;                             // 7
   }                                        // 8
   v[p] = v[j], v[j] = c;                   // 9
   return j;                                // 10
}
