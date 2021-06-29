#include<stdio.h>
int Pivode3 (int v[],int ini,int fim)
{
     int meio;
        meio=(ini+fim)/2;
        if (v[ini]<v[fim] && v[ini]>v[meio] || v[ini]>v[fim] && v[ini]<v[meio])
        return ini;
        if (v[meio]<v[fim] && v[meio]>v[ini] || v[meio]>v[fim] && v[meio]<v[ini])
        return meio;
     return fim;
}
void quicksort (int v[],int ini,int fim)
{
     int esq,dir,pivo,aux;
     esq=ini;
     dir=fim-1;

     if ((fim-ini)<1)
     return;
     if ((fim-ini)==1)
     {
      if(v[ini]>v[fim])
      {
       aux=v[fim];
       v[fim]=v[ini];
       v[ini]=aux;
       }
      return;
     }
     else
     {
      pivo=Pivode3(v,ini,fim);

      if(v[fim]!=v[pivo])
      {
      aux=v[fim];
      v[fim]=v[pivo];
      v[pivo]=aux;}

      while(esq<dir)
      {
       if(v[esq]>v[fim])
       {
        if(v[dir]<v[fim])
        {
         aux=v[esq];
         v[esq]=v[dir];
         v[dir]=aux;
         esq++;dir--;
         }
        else
        {
          dir--;
        }
        }
       else
       {
        esq++;
        }
      }
     quicksort(v,ini,esq);
     quicksort(v,esq,fim);
     }
}
int main (void)
{
     int v[10]={9,0,8,1,7,2,6,3,5,4},i;
     quicksort(v,0,9);
     for(i=0;i<10;i++){
      printf("%d\t",v[i]);}
     return 0;
}
