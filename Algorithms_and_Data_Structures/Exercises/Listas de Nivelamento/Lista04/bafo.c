#include <stdio.h>

int main(){
  
  int n, a, b;
  int conta, contb;
  int teste=1;
  int i;
  
  while (scanf (" %d", &n) && n!=0){
    
    conta=0;contb=0;
    
    for(i=0; i<n; i++){
      
      scanf (" %d %d", &a, &b);
      conta+=a;
      contb+=b;
      
    }
    
    printf ("Teste %d\n", teste++);
    if (conta > contb)
      printf ("Aldo\n\n");
    else
      printf ("Beto\n\n");
    
  }
  
  return 0;
  
}