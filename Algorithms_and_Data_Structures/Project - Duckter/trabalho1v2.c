#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define AUTHKEY "a12ae7e8"
#define TAMINICIAL 100


typedef struct chaves{
    char key1[51];
    char conteudo[1001];
}chaves;
typedef struct tags{
    char tag[1001];
    char key2[51];
}tags;
typedef struct hits{
    char rep[10000];
    int vet[10000];
}hits;

int  ADD_KEY (chaves K[],int keycont, int TotalK)
{
    if(keycont + 1 == TotalK)
    {
	TotalK = TotalK + TAMINICIAL;
        K = realloc(K, (TotalK)*sizeof (chaves));

    }

    scanf(" %s:",K[keycont].key1);
    scanf(" %[^\n]s",K[keycont].conteudo);


    return(keycont);
}

int TAG_HIT (tags T[], int tagcont,int TotalT)
{
    if(tagcont + 1 == TotalT)
    {
        TotalT = TotalT + TAMINICIAL;
        T = realloc(T, (TotalT)*sizeof (tags));
    }

    scanf(" %s",T[tagcont].tag);
    scanf(" %s",T[tagcont].key2);

    return(tagcont);
}
int PIVODE3TAGS (tags T[],int left,int right)
{
    int m,i,j;
    m = (left + right)/2;
    i = left;
    j= right;

    if ((T[i].tag < T[j].tag && T[i].tag > T[m].tag) || (T[i].tag > T[j].tag && T[i].tag < T[m].tag))
    {
        return i;
    }
    if ((T[m].tag < T[j].tag && T[m].tag > T[i].tag) || (T[m].tag > T[j].tag && T[m].tag < T[i].tag))
    {
        return m;
    }
    return j;
}
int PIVODE3KEYS (chaves K[],int left,int right)
{
    int m,i,j;
    m = (left + right)/2;
    i = left;
    j= right;

    if ((K[i].key1 < K[j].key1 && K[i].key1 > K[m].key1) || (K[i].key1 > K[j].key1 && K[i].key1 < K[m].key1))
    {
        return i;
    }
    if ((K[m].key1 < K[j].key1 && K[m].key1 > K[i].key1) || (K[m].key1 > K[j].key1 && K[m].key1 < K[i].key1))
    {
        return m;
    }
    return j;
}

void QUICK_SORT_TAGS (tags T[],int left,int right)
{
    int l,r,p,i,j;
    tags Aux;

    l = left;
    r = right-1;
    i = left;
    j = right;

    if ((j - i) < 1)
    {
        return;
    }
    if ((j - i) == 1)
    {
        if(T[i].tag > T[j].tag)
        {
            Aux = T[j].tag;
            T[j].tag = T[i].tag;
            T[i].tag = Aux;
        }
        return;
     }
     else
     {
          p = PIVODE3TAGS(T, i, j);

          if(T[j].tag != T[p].tag)
          {
                Aux = T[j].tag;
                T[j].tag = T[p].tag;
                T[p].tag = Aux;
          }
          while(l < r)
          {
                if(T[l].tag > T[j].tag)
                {
                    if(T[r].tag < T[j].tag)
                    {
                        Aux = T[l].tag;
                        T[l].tag = T[r].tag;
                        T[r].tag = Aux;
                        l++;
                        r--;
                    }
                    else
                    {
                        r--;
                    }
                }
                else
                {
                    l++;
                }
            }
            QUICK_SORT_TAGS(T, i, l);
            QUICK_SORT_TAGS(T, l, j);
     }
}

void QUICK_SORT_KEY(chaves K[], int left, int right)
{
    int l,r,p,i,j;
    chaves Aux;

    l = left;
    r = right-1;
    i = left;
    j = right;

    if ((j - i) < 1)
    {
        return;
    }
    if ((j - i) == 1)
    {
        if(K[i].key1 > K[j].key1)
        {
            Aux = K[j].key1;
            K[j].key1 = K[i].key1;
            K[i].key1 = Aux;
        }
        return;
     }
     else
     {
          p = PIVODE3TAGS(K, i, j);

          if(K[j].key1 != K[p].key1)
          {
                Aux = K[j].key1;
                K[j].key1 = K[p].key1;
                K[p].key1 = Aux;
          }
          while(l < r)
          {
                if(K[l].key1 > K[j].key1)
                {
                    if(K[r].key1 < K[j].key1)
                    {
                        Aux = K[l].key1;
                        K[l].key1 = K[r].key1;
                        K[r].key1 = Aux;
                        l++;
                        r--;
                    }
                    else
                    {
                        r--;
                    }
                }
                else
                {
                    l++;
                }
            }
            QUICK_SORT_KEY(K, i, l);
            QUICK_SORT_KEY(K, l, j);
     }
}

