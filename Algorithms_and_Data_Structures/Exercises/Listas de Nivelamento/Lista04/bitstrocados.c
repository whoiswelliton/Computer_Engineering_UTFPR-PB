#include <stdio.h>

int main(){
  
  int v;
  int n=1;
  int i, j, k, l;
  
  while (scanf (" %d", &v) && v!=0){
    
    printf ("Teste %d\n", n);
    ++n;
    
    i = v/50;
    j = (v%50)/10;
    k = ((v%50)%10)/5;
    l = ((v%50)%10)%5;
    
    printf ("%d %d %d %d\n\n", i, j, k, l);
    
  }
  
  return 0;
  
}