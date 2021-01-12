#include "includes.h"
#include "globals.h"



void glutSleep(int millisecondsToWait){

	int startTime=glutGet(GLUT_ELAPSED_TIME);

	do{/*waiting*/}
	while((glutGet(GLUT_ELAPSED_TIME)-startTime)<millisecondsToWait);

}

void table(void)
{
  

///////////////////////////////
//table

  //top
	glPushMatrix();
	//glBindTexture(GL_TEXTURE_2D, textureID[57]);
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.4, 0.4, 1.0);
	  glBegin ( GL_POLYGON );
		//glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0.0, 0.0, 2.0 );
		//glTexCoord2d(0.0, 1.0);
		glVertex3f ( 3.0, 0.0, 2.0 );	
		//glTexCoord2d(1.0, 1.0);
		glVertex3f ( 3.0, 5.0, 2.0 );
		//glTexCoord2d(1.0, 0.0);
		glVertex3f ( 0.0, 5.0, 2.0 );
	  glEnd();
	glPopMatrix();

 //bottom
	glPushMatrix();
	//glBindTexture(GL_TEXTURE_2D, textureID[57]);
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(1.0, 0.4, 0.4);
	  glBegin ( GL_POLYGON );
		//glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0.0, 0.0, 1.8 );
		//glTexCoord2d(0.0, 1.0);
		glVertex3f ( 3.0, 0.0, 1.8 );	
		//glTexCoord2d(1.0, 1.0);
		glVertex3f ( 3.0, 5.0, 1.8 );
		//glTexCoord2d(1.0, 0.0);
		glVertex3f ( 0.0, 5.0, 1.8 );
	  glEnd();
	glPopMatrix();

  //long sides
	//left
	glPushMatrix();
	//glBindTexture(GL_TEXTURE_2D, textureID[57]);
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(1.0, 0.0, 0.0);
	  glBegin ( GL_POLYGON );
		//glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0.0, 0.0, 2.0 );
		//glTexCoord2d(0.0, 1.0);
		glVertex3f ( 0.0, 0.0, 1.8 );	
		//glTexCoord2d(1.0, 1.0);
		glVertex3f ( 0.0, 5.0, 1.8 );
		//glTexCoord2d(1.0, 0.0);
		glVertex3f ( 0.0, 5.0, 2.0 );
	  glEnd();
	glPopMatrix();
	//right
	glPushMatrix();
	//glBindTexture(GL_TEXTURE_2D, textureID[57]);
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(1.0, 0.0, 0.0);
	  glBegin ( GL_POLYGON );
		//glTexCoord2d(0.0, 0.0);
		glVertex3f ( 3.0, 0.0, 2.0 );
		//glTexCoord2d(0.0, 1.0);
		glVertex3f ( 3.0, 0.0, 1.8 );	
		//glTexCoord2d(1.0, 1.0);
		glVertex3f ( 3.0, 5.0, 1.8 );
		//glTexCoord2d(1.0, 0.0);
		glVertex3f ( 3.0, 5.0, 2.0 );
	  glEnd();
	glPopMatrix();

  //short sides
	//front
	glPushMatrix();
	//glBindTexture(GL_TEXTURE_2D, textureID[57]);
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(1.0, 0.0, 0.0);
	  glBegin ( GL_POLYGON );
		//glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0.0, 0.0, 2.0 );
		//glTexCoord2d(0.0, 1.0);
		glVertex3f ( 0.0, 0.0, 1.8 );	
		//glTexCoord2d(1.0, 1.0);
		glVertex3f ( 3.0, 0.0, 1.8 );
		//glTexCoord2d(1.0, 0.0);
		glVertex3f ( 3.0, 0.0, 2.0 );
	  glEnd();
	glPopMatrix();
	//back
	glPushMatrix();
	//glBindTexture(GL_TEXTURE_2D, textureID[57]);
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(1.0, 0.0, 0.0);
	  glBegin ( GL_POLYGON );
		//glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0.0, 5.0, 2.0 );
		//glTexCoord2d(0.0, 1.0);
		glVertex3f ( 0.0, 5.0, 1.8 );	
		//glTexCoord2d(1.0, 1.0);
		glVertex3f ( 3.0, 5.0, 1.8 );
		//glTexCoord2d(1.0, 0.0);
		glVertex3f ( 3.0, 5.0, 2.0 );
	  glEnd();
	glPopMatrix();


  //legs
   //leg 1
    glPushMatrix();
    glTranslated(0.2, 0.2, 0.0); 
    glColor3f (0.0,1.0,1.0);
    gluCylinder(gluNewQuadric(), 
            (GLdouble) 0.1,
            (GLdouble) 0.1,
            (GLdouble) 1.8,
            (GLint)    40,
            (GLint)    40 );
    glPopMatrix();
   //leg 2
    glPushMatrix();
    glTranslated(2.8, 0.2, 0.0); 
    glColor3f (0.0,1.0,1.0);
    gluCylinder(gluNewQuadric(), 
            (GLdouble) 0.1,
            (GLdouble) 0.1,
            (GLdouble) 1.8,
            (GLint)    40,
            (GLint)    40 );
    glPopMatrix();
   //leg 3
    glPushMatrix();
    glTranslated(2.8, 4.8, 0.0); 
    glColor3f (0.0,1.0,1.0);
    gluCylinder(gluNewQuadric(), 
            (GLdouble) 0.1,
            (GLdouble) 0.1,
            (GLdouble) 1.8,
            (GLint)    40,
            (GLint)    40 );
    glPopMatrix();
   //leg 4
    glPushMatrix();
    glTranslated(0.2, 4.8, 0.0); 
    glColor3f (0.0,1.0,1.0);
    gluCylinder(gluNewQuadric(), 
            (GLdouble) 0.1,
            (GLdouble) 0.1,
            (GLdouble) 1.8,
            (GLint)    40,
            (GLint)    40 );
    glPopMatrix();
