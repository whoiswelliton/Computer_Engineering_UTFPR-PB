#include <stdio.h>

int main(){
  
  int n, l, c;
  int i;
  int coposquebrados=0;
  
  scanf (" %d", &n);
  
  for (i=0; i<n; i++){
    
    scanf (" %d %d", &l, &c);
    if (l>c)
      coposquebrados+=c;
    
  }
  
  printf ("%d\n", coposquebrados);
  return 0;
  
}