#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "mpi.h"
char Nome[]={'G','U','S','T','A','V','O'};
void main(int argc, char * argv[]){
	int my_rank;            /* rank of process */
	int p;                  /* number of processes */
	int source;             /* rank of sender */
	int dest;               /* rank of receiver */
	int tag = 0;            /* tag for messages */
	//char message[100];      /* storage for message */
	MPI_Status status;      /* return status for receive */

	/* Start up MPI */
	MPI_Init(&argc, &argv);
	/* Find out process rank */
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	/* Find out number of processes */
	MPI_Comm_size(MPI_COMM_WORLD, &p);


	if(my_rank==0){//cozinheiro
		int Num_Javalis[1]={14};
		int Recebido[1];
		while(1){
			MPI_Recv(Recebido,1,MPI_INT,1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
			MPI_Send(Num_Javalis,1,MPI_INT,1,0,MPI_COMM_WORLD);
		}
	}
	if(my_rank==1){//mesa
		int Javalis[1]={0};
		int Rank[1];
		int Recebidos[1];
		while(1){
			if (Javalis[0]==0){
				MPI_Send(Javalis,1,MPI_INT,0,0,MPI_COMM_WORLD);
				printf("Acordando o cozinheiro------------------------\n");
				MPI_Recv(Javalis,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
			}
			else{
				MPI_Recv(Recebidos,7,MPI_INT,MPI_ANY_SOURCE,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
				printf("Mesa recebeu: %c e esta enviando %d Javalis\n",Nome[Recebidos[0]-2],Javalis[0]);
				MPI_Send(Javalis,1,MPI_INT,Recebidos[0],0,MPI_COMM_WORLD);
				Javalis[0]--;
			}
		}
	}
	else{//Gauleses
		int qualJavali[1];
		int rank[1]={my_rank};
		while(1){
			MPI_Send(rank,1,MPI_INT,1,0,MPI_COMM_WORLD);
			MPI_Recv(qualJavali,1,MPI_INT,1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
			printf("O Gaules %c comeu o javali %d\n",Nome[my_rank-2],qualJavali[0]);
			sleep(2);
		}
	}
	/* Shut down MPI */
	MPI_Finalize();
}
