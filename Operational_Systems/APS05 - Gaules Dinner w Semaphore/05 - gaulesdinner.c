#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>
#include <time.h>
#include <math.h>

//#define T 5  
#define SIZE_GAU 8
#define SIZE_JVL 15

int JAVA_COUNT = SIZE_JVL;
//int LUCKY_JAVA = 0;

sem_t table; 
sem_t hungry; 
sem_t mutex;  

void replaceJAVALIS()
{
	sem_wait(&table);

	JAVA_COUNT = SIZE_JVL;
	
	sem_post(&hungry);
}

void *cooker()
{
	while(1)
	{  
        	replaceJAVALIS();
    	}
}

void eatJAVALI(void *g)
{
        printf(" - G[%c] is eating the lucky javali %d n very happy.\n",g, JAVA_COUNT+1);

}

void takeJavali(void *g)
{
    	sem_wait(&mutex); 

    	if(JAVA_COUNT == 0)
	{
		printf(" - Gaules %c[] get hungry first n wake up the cooker\n",g);		
		
        	sem_post(&table);
		
		sem_wait(&hungry);

   	}
	
	JAVA_COUNT--;

	eatJAVALI(g);
	
        sem_post(&mutex); 
    
}

void *gaules(void* g)
{
	while(1)
	{
		takeJavali(g);

		sleep(1);
	}
}

int main()
{
	int i = 0;
	char Name[8];
	strcpy(Name, "Wel1iton");

	sem_init(&mutex,0,1);
	sem_init(&table,0,0);
	sem_init(&hungry,0,1);
	
	pthread_t COOKER;
	pthread_t GAULES[SIZE_GAU]; 

	pthread_create(&COOKER, NULL, cooker, NULL);

	printf("-----------------[Dinner is Served]--------------\n");
	
	for(i = 0; i < SIZE_GAU; i++)
	{
		//pthread_create(&COOKER, NULL, cooker, NULL);
		pthread_create(&GAULES[i], NULL, gaules, (void*) Name[i]);
		printf(" + Gaules G[%c] is on the table.\n",Name[i]);
	}

	sleep(6);
	printf("-----------------[Dinner is Over]----------------\n");
    	//exit(0);

}
