void quick_S (int v[], int p, int r) 
{
   int c, i, j, t;
   if (p < r)
 {      
      c = v[(p+r)/2];
      i = p, j = r;
      while (i <= j) {
         while (v[i] < c) ++i;
         while (c < v[j]) --j;
         if (i <= j) {
            t = v[i], v[i] = v[j], v[j] = t;
            ++i, --j;
         }
      }
      quick_S (v, p, j);
      quick_S (v, i, r);
   }
}
