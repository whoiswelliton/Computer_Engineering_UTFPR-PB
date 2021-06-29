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

void QUICK_SORT_TAG(tags T[], int left, int right)
{
	  int i, j , m;
	  tags x;
	  tags aux;

	  i = left;
	  j = right;
	  m = (left+right)/2;
	  x = T[m];

	  while(i < j)
          {
	    while((strcmp(T[i].tag,x.tag) < 0) && (i < right)) 
	    {
	       i++;
	    }
	    while((strcmp(T[j].tag,x.tag) > 0) && (j > left)) 
	    {
		j--;
	    }
	    if(i <= j)  
	    {
	      aux = T[i];
	      T[i] = T[j];
	      T[j] = aux;
	      i++;
	      j--;
	    }
	  } 

	  if(left < j) 
	  {
	     QUICK_SORT_TAG(T, left, j);
	  }
	  if(i < right) 
	  {
	     QUICK_SORT_TAG(T, i, right);
	  }
}
void QUICK_SORT_KEY(chaves K[], int left, int right)
{
  int i, j , m;
  chaves x;
  chaves aux;

  i = left;
  j = right;
  m = (left+right)/2;
  x = K[m];

  do 
  {
    while((strcmp(K[i].key1,x.key1) < 0) && (i < right)) 
    {
       i++;
    }
    while((strcmp(K[j].key1,x.key1) > 0) && (j > left)) 
    {
        j--;
    }
    if(i <= j)  
    {
      aux = K[i];
      K[i] = K[j];
      K[j] = aux;
      i++;
      j--;
    }
  } while(i <= j);

  if(left < j) 
  {
     QUICK_SORT_KEY(K, left, j);
  }
  if(i < right) 
  {
     QUICK_SORT_KEY(K, i, right);
  }
}

int BUSCA_TAG (tags T[], char Tg[], int tagcont) 
{
	int l, m, r;                              
	l = 0;                                         //left
   	r = tagcont-1;                                 //right
                       

   	while (l <= r) 
	{                				 //middle     
		m = (l + r)/2;
	                       
     		if (strcmp(Tg, T[m].tag) == 0) 
		{
			return(m);
		}
		else if (strcmp(Tg, T[m].tag) > 0)
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

int BUSCA_KEY (chaves K[], char Tg[], int keycont) 
{
	int l, m, r;                              
	l = 0;                         //left
   	r = keycont-1;                 //right
                     

   	while (l <= r) 
	{           	
		 m = (l + r)/2;				 //middle
                  
     	        if (strcmp(Tg, K[m].key1) == 0)  
		{
			return(m);
		}
		else if (strcmp(Tg, K[m].key1) > 0)
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
   	
    if(y == -1)
    {
	printf("TAG");
    }
    else
    if(x == -1)
    {
	printf("KEY");
    }
    {
	    printf("#%s -> %s\n",T[y].tag,T[y].key2);
	    printf("%s :. %s\n",K[x].key1,K[x].conteudo);
    }
       
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