///////////////////////////////
}

void drawPen(void){
glPushMatrix();

    // This should be to draw a cylinder horizontal support
    glPushMatrix();
    glTranslated(0.0, 0.0, 5.0);  
    glRotatef(-90.0, -1.0, 0.0, 0.0);  
    glColor3f (1.0,0.0,1.0);
    gluCylinder(gluNewQuadric(), 
            (GLdouble) 0.1,
            (GLdouble) 0.1,
            (GLdouble) 4.0,
            (GLint)    20,
            (GLint)    20 );
    glPopMatrix();


    // This should be to draw a cylinder back hold
    glPushMatrix();
    glTranslated(0.0, 0.0, 0.0); 
    glColor3f (0.0,1.0,1.0);
    gluCylinder(gluNewQuadric(), 
            (GLdouble) 0.1,
            (GLdouble) 0.1,
            (GLdouble) 5.0,
            (GLint)    40,
            (GLint)    40 );
    glPopMatrix();

    // This should be to draw a cylinder pendulum
    glPushMatrix();
    glTranslated(0.0,-4.0,5.0);
    glRotatef(90.0,0.0,0.0,1.0);
    glRotatef(180.0,1.0,0.0,0.0); 
    glRotated((double)180*theta/M_PI,1,0,0);
    glRotated((double)180*theta/M_PI,0,0,1);    
    glColor3f (0.0,0.0,1.0);
    gluCylinder(gluNewQuadric(), 
            (GLdouble) 0.1,
            (GLdouble) 0.1,
            (GLdouble) 2.0,
            (GLint)    40,
            (GLint)    40 );
    glPopMatrix();



    // This should draw a red sphere 
    glPushMatrix();
     glTranslated(0.0,-4.0,5.0);
     glRotatef(90.0,0.0,0.0,1.0);
      glRotated((double)180*theta/M_PI,1,0,0);
      glRotated((double)180*theta/M_PI,0,0,1);
     glTranslated(0.0, 0.0, -2.0);
    glColor3f (1.0,0.0,0.0);
    gluSphere(gluNewQuadric(), 
             (GLdouble) 0.5,
             (GLint)     10,
             (GLint)     10 );

    glPopMatrix();

//cylinder base
 glPushMatrix();
  glTranslated(0.0, 0.0, 0.25);
  glColor3f (0.0,1.0,0.0);
  gluDisk(gluNewQuadric(), 
    (GLdouble) 0,
    (GLdouble) 2,
    (GLint)    20,
    (GLint)    10);
 glPopMatrix();
glPopMatrix();


 glPushMatrix();
  glTranslated(0.0, 0.0, 0.0);
  glColor3f (0.0,0.8,0.0);
  gluCylinder(gluNewQuadric(), 
    (GLdouble) 2,
    (GLdouble) 2,
    (GLdouble) 0.25,
    (GLint)    20,
    (GLint)    10 );
 glPopMatrix();
glPopMatrix();

}

void display(void)
{

 extern double theta;
   // printf("%f\n",theta);
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glLoadIdentity();   // Call this before setting the viewing position 

    // We are going to set our position to be down the Y-Axis looking at the
    // center of the coordinate frame.  The positive Z-Axis will be up.

    gluLookAt( (double)camPos.x, (double)camPos.y, (double)camPos.z, //eye
            (double) camTar.x, (double) camTar.y, (double) camTar.z, //center
            (double) up.x, (double) up.y, (double) up.z);// up




    glEnable(GL_DEPTH_TEST);

    glColor3f(0.0,1.0,0.0);


///////////////////////////////
//Room
//floor
	glPushMatrix();
	//glBindTexture(GL_TEXTURE_2D, textureID[57]);
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.8);
	  glBegin ( GL_POLYGON );
		//glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0.0, 0.0, 0.0 );
		//glTexCoord2d(0.0, 1.0);
		glVertex3f ( 20.0, 0.0, 0.0 );	
		//glTexCoord2d(1.0, 1.0);
		glVertex3f ( 20.0, 20.0, 0.0 );
		//glTexCoord2d(1.0, 0.0);
		glVertex3f ( 0.0, 20.0, 0.0 );
	  glEnd();
	glPopMatrix();

