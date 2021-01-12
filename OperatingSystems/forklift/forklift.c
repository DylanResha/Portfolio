// Dylan Resha
// CSC 460 
// 2/3/2020
// square forklift
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
int N;
char curLet;

// checks to see if the correct number of args are input
  if( argc == 2 ) {
     N = atoi(argv[1]);
// checks to see if the input is in the range     
     if(N <= 26 && N >= 1 )
      {
         curLet = 'A';
         int i;
         int j;
       //creates N processes  
         for( i=1; i<N; i++)
           {
             if(fork() == 0 )break;
             curLet++;                
           }
        //prints each process N times   
         for(j=0; j<N;j++)
           {
             printf("%c:%d\n",curLet,getpid());
             sleep(1); 
           }
        }
//less than 1 or more than 26        
      else{
        printf("outside of range.\n");
      } 
   }
// to many arguments   
  else if( argc > 2 ) {
      printf("Too many arguments supplied.\n");
   }
// only command no args   
  else {
      printf("One argument expected.\n");
   }
return 0;   
}