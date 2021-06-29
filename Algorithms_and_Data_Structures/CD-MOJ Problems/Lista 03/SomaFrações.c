#include <stdio.h>
#include <stdlib.h>

int MMC(int num,int num2)
{
  int i;
  if(num>num2)
  {
    i=num;
    num=num2;
    num2=i;
  }
  for(i=num2;;i++)
  {
    if((i%num==0)&&(i%num2==0))
    {
      return (i);
    }
  }
}

int MDC(int x,int y)
{
  int i,mdc;
  if(x>y)
  {
    i=x;
    x=y;
    y=i;
  }
  for(i=x;i>=1;i--)
  {
    if((x%i==0) && (y%i==0))
    {
      return(i);
    }
  }

}
int main(void)
{
	int a,b,c,d,res1,res2,i;

	scanf("%d %d %d %d",&a,&b,&c,&d);

	res1 = (((MMC(b,d)/b)*a) + ((MMC(b,d)/d)*c));
    res2 = MMC(b,d);
    i = MDC(res1,res2);
    res1 =(res1/i);
    res2 =(res2/i);
    printf("%d %d\n",res1,res2);

    return(0);
}


