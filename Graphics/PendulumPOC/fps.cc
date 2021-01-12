#include "includes.h"
#include "globals.h"

void checkFPS(int val){

  if(0!=val){
   printf("The Framerate is %d fps.", frames);
  }

  frames=0;
  glutTimerFunc(1000,checkFPS,1);
}
