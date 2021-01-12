#ifndef GLOB
#define GLOB
   #include "includes.h"
   double t=0.0;
   double theta=M_PI/4.0;
   double omega=0.0;
   unsigned frames = 0;
   int oldTime=0;

glm::vec3 camPos = glm::vec3(0.8f, 0.0f, 2.0f); 
glm::vec3 camTar = glm::vec3(0.8f, 1.0f, 2.0f);
glm::vec3 camDir = glm::normalize(camPos-camTar);
glm::vec3 up = glm::vec3(0.0f, 0.0f, 1.0f);

float speed = 0.1;
float rotAngle = 180.0;

#endif
