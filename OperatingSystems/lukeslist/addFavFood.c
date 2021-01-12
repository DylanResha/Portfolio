//Dylan Resha
//CSC 460
//2-21-2020
//Lukes List Food

#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <sys/shm.h>
#include <string.h>

struct bbStruct
{
        int id;
        char name[20];
        int favNum;
        char favFood[30];
};

main(int argc, char *argv[])
{
int shmid,i;
struct bbStruct *shmem;
FILE *fopen(), *fp;


/*****  Open File to hold Shared Memory ID  *****/

if((fp = fopen("/pub/csc460/bb/BBID.txt","r")) == NULL)
    {
    printf("watch:  could not open file.\n");
    return(0);
    }


/*****  Get Shared Memory ID and close file  *****/

    fscanf(fp,"%d",&shmid);
    fclose(fp);

/****   Attach to the shared memory  ******/

shmem = (struct bbStruct *) shmat(shmid, NULL, SHM_RND);

for (i=0;i<21;i++)
    {
      if(shmem->id == 14)
        {
          strcpy(shmem->favFood,argv[1]);
        }       
       shmem++;
    }
}