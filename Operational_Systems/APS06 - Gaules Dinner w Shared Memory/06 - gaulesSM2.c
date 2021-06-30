#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

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

void replaceJAVALIS()
{
    sem_wait(&ptr->table);

    ptr->JAVA_COUNT = SIZE_JVL;

    printf("\n < The Cooker Made his Magic >");

    sem_post(&ptr->hungry);
}

void *cooker()
{
    while(1)
    {  
            replaceJAVALIS();
    }
}

int main(int args, char *argv[])
{
    key_t key;
    int i = 0;
    int shmid; 
    pthread_t COOKER;
	printf("1\n");
    //generating a public key
    key = ftok("/home/ecomp/a1543857/SO/Shared Memory/shrd.txt", KEY);
     printf("2\n");
    //creating n saving shared memory
    shmid = shmget(key, sizeof(struct dinner*), 0);
    if(shmid == -1)
    {
        perror("shmget");
        exit(1);
    }
	printf("3\n");
    //connecting process with memory space
    ptr = shmat(shmid, 0, 0);
    if((int) ptr == -1)
    {
        perror("shmat");
        exit(1);
    }
    ptr->JAVA_COUNT = SIZE_JVL;
	printf("4\n");
    pthread_create(&COOKER, NULL, cooker, NULL);
	sleep(5);
    return 1;
}
