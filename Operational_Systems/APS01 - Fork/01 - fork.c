#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main (int argc, char *argv[]) {
    pid_t childpid = 0; // Cria A
    int i, n;

    fprintf(stderr, " A Nascendo -> process ID:%ld  parent ID:%ld\n",(long)getpid(), (long)getppid());
    
    if((childpid = fork()) == 0)  ///Cria B
    {  
        fprintf(stderr, " B Nascendo -> process ID:%ld  parent ID:%ld\n",(long)getpid(), (long)getppid());
    
        if((childpid = fork()) == 0) //Cria C
        {  
            fprintf(stderr, " C Nascendo-> process ID:%ld  parent ID:%ld\n",(long)getpid(), (long)getppid()); 

            return 0;   
        }
        else
        {
            wait();
	    //Mata C
	    fprintf(stderr, " C Morrendo-> process ID:%ld  parent ID:%ld\n",(long)getpid(), (long)getppid()); 
            return 0;
        }

    }
    else
    {

        wait();
	//Mata B
        fprintf(stderr, " B Morrendo-> process ID:%ld  parent ID:%ld\n",(long)getpid(), (long)getppid());

        if((childpid = fork()) == 0) //Cria D
        {  
            fprintf(stderr, " D Nascendo-> process ID:%ld  parent ID:%ld\n",(long)getpid(), (long)getppid()); 
            

            return 0;;
        }
        else
        {
            wait();
	    //Mata D
	    fprintf(stderr, " D Morrendo-> process ID:%ld  parent ID:%ld\n",(long)getpid(), (long)getppid()); 

            if((childpid = fork()) == 0)  ///Cria E
            {  
                fprintf(stderr, " E Nascendo -> process ID:%ld  parent ID:%ld\n",(long)getpid(), (long)getppid());
            
                if((childpid = fork()) == 0) //Cria F
                {  
                    fprintf(stderr, " F Nascendo-> process ID:%ld  parent ID:%ld\n",(long)getpid(), (long)getppid()); 
                    
                    if((childpid = fork()) == 0) //Cria G
                    {  
                        fprintf(stderr, " G Nascendo-> process ID:%ld  parent ID:%ld\n",(long)getpid(), (long)getppid()); 
                        
                        return 0;   
                    }
                    else
                    {
                        wait();
			
			fprintf(stderr, " G Morrendo-> process ID:%ld  parent ID:%ld\n",(long)getpid(), (long)getppid());  
                        return 0;
                    }   
                }
                else
                {
                    wait();

                    fprintf(stderr, " F Morrendo-> process ID:%ld  parent ID:%ld\n",(long)getpid(), (long)getppid());
                    return 0;
                }
            }
	    else
            {
                wait();
                        
                fprintf(stderr, " E Morrendo-> process ID:%ld  parent ID:%ld\n",(long)getpid(), (long)getppid());
                return 0;
            }
        }  
    }
}
