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
int fileLet;
int count = 0;


// checks to see if the correct number of args are input
  if( argc == 2 ) {
     N = atoi(argv[1]);
     
     
// checks to see if the input is in the range     
     if(N <= 26 && N >= 1 )
      {
      FILE *fopen(), *fp;
      if((fp=fopen("syncfile","w"))== NULL){
        printf("\nFailed to open File to write\n");
        return 0;
      }
      fprintf(fp,"%d",65);
      fclose(fp);
      
         curLet = 'A';
         int i;
         //int count=0;
       //creates N processes  
         for( i=1; i<N; i++)
           {
             if(fork() == 0 )break;
             curLet++;                
           }
         
          
          while(fileLet < (N*5)+64){
           //printf("%s\n","in inner");             
              if((fp=fopen("syncfile","r"))== NULL){
                    printf("\nFailed to open File to write\n");
                    return 0;
                  }
                  fscanf(fp,"%d",&fileLet);
                  fclose(fp);
                  
                  if(fileLet%N == (int)curLet%N &&(fileLet < (N*5)+65)){
                      printf("%c:%d\n",curLet,getpid());
                       fileLet++;
                    if((fp=fopen("syncfile","w"))== NULL){
                      printf("\nFailed to open File to write\n");
                      return 0;
                      }
                  fprintf(fp,"%d",fileLet);
                  fclose(fp);                         
                  }                 
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
return 0;   
}