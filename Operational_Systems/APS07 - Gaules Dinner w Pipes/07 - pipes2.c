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
int JAVA_COUNT = SIZE_JVL;
int X = SIZE_JVL;
int Y;

void replaceJAVALIS(char **arg)
{
    JAVA_COUNT = SIZE_JVL;
    
    read(atoi(arg[0]),&Y,sizeof(Y));
    write(atoi(arg[1]),&X,sizeof(X));

    printf(" < The Cooker Made his Magic n Replace All The Java's >\n\n");

}

void *cooker(char **arg)
{
    while(1)
    {  
            replaceJAVALIS(arg);
    }
}

int main(int argc, char *argv[])
{
    pthread_t COOKER;

    pthread_create(&COOKER, NULL, cooker, argv);

    sleep(6);
    return 1;
}
