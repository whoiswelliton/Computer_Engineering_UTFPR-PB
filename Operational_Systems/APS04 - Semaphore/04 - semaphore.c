#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <math.h>
 
sem_t smph1,smph2,smph3; 
int t;

void *Call_A(char ID)
{
	printf("-> Starting %c\n",ID);
    	
        t = rand()%5 + 1; //work without context, just chilling
        sleep(t);
	sem_post(&smph1);

	printf("Finishing...%c\n",ID);
}

void *Call_B(char ID)
{
    	printf("-> Starting %c\n",ID);
        
        t = rand()%5 + 1;
        sleep(t);

	sem_post(&smph2);

        printf("Finishing...%c\n",ID);
    	
}

void *Call_C(char ID)
{
	sem_wait(&smph1);
	sem_wait(&smph2);
	
        printf("-> Starting %c\n",ID);

	t = rand()%5 + 1;
        sleep(t);
        
	sem_post(&smph3);
	sem_post(&smph3);

	printf("Finishing...%c\n",ID);
}

void *Call_D(char ID)
{
	sem_wait(&smph3);

        printf("-> Starting %c\n",ID);
	
	t = rand()%5 + 1;
        sleep(t);

	printf("Finishing...%c\n",ID);
}

void *Call_E(char ID)
{
	sem_wait(&smph3);

        printf("-> Starting %c\n",ID);
	
	t = rand()%5 + 1;
        sleep(t);

	printf("Finishing...%c\n",ID);
}


int main(int argc, char *argv[])
{
	
	int i;
	pthread_t letters[5];   
	sem_init(&smph1,0,0);  // (semaphore, shared between threads, quantity)
    	sem_init(&smph2,0,0);
    	sem_init(&smph3,0,0);
	srand( (unsigned)(time(NULL)));  
	
	pthread_create(&letters[0], NULL, Call_A, 'A');
	pthread_create(&letters[1], NULL, Call_B, 'B'); 
	pthread_create(&letters[2], NULL, Call_C, 'C');
	pthread_create(&letters[3], NULL, Call_D, 'D');
    	pthread_create(&letters[4], NULL, Call_E, 'E');

	for(i = 0; i < 5; i++)
	{
		pthread_join(letters[i], NULL);
	}

	sem_destroy(&smph1);
    	sem_destroy(&smph2);
    	sem_destroy(&smph3);
}
