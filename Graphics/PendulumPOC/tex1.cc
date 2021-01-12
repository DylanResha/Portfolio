//
//
//  Texturing Example Using SOIL and GLEW with Direct Rendering 
//
//  Andrew J. Pounds, Ph.D.
//  Department of Computer Science 
//  Mercer University
//  Spring 2017
//
//  compile with:
//
//  g++  tex1.cc -lGL -lGLU -lGLEW -lglut libSOIL.a
//

#include <cmath>
#include <string>
#include <stdio.h>

#include <GL/glew.h>         // <---- This gives us access to more modern OpenGL stuff,
                             //       in includes GL and GLU
#include <GL/glut.h>

#include "SOIL.h"            // <---- This is our image loading library

// A Simple reshape function
void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(40.0, (GLfloat) w/(GLfloat) h, 1.0, 40.0);
   glMatrixMode(GL_MODELVIEW);
}


void display(){

    GLuint myTexture;     // <-- Stores the ID of the texture 
    unsigned char* image; // <-- Stores image information
    int width, height;    // <-- Used by SOIL

    glClearColor(0.0,0.0,0.0,0.0);

// Set up a 3D Viewing perspective pulled back from the X-Y plane looking down
// at the first quadrant.

    glLoadIdentity();
    glClear (GL_COLOR_BUFFER_BIT);

    gluLookAt(  5.0,   5.0,   20.0,  // Eye
                5.0,   5.0, 0.0,  // Center
                0.0,   -1.0, 0.0); // Up

// Enable Texturing and the Depth Buffer
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);

#ifdef DEBUG
    printf( "OpenGL Version: %s\n", glGetString(GL_VERSION)); 
#endif

// Here we will generate a texture ID, give it a name then we bind it to
// a structure type.  Once I bind a texture all subsequent operations
// pertain to that texture until I either unbind it or bind another texture. 
    glGenTextures(1, &myTexture);  
    glBindTexture(GL_TEXTURE_2D, myTexture); 

// Here I am setting up filters and functions to be used for the MIPMAPS.  Rather than
// go into the details of MIPMAPS here, take a look at your text of just read
// the OpenGL docs.  The important thing is that these items get stored in the
// data structure along with the texture.  
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

// Now we call one of the SOIL library functions to load the image data into a character array.
// glTexImage2D takes the data and coverts it into the internal format used by OpenGL.
    image = SOIL_load_image("./textures/smiley_256_256.jpg", &width, &height, 0, SOIL_LOAD_RGB); 
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

// glGenerateMipmap is a function that, at this time, is accessed via GLEW.  It builds the various
// MIPMAP representations of the texture and stores them in the object as well. 
    glGenerateMipmap(GL_TEXTURE_2D); 

// Be nice and clean up after yourself.
    SOIL_free_image_data(image);

// Since we have been working with direct rendering, I wanted to give you an example that used 
// some modern aspects of texturing but still used direct rendering.  In the following example 
// I create my Texture Coordinates on the left (they vary between 0 and 1) and the vertices for
// my polygon on the right.  

    glBegin(GL_POLYGON);

      glTexCoord2d( 0.0, 0.0);   glVertex2d(  0.0,  0.0 );
      glTexCoord2d( 0.0, 0.5);   glVertex2d(  0.0, 10.0 );
      glTexCoord2d( 1.0, 0.5);   glVertex2d( 10.0, 10.0 );
      //glTexCoord2d( 1.0, 0.0);   glVertex2d( 10.0,  0.0 );

    glEnd();

// Flush the buffer
    glFlush();
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_DEPTH_TEST);

}


int main(int argc, char** argv) {
    int windowsize;
    windowsize=800;    
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH  );
    glutInitWindowSize (windowsize, windowsize); 
    glutCreateWindow("Texture Example");
// After creating the window call glewInit so context will be initialized. Otherwise
// you will probabaly see segfaults.
    glewInit();
    glClearColor(0.0,0.0,0.0,0.0);
    glLoadIdentity();
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    
} 
