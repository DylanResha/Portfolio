// Dylan Resha
// CSC 460 
// 2/19/2020
// fast sync forklift
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

#define TURN shmem[0]
int main(int argc, char *argv[])
{
int N, shmid, *shmem;
char curLet;

// the first Process 
 int firstID = getpid();
// Get Shared Memory and ID 
shmid  =  shmget(IPC_PRIVATE, sizeof(int), 0770);
if (shmid == -1)
    {
    printf("Could not get shared memory.\n");
    return(0);
    }
//   Attach to the shared memory 
 shmem = (int *) shmat(shmid, NULL, SHM_RND);
//  Initialize the shared memory 
TURN = 0;
// checks to see if the correct number of args are input
  if( argc == 2 ) {
     N = atoi(argv[1]);
         
// checks to see if the input is in the range     
     if(N <= 26 && N >= 1 )
      {

         curLet = 'A';
         int i;
         
       //creates N processes  
         for( i=1; i<N; i++)
           {
             if(fork() == 0 )break;
             curLet++;                
           }
//let each process run 5 times           
for (i = 0; i < 5; i++)
   {
        while(TURN != (int)curLet-65);  // busy wait for Child
        printf("%c:%d\n",curLet,getpid());
        TURN = (TURN + 1) % N;
   }               
  }
  
//less than 1 or more than 26        
      else{
        printf("outside of range.\n");
      }
      sleep(1); 
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

//  Detach and clean-up the shared memory  

if (shmdt(shmem) == -1 ) printf("shmgm: ERROR in detaching.\n");

if (firstID == getpid())         // ONLY need one process to do this
if ((shmctl(shmid, IPC_RMID, NULL)) == -1)
    printf("ERROR removing shmem.\n");


return 0;   
}