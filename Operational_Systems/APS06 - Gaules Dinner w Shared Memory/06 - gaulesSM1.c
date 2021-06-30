#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <time.h>
#include <math.h>
  
#define SIZE_GAU 8
#define SIZE_JVL 15
#define KEY 1234

typedef struct DINNER
{
	int JAVA_COUNT;
	sem_t table;
	sem_t hungry;
}dinner;

dinner *ptr;
sem_t mutex;

void eatJAVALI(void *g)
{
        printf(" - G[%c] is eating the lucky javali %d n very happy.\n",g,ptr->JAVA_COUNT+1);
}

void takeJavali(void *g)
{
        sem_wait(&mutex); 

        if(ptr->JAVA_COUNT == 0)
	{
		printf(" - Gaules G[%c] get hungry first n wake up the cooker\n",g);     
		
		sem_post(&ptr->table);
		
		sem_wait(&ptr->hungry);

	}
    
    	ptr->JAVA_COUNT = ptr->JAVA_COUNT-1;

    	eatJAVALI(g);
    
    	sem_post(&mutex); 
}

void *gaules(void *g)
{
    while(1)
    {
        takeJavali(g);

        sleep(1);
    }
}

int main()
{

    key_t key;
    int i = 0;
    int shmid;
    char Name[8];
    strcpy(Name, "Wel1iton");

    pthread_t GAULES[SIZE_GAU];

    //printf("1\n");

    //generating a public key
    key = ftok("/home/ecomp/a1543857/SO/Shared Memory/shrd.txt", KEY);

    //printf("2\n");

    //creating n saving shared memory
    shmid = shmget(key, sizeof(struct dinner*), IPC_CREAT|0666);
    if(shmid == -1)
    {
        perror("shmget");
        exit(1);
    }

    //printf("3\n");

    //attaching-connecting process with memory space
    ptr = (struct dinner*) shmat(shmid, 0, 0);
    if((int) ptr == -1)
    {
        perror("shmat");
        exit(1);
    }

    ptr->JAVA_COUNT = SIZE_JVL;

    sem_init(&mutex,0,1);
    sem_init(&ptr->table,1,0);
    sem_init(&ptr->hungry,1,1);
    //printf("4\n");
	
    pid_t pid;

	if(pid = fork() < 0)
	{
		printf("Erro\n");
	}
	if(pid == 0)
	{
		execl("./c2",NULL);
	}

    printf("-----------------[Dinner is Served]--------------\n");
    
    for(i = 0; i < SIZE_GAU; i++)
    {
        pthread_create(&GAULES[i], NULL, gaules, (void*) Name[i]);
        printf(" + Gaules G[%c] is on the table.\n",Name[i]);
    }

    //printf("5\n");

    sleep(6);
    printf("-----------------[Dinner is Over]----------------\n");

    sem_destroy(&mutex);
    sem_destroy(&ptr->table);
    sem_destroy(&ptr->hungry);
    return 1;

}
