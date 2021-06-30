#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <math.h>
  
#define MAX 50
#define READ 0
#define WRITE 1
#define SIZE_GAU 8
#define SIZE_JVL 15

sem_t mutex;
int X = SIZE_JVL;
int Y; //nadica de nada

int fd1[2], fd2[2];
int pipe(fd1);   //j  
int pipe(fd2);   //c

void eatJAVALI(void *g)
{
        printf(" - G[%c] is eating the lucky javali %d n very happy.\n",g, X);
}

void takeJavali(void *g)
{
        sem_wait(&mutex); 

        if(X == 0)
	{
		printf("\n - Gaules G[%c] get hungry first n wake up the cooker\n",g);     
		Y = 1;
		write(fd2[1],&Y,sizeof(int));  	//pipe 2: open write
		read(fd1[0],&X,sizeof(int));	//pipe 1: open read
		
	}
	
	eatJAVALI(g);
    	X--;
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
    pid_t pid;
    int i = 0;
    int shmid;
    char Name[8];
    strcpy(Name, "Wel1iton");

    pthread_t GAULES[SIZE_GAU];

    sem_init(&mutex,0,1);

    if (pipe(fd1) < 0) 
    { 
	fprintf(stderr,"* Tube 1 Error *\n");
      	_exit(1); 
    }
    if (pipe(fd2) < 0) 
    { 
	fprintf(stderr,"* Tube 2 Error *\n");
      	_exit(1); 
    }

    pid = fork();

    if (pid < 0) 
    {
      	fprintf(stderr,"* Fork Error *\n");
      	_exit(1);
    }
  	
    if(pid == 0)    	//child process
    { 
      	close(fd1[0]);  //closing read from tube 1
	close(fd2[1]);  // closing write from tube 2
	
	char write[MAX];
        char read[MAX];

      	sprintf(write,"%d",fd1[1]); //pipe on integer type
	sprintf(read,"%d",fd2[0]); 

      	execl("./c2", read, write, NULL); //args[]
    }
    printf("-----------------[Dinner is Served]--------------\n");
    
	 for(i = 0; i < SIZE_GAU; i++)
	 {
		pthread_create(&GAULES[i], NULL, gaules, (void*) Name[i]);
		printf(" + Gaules G[%c] is on the table.\n",Name[i]);
	 }

	 sleep(6);
	 printf("-----------------[Dinner is Over]----------------\n");

    sem_destroy(&mutex);
    return 1;
}