//ceiling
	glPushMatrix();
	//glBindTexture(GL_TEXTURE_2D, textureID[57]);
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.6, 0.8);
	  glBegin ( GL_POLYGON );
		//glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0.0, 0.0, 10.0 );
		//glTexCoord2d(0.0, 1.0);
		glVertex3f ( 20.0, 0.0, 10.0 );	
		//glTexCoord2d(1.0, 1.0);
		glVertex3f ( 20.0, 20.0, 10.0 );
		//glTexCoord2d(1.0, 0.0);
		glVertex3f ( 0.0, 20.0, 10.0 );
	  glEnd();
	glPopMatrix();

//left wall
	glPushMatrix();
	//glBindTexture(GL_TEXTURE_2D, textureID[57]);
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.8, 0.8);
	  glBegin ( GL_POLYGON );
		//glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0.0, 0.0, 0.0 );
		//glTexCoord2d(0.0, 1.0);
		glVertex3f ( 0.0, 0.0, 10.0 );	
		//glTexCoord2d(1.0, 1.0);
		glVertex3f ( 0.0, 20.0, 10.0 );
		//glTexCoord2d(1.0, 0.0);
		glVertex3f ( 0.0, 20.0, 0.0 );
	  glEnd();
	glPopMatrix();

//right wall
	glPushMatrix();
	//glBindTexture(GL_TEXTURE_2D, textureID[57]);
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.6, 0.8, 0.8);
	  glBegin ( GL_POLYGON );
		//glTexCoord2d(0.0, 0.0);
		glVertex3f ( 20.0, 0.0, 0.0 );
		//glTexCoord2d(0.0, 1.0);
		glVertex3f ( 20.0, 0.0, 10.0 );	
		//glTexCoord2d(1.0, 1.0);
		glVertex3f ( 20.0, 20.0, 10.0 );
		//glTexCoord2d(1.0, 0.0);
		glVertex3f ( 20.0, 20.0, 0.0 );
	  glEnd();
	glPopMatrix();

//back wall
	glPushMatrix();
	//glBindTexture(GL_TEXTURE_2D, textureID[57]);
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.6);
	  glBegin ( GL_POLYGON );
		//glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0.0, 20.0, 0.0 );
		//glTexCoord2d(0.0, 1.0);
		glVertex3f ( 0.0, 20.0, 10.0 );	
		//glTexCoord2d(1.0, 1.0);
		glVertex3f ( 20.0, 20.0, 10.0 );
		//glTexCoord2d(1.0, 0.0);
		glVertex3f ( 20.0, 20.0, 0.0 );
	  glEnd();
	glPopMatrix();

//front wall
	glPushMatrix();
	//glBindTexture(GL_TEXTURE_2D, textureID[57]);
	 glPolygonMode(GL_FRONT, GL_FILL);
	 glPolygonMode(GL_BACK, GL_FILL);
	 glColor3f(0.8, 0.8, 0.6);
	  glBegin ( GL_POLYGON );
		//glTexCoord2d(0.0, 0.0);
		glVertex3f ( 0.0, 0.0, 0.0 );
		//glTexCoord2d(0.0, 1.0);
		glVertex3f ( 0.0, 0.0, 10.0 );	
		//glTexCoord2d(1.0, 1.0);
		glVertex3f ( 20.0, 0.0, 10.0 );
		//glTexCoord2d(1.0, 0.0);
		glVertex3f ( 20.0, 0.0, 0.0 );
	  glEnd();
	glPopMatrix();
//////////////////////////////////////
// pendulumn locations

//pen1
glPushMatrix();
 glTranslated(10.5, 10.5, 2.0);
 glScaled(0.1, 0.1, 0.1);
 drawPen();
glPopMatrix();
//pen2
glPushMatrix();
 glTranslated(12.5, 10.5, 2.0);
 glScaled(0.1, 0.1, 0.1);
 drawPen();
glPopMatrix();
//pen3
glPushMatrix();
 glTranslated(11.5, 13.0, 2.0);
 glScaled(0.3, 0.3, 0.3);
 drawPen();
glPopMatrix();
//pen4
glPushMatrix();
 glTranslated(8.0, 13.0, 0.0);
 //glScaled(0.3, 0.3, 0.3);
 drawPen();
glPopMatrix();


//table locations

//table 1
glPushMatrix();
  glTranslated(10.0, 10.0, 0.0);
  table();
glPopMatrix();

   
    showFPS();
    showFPP();
    glutSwapBuffers();
//#ifdef SYNC
    float desired = 1/60;
    glutSleep(desired);
//#endif


}
