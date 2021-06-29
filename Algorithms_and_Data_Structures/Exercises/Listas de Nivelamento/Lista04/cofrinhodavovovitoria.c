#include <stdio.h>

int main(){
  
  int n, j, z,i;
  int saldo; //positivo para quando joaozinho tem mais, negativo quando 
                //zezinho tem mais
  int teste=1;
  
  while (scanf ("%d", &n) && n!=0){
    
    printf ("Teste %d\n", teste);
    teste++;
    saldo=0;
    
    for (i=0; i<n; i++){
      
      scanf (" %d %d", &j, &z);
      saldo = saldo+j-z;
      printf ("%d\n", saldo);
      
    }
    printf ("\n");
    
  }
  
  return 0;
  
}