int BUSCA_TAG (tags T[], char Tg[], int tagcont)
{
	int l, m, r;
	l = 0;                                         //left
   	r = tagcont-1;                                 //right


   	while (l < r)
	{                				 //middle
		m = (l + r)/2;

     		if (strcmp(T[m].tag, Tg) == 0)
		{
			return(m);
		}
		else if (strcmp(T[m].tag, Tg) < 0)
		{
			l = m + 1;
		}
      		else
		{
			r = m - 1;
		}
   	}
   return -1;
}

int BUSCA_KEY (chaves K[], char T[], int keycont)
{
	int l, m, r;
	l = 0;                         //left
   	r = keycont-1;                 //right


   	while (l <= r)
	{
		 m = (l + r)/2;				 //middle

     	        if (strcmp(K[m].key1, T) == 0)
		{
			return(m);
		}
		if (strcmp(K[m].key1, T) < 0)
		{
			l = m + 1;
		}
      		else
		{
			r = m - 1;
		}
   	}
   return -1;
}

void SHOW_TAG(tags T[],chaves K[], int tagcont,int keycont)
{
    int x,y;
    char Tg[1001];
    scanf(" %s",Tg);
    x = 0;
    y = 0;


    QUICK_SORT_TAG(T, 0, tagcont-1);
    QUICK_SORT_KEY(K, 0, keycont-1);

    y = BUSCA_TAG(T, Tg, tagcont);
    x = BUSCA_KEY(K, T[y].tag, keycont);

    printf("#%s -> %s\n",T[y].tag,T[y].key2);
    printf("%s :. %s\n",K[x].key1,K[x].conteudo);

}



//int TREND_TOP()

//int TREND_BOTTOM()

//int DUMP_TAGS()

//int DUMP_KEYS()


int main (void)
{
    chaves *K;
    tags *T;
    hits *H;
    int d,f;

    K = malloc(TAMINICIAL*sizeof (chaves));
    T = malloc(TAMINICIAL*sizeof (tags));
    H = malloc(TAMINICIAL*sizeof (hits));

    int TotalT, TotalK;

    int keycont, tagcont;
    TotalT = TotalK = TAMINICIAL;
    keycont = tagcont = 0;

    char string1 [10],string2[10],string3[50];

    while(scanf("%s %s",string1,string2) != EOF)
    {

        if(strcmp(string1,"add") == 0 && strcmp(string2,"key") == 0)
        {
        	ADD_KEY(K, keycont, TotalK);
		keycont++;
        }
        else if(strcmp(string1,"tag") == 0 && strcmp(string2,"hit") == 0)
        {
        	TAG_HIT(T, tagcont, TotalT);
		tagcont++;
        }
	else if(strcmp(string1,"show") == 0 && strcmp(string2,"tagcontent") == 0)
	{
		SHOW_TAG(T, K, tagcont, keycont);

	}
	/*else if(strcmp(string1,"list") == 0 && strcmp(string1,"trending") == 0)
	{
		//ler string3
		if(strcmp(string3,"top") == 0)
		 {
		        TREND_TOP();
		 }
		 else if(strcmp(string3,"bottom") == 0)
		  {
		     	   	TREND_BOTTOM();
		  }
  	}
	else if(strcmp(string1,"dump") == 0)
	{
		    	if(strcmp(string2,"tags") == 0)
		    	{
		    	   	DUMP_TAGS();
		    	}
		   	 else if(strcmp(string2,"keys") == 0)
		  	{
		        	DUMP_KEYS();
                  	}
        }*/

    }
	QUICK_SORT_TAG(T, 0, tagcont-1);
        QUICK_SORT_KEY(K, 0, keycont-1);

    	for(d=0;d<keycont;d++)
	{
		printf("\n%s - %s\n",K[d].key1,K[d].conteudo);
	}
	for(f=0;f<tagcont;f++)
	{
		printf("\n%s - %s\n",T[f].tag,T[f].key2);
	}

    return 0;
}
