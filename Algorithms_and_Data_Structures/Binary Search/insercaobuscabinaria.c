 Inserção por busca binária
#include<stdio.h>
int adicPorInsPesqBin(int tam,int v[],int pesq)
{
 int ini=0,fim=tam-1,i=0;
 while(ini<=fim)
 {
  int meio;
  meio=(ini+fim)/2;
  if(v[i]==pesq)
  {
   return -1;
  } 
  else if(v[meio]<pesq)
  {
   ini=meio+1;
  }
  else if(v[meio]>pesq)
  {
   fim=meio-1;
  }
  i++;
 }

 while(ini<=tam)
 {
  v[tam]=v[tam-1];
  tam--;
 }
 v[ini]=pesq;
 return ini;
}
int main (void)
{
 int v[4]={4,5,12,22},pos,x,i,k;
 printf("Informe o valor a ser inserido: ");
 scanf("%d",&x);
 pos=adicPorInsPesqBin(5,v,x);
 printf("O valor foi inserido na posicao: %d. (Se o programa retornou -1, significa que o valor a ser inserido ja existe no vetor\n)",pos);
 printf("\n\n");
 if(pos==-1)k=4;
 else k=5;
 for(i=0;i<k;i++)
 {
  printf("%d\t",v[i]);
 }
 return 0;
}
