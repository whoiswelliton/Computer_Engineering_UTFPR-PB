#include <stdio.h>
#include <stdlib.h>

int main()
{
     int N,C,S,E,i=0,Soma=0;
     char Res;
     scanf("%d",&N);
     scanf("%d",&C);

        for(i=0;i<=N*2;i++)
        {
            if(i % 2 != 0)
            {
                scanf("%d",&E);
                Soma = Soma + E;
                if(Soma < C)
                {
                    Res = 'N';
                }
                else
                {
                    Res = 'S';
                    printf("%s",Res);
                    return(0);

                }
            }
            else
            {
                scanf("%d",&S);
                Soma = Soma - S;
                if(Soma < C)
                {
                    Res = 'N';
                }
                else
                {
                    Res = 'S';
                    printf("%s",Res);
                    return(0);

                }

            }
        }
        if(Soma < C)
        {
            Res = 'N';
            printf("%s\n",Res);
            return(0);
        }
        else
        {
            Res = 'S';
            printf("%s\n",Res);
            return(0);
        }
}

