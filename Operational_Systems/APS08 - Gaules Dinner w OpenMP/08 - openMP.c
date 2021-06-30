#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define SIZE_GAU 8
#define SIZE_JVL 15

int JAVA_COUNT = SIZE_JVL;

omp_lock_t table; 
omp_lock_t hungry; 

void replaceJAVALIS()
{
	omp_set_lock(&table); 

	JAVA_COUNT = SIZE_JVL;
	printf(" < The Cooker Made his Magic n Replace All The Java's >\n\n");
	
	omp_unset_lock(&hungry);
}

void *cooker(void *g)
{
	while(1)
	{  
        	replaceJAVALIS();
    	}
}

void eatJAVALI(void *g)
{
        printf(" - G[%d] is eating the lucky javali %d n very happy.\n",g, JAVA_COUNT+1);

}

void takeJavali(void *g)
{
	#pragma omp critical(section1)
    	{
	    	if(JAVA_COUNT == 0)
		{
			printf(" - Gaules [%d] get hungry first n wake up the cooker\n",g);		
			omp_unset_lock(&table);
			omp_set_lock(&hungry);

	   	}
	
		JAVA_COUNT--;

		eatJAVALI(g);
	}
    
}

void gaules(void *g)
{
	while(1)
	{
		takeJavali(g);

		sleep(1);
	}
}

int main()
{

	omp_set_lock(&table);
    	omp_set_lock(&hungry);

	printf("-----------------[Dinner is Served]--------------\n");
    	
	#pragma omp parallel num_threads(SIZE_GAU+1)  //cria threads em OMP
    	{
		int g;
		g = omp_get_thread_num();
	
		if(g == 0)
		{
		    cooker(g);
		}

		gaules(g);
        
   	 }
	
	printf("-----------------[Dinner is Over]----------------\n");
}
