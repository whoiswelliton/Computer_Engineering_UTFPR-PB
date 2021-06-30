#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include </usr/include/openmpi/mpi.h>
#include <omp.h>

#define SIZE_GAU 8
#define SIZE_JVL 15

void main(int argc, char * argv[])
{
	int my_rank;           
	int size;              
	       
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
			MPI_Recv(Received, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		
			MPI_Send(Javalis, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
		}
		
	}
	else if(my_rank == 1) //table
	{
		int Avaliable[1] = {14};
		int Request[1];

		while(1)
		{
			if (Avaliable[0] == 0)
			{
				printf("The Last Gaules get hungry, shout n wake up the cooker...\n");

				#pragma omp critical(section1)
				{
		
					MPI_Send(Avaliable, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);

					MPI_Recv(Avaliable, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				
					printf("\n < The Cooker Made his Magic n Replace All The Java's >\n\n");
				}
			}
			else
			{
				MPI_Recv(Request, 1, MPI_INT, 2, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

				printf("Table Received a Request from: %c | Sending Javali %d \n",Name[Request[0]], Avaliable[0]);

				MPI_Send(Avaliable, 1, MPI_INT, 2, 0, MPI_COMM_WORLD);

				Avaliable[0]--;
			
			}
		}
	}
	else //Gaules
	{
		#pragma omp parallel num_threads(SIZE_GAU)
		{
			int idGaules;
			idGaules = omp_get_thread_num();
		
			int LuckyJava;
			//int AskTable[1] = {my_rank};
			//printf("\nTest %c %d\n",Name[idGaules],idGaules);

			while(1)
			{
				
				MPI_Send(&idGaules, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);

				MPI_Recv(&LuckyJava, 1, MPI_INT,1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

				printf(" - G[%c][id = %d] is eating the lucky javali %d n very happy.\n", Name[idGaules], idGaules, LuckyJava);

				sleep(1);
			
			}
		}
	}

	MPI_Finalize();
}
