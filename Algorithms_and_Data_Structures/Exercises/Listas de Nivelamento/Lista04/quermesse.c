#include <stdio.h>

int main(){

  int n;
  int i, cont=1, aux;
  int ganhador;
  
  while (scanf (" %d", &n) && n!=0){
    
    
    for(i=1; i<=n; i++){
      
      scanf (" %d", &aux);
      if (aux == i)
	ganhador=i;
    }
    
    printf ("Teste %d\n%d\n",cont,ganhador);
    cont++;
  
  
  }
  
    return 0;
}