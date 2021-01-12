#ifndef SHOW_FPS
#define SHOW_FPS

#include "includes.h"
#include "globals.h"
#include <stdio.h>

void drawString(GLuint x, GLuint y, void *font, const char* string)
{
 const char *c;
 glRasterPos2i(x, y);

  for(c=string; *c!='\0'; c++)
	glutBitmapCharacter(font, *c);

}

void showFPS(){
 static float fps;

 frames++;
 int currentTime=glutGet(GLUT_ELAPSED_TIME);
 
 if (currentTime - oldTime > 1000){
  fps = frames*1000.0/(currentTime-oldTime);
  oldTime = currentTime;
  frames = 0;
 }

 char *charString = (char*) malloc(12*sizeof(char));
 sprintf(charString, "FPS: %6.1f", fps);

 glMatrixMode(GL_PROJECTION);
 glPushMatrix();
 glLoadIdentity();
 gluOrtho2D(0.0, 500.0, 0.0, 500.0);

 glMatrixMode(GL_MODELVIEW);
 glPushMatrix();
 glLoadIdentity();

 glColor3f(255,255,0);
 drawString(50,50,GLUT_BITMAP_HELVETICA_12,charString);

 glPopMatrix();
 glMatrixMode(GL_PROJECTION);
 glPopMatrix();
 glMatrixMode(GL_MODELVIEW);

 free(charString);

}
void showFPP(){
static int period_start;
static int period_stop;
static double startTime;
static double stopTime;
static double period;
static float fpp;
static float fps;
/*
if(!period_stop&& !period_start && (omega*theta < 0.0)){
 period_start = 1;
 startTime=t;
}

else if(!period_stop && period_start && (omega*theta < 0.0)){
 period_stop = 1;
 stopTime=t;
 period = fabs(stopTime-startTime)*2;
}

else if(period_stop && period_start){
period_start = NULL;
period_stop = NULL;
}
*/
//printing the period to the screen
 char *charString = (char*) malloc(12*sizeof(char));
 period = 2*M_PI*sqrt(1/9.8);
 sprintf(charString, "Period: %6.1f", period);

 glMatrixMode(GL_PROJECTION);
 glPushMatrix();
 glLoadIdentity();
 gluOrtho2D(0.0, 500.0, 0.0, 500.0);

 glMatrixMode(GL_MODELVIEW);
 glPushMatrix();
 glLoadIdentity();

 glColor3f(255,255,0);
 drawString(50,35,GLUT_BITMAP_HELVETICA_12,charString);

 glPopMatrix();
 glMatrixMode(GL_PROJECTION);
 glPopMatrix();
 glMatrixMode(GL_MODELVIEW);

 free(charString);
 

 
//printing the frames per period to the screen

 int currentTime=glutGet(GLUT_ELAPSED_TIME);
 
 if (currentTime - oldTime > 1000){
  fps = frames*1000.0/(currentTime-oldTime);
 }

 fpp = fps*period;

 char *charString2 = (char*) malloc(12*sizeof(char));
 sprintf(charString2, "FPP: %6.1f", fpp);

 glMatrixMode(GL_PROJECTION);
 glPushMatrix();
 glLoadIdentity();
 gluOrtho2D(0.0, 500.0, 0.0, 500.0);

 glMatrixMode(GL_MODELVIEW);
 glPushMatrix();
 glLoadIdentity();

 glColor3f(255,255,0);
 drawString(50,20,GLUT_BITMAP_HELVETICA_12,charString);

 glPopMatrix();
 glMatrixMode(GL_PROJECTION);
 glPopMatrix();
 glMatrixMode(GL_MODELVIEW);

 free(charString2);
}

#endif
