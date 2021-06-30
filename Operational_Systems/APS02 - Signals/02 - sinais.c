#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int i = 0;

void ALARM(int signum){
	printf("\n HASTA LA VISTA BABY!\n");
	sleep(3);
	raise(SIGKILL);
}


void CNTRL_C(int signum)
{
  	i++;
  
  	if(i >= 10)
  	{
  		char out;

  		printf("\n REALLY EXIT BRO? (Y/N)");
  		alarm(5);
  		scanf(" %c",&out);
		
		if(out == 'Y' || out == 'y')
		{
			alarm(0);
			sleep(2);
			raise(SIGKILL);
		}
		else if(out == 'N' || out == 'n')
		{
			alarm(0);
			i = 0;
		}
		else
		{
			printf("\n Entrada Inválida\n");
		}
  	}
	
}

void CNTRL_Z(int signum)
{
    printf("\nCTRL+C Emitiu %d sinais\n", i);
    return;
}

int main(void)
{
    signal(SIGINT, CNTRL_C);
    signal(SIGTSTP, CNTRL_Z);
    signal(SIGALRM,ALARM);

    for(;;);
}

