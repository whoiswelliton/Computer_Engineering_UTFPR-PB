#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <omp.h>
#include </usr/include/openmpi/mpi.h>

#define SIZE_GAU 8
#define SIZE_JVL 15

int JAVA_COUNT = SIZE_JVL;
int tag = 0;

/*
void gaules(void* g)
{
	while(1)
	{
		//takeJavali(g);
		sleep(1);
	}
}
*/	

void main(int argc, char *argv[])
{
	int i;
		
	int size;              
	int my_rank;            
	MPI_Status status;  

	char Name[8];
	strcpy(Name,"Wel1iton");
	
   	MPI_Init(&argc, &argv);   
    	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank); 
    	MPI_Comm_size(MPI_COMM_WORLD, &size); 
	

	if(my_rank == 0) //cooker
	{
        	
		int Javalis[1] = {14};
		int Received[1];
		
		while(1)
		{
			MPI_Recv(Received, 1, MPI_INT, 99, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		
			MPI_Send(Javalis, 1, MPI_INT, 99, tag, MPI_COMM_WORLD);
		}
	

	}
	else  //table
	{
		printf("-----------------[Dinner is Served]--------------\n");
	
		#pragma omp parallel num_threads(SIZE_JVL) //gauleses
		{
			int Gaules[1];
			Gaules[0] = omp_get_thread_num();

			//printf(" + Gaules G[%c] is on the table.\n", gaules[0]);

			int Rank[1] = {my_rank};
			int LuckyJava[1];

				
			#pragma omp critical(section1)
			{
    	
			    	if(JAVA_COUNT == 0)
				{
					printf("\n - Gaules [%d] get hungry first n wake up the cooker\n", gaules[0]);		
					
					MPI_Send(Javalis,1,MPI_INT,0,0,MPI_COMM_WORLD);
			
					MPI_Recv(Javalis,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);

			   	}
				else
				{
					MPI_Recv(Recebidos,1,MPI_INT,2,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);

					printf("Mesa recebeu: %c e esta enviando %d Javalis\n",Nome[Recebidos[0]],Javalis[0]);

					//printf(" - G[%d] is eating the lucky javali %d n very happy.\n", gaules[0], JAVA_COUNT);

					MPI_Send(Javalis,1,MPI_INT,2,0,MPI_COMM_WORLD);

					Javalis[0]--;
					//JAVA_COUNT--;
				}
			}
		}
	}

	printf("-----------------[Dinner is Over]----------------\n");

	MPI_Finalize(); 

}
