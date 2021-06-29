#include <stdio.h>
#include <math.h>
/*PROGRAMA PARA EXECUTAR NO MENOR TEMPO POSSIVEL*/
int main(){
  
   int i;
   long int n;
   scanf (" %ld", &n);
   int raiz = sqrt(n);
   
   if (n == 2)
     printf ("sim\n");
   
   for (i=2;i<=raiz; i++)
     if (n%i == 0){
       printf ("nao\n");
       return 0;
     }
     
   printf ("sim\n");
   return 0;
  
  
  
}