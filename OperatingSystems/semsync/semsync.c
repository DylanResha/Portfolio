// Dylan Resha
// CSC 460 
// 2/28/2020
// semsync forklift
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>


int main(int argc, char *argv[])
{
int     N, i, sem_id, procID=0;
int     loopCount = 5;

	// checks to see if the correct number of args are input
	if( argc == 2 ) {
		N = atoi(argv[1]);

//  Ask OS for semaphores.
sem_id = semget (IPC_PRIVATE, N, 0777);

//  See if you got the request.
if (sem_id == -1)
   {
    printf("%s","SemGet Failed.\n");
    return (-1);
   }

		// checks to see if the input is in the range     
		if(N <= 26 && N >= 1 )
		{
//  Initialize your sems.
 semctl(sem_id, 0, SETVAL, 1);
 
			for( i=1; i<N; i++){
      
        semctl(sem_id, i, SETVAL, 0);
        }
        
			//creates N processes  
			for( i=0; i<N-1; i++)
			{
     
				if(fork() == 0 )procID++;
        else break;	               
			}
      int nextProcID = (procID+1)%N;
			//let each process run 5 times           
       for (i=0; i< loopCount; i++)
       {
      
         p(procID,sem_id);
         printf("%c\t%d\n",procID+65,getpid());
         v(nextProcID,sem_id);
       }              
		}

		//less than 1 or more than 26        
		else{
			printf("outside of range.\n");
		} 
	}

	//argc error handle   
	// to many arguments   
	else if( argc > 2 ) {
		printf("Too many arguments supplied.\n");
	}
	// only command no args   
	else {
		printf("One argument expected.\n");
	}
    sleep(2);
  semctl(sem_id, 0, IPC_RMID, 0);
        
}

p(int s,int sem_id)
{
struct sembuf sops;

sops.sem_num = s;
sops.sem_op = -1;
sops.sem_flg = 0;
if((semop(sem_id, &sops, 1)) == -1) printf("%s", "'P' error\n");
}

v(int s, int sem_id)
{
struct sembuf sops;

sops.sem_num = s;
sops.sem_op = 1;
sops.sem_flg = 0;
if((semop(sem_id, &sops, 1)) == -1) printf("%s","'V' error\n");
}
