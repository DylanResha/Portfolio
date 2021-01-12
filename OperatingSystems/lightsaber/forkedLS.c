// Dylan Resha
// CSC 460 
// 1/24/2020
// The Forked Lightsaber
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
int N;
  if( argc == 2 ) {
     N = atoi(argv[1]);
     if(N <= 5 && N >= 1 )
      {
       printf("%-10s","GEN\tPID\tPPID\n");
         int currentGen = 0;
         int i;
         for( i=0; i<N; i++)
            {

              if(fork() == 0){
              i= -1;
              currentGen++;
              N--;                      
              }

            }
            printf("%d\t%d\t%d\n",currentGen,getpid(),getppid());
            sleep(1); 
        }
        
      else{
        printf("outside of range.\n");
      }
     
   }
  else if( argc > 2 ) {
      printf("Too many arguments supplied.\n");
   }
  else {
      printf("One argument expected.\n");
   }
return 0;   
}
