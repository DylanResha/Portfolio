//Dylan Resha

#include <cmath>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include <vector>

using namespace std;

#define WINDOW_MAX 1000
#define WINDOW_MIN 0
#define VIEWPORT_MAX 900
#define VIEWPORT_MIN 100
#define MAX 2520

/* Define the vertex data type */
typedef struct vertex { 
    float x;
    float y;
    float z;
    float w;
} vertex;


//////////////////////////////////////////////////////////////////
//struct that holds two points to creat a line
struct line{
	vertex a,b;

};
//////////////////////////////////////////////////////////////////
//struct that holds 3 points to make a triangle
struct triangle{
	vertex v1,v2,v3;
};

//vectors to hold my lists in
vector<vertex> coords;
vector<line> lineList;
vector<triangle> triList;


/* Define these two variables to have a global scope */
float DELTA_SPIN = 0.0;
float SPIN  = 0.0;
float SCALE = 1.0; 
float rp = 1.0;
float tX = -WINDOW_MAX/2;
float tY = -WINDOW_MAX/2;

void vmatm (int SIZE, float *pA, float *pB)

// Matrix-vector multiplication
// pA is a pointer to the first element of matrix A
// pB is a pointer to the first element of vector B
// On return, B will contain transformed coordinates
{
   int i, j;
   float temp[4];

   for (i=0; i<SIZE; i++)
             temp[i] = 0.0;

   for (i=0; i < SIZE; i++)
     for (j = 0; j < SIZE; j++)
           temp[i] += *(pA+(i*SIZE+j)) * *(pB+j);
   
   for (i=0; i<SIZE; i++)
         *(pB+i) = temp[i];

}

////////////////////////////////////////////////////////////////


void Intersect(vertex first, vertex second, vertex *clipBoundary,
			  vertex *intersectPt)
{
	if (clipBoundary[0].y == clipBoundary[1].y) {		/*horizontal*/
		intersectPt->y = clipBoundary[0].y;
		intersectPt->x = first.x + (clipBoundary[0].y - first.y) *
			(second.x - first.x) / (second.y - first.y);
	} else {							/*vertical*/
		intersectPt->x = clipBoundary[0].x;
		intersectPt->y = first.y + (clipBoundary[0].x - first.x) *
			(second.y - first.y) / (second.x - first.x);
	}
}

bool Inside(vertex testVertex, vertex *clipBoundary)
{
	if (clipBoundary[1].x > clipBoundary[0].x)	/*bottom*/
		if (testVertex.y >= clipBoundary[0].y)
			return true;
	if (clipBoundary[1].x < clipBoundary[0].x)	/*top*/
		if (testVertex.y <= clipBoundary[0].y)
			return true;
	if (clipBoundary[1].y > clipBoundary[0].y)	/*right*/
		if (testVertex.x <= clipBoundary[1].x)
			return true;
	if (clipBoundary[1].y < clipBoundary[0].y)	/*left*/
		if (testVertex.x >= clipBoundary[1].x)
			return true;
	return false;
}

void Output(vertex newVertex, int *outLength, vertex *outVertexArray)
{
	(*outLength)++;
	outVertexArray[*outLength - 1].x = newVertex.x;
	outVertexArray[*outLength - 1].y = newVertex.y;
}

void SHPC(vertex *inVertexArray, vertex *outVertexArray, int inLength, int *outLength, vertex *clip_boundary)
{
	vertex s, p, i;
	int j;

	*outLength = 0;
	s = inVertexArray[inLength - 1];	/* Start with the last vertex in inVertexArray */
	for (j = 0; j < inLength; j++) {
		p = inVertexArray[j];	/* Now s and p correspond to the vertices in Fig.3.33 */
		if (Inside(p, clip_boundary)) {	/* Cases 1 and 4 */
			if (Inside(s, clip_boundary))
				Output(p, outLength, outVertexArray);	/* Case 1 */
			else {						/* Case 4 */
				Intersect(s, p, clip_boundary, &i);
				Output(i, outLength, outVertexArray);
				Output(p, outLength, outVertexArray);
			}
		} else if(Inside(s, clip_boundary)) {			/* Cases 2 and 3 */
			Intersect(s, p, clip_boundary, &i);		/* Case 2 */
			Output(i, outLength, outVertexArray);
		}							/* No action for case 3 */
		s = p;					/* Advance to next pair of vertices */
	}
}



/////////////////////////////////////////////////////////////////////
//tessalation/////
//////////////////////////////////////////////////////////////////

//method to check if two lines intersect
bool checkIntersect(int m, int l){
              //all x's and y's
	//cout<<"in check intersect"<<endl;
		float x1 = (lineList.at(m).a.x);
		float x2 = (lineList.at(m).b.x);
		float x3 = (lineList.at(l).a.x);
		float x4 = (lineList.at(l).b.x);
		float y1 = (WINDOW_MAX-(lineList.at(m).a.y));
		float y2 = (WINDOW_MAX-(lineList.at(m).b.y));
		float y3 = (WINDOW_MAX-(lineList.at(l).a.y));
		float y4 = (WINDOW_MAX-(lineList.at(l).b.y));
		
		//parts of the matrix needed to find determinate
		float p1= (x3-x1);
		float p2= -(y4-y3);
		float p3= (y3-y1);
		float p4= -(x4-x3);
		float p5= (x2-x1);
		float p6= (y2-y1);
		
		//find nomenator determinate and denominator determinate
		float uaNomDet= ((p1*p2)-(p3*p4));
		float ubNomDet= ((p5*p3)-(p6*p1));
		float denomDet= ((p5*p2)-(p6*p4));
		
	  // finds ua from two determinates		
	  float ua = (uaNomDet/denomDet);	
	  float ub = (ubNomDet/denomDet);
	//if statement to see if the values of ua and ub are between 0 and 1
	if((ua<1&&ua>0)&&(ub<1&&ub>0)){return true;}
	
return false;
}
//////////////////////////////////////////////////////////////////
bool polyIntersect(){

//simple double for loop to check all lines in the list
	for(int i=0; i<lineList.size()-1; i++){
		cout<<"size of line list"<<lineList.size()<<endl;
	   int j = (i+1);	
	 for(int k=0; k<lineList.size()-3; k++){
		//cout<<"in poly intersect loop. k="<<k<<" size of list="<<lineList.size()<<"j="<<j<<endl;
		if(checkIntersect(i,j%lineList.size())){return true;}
		j++;
 	  }
	 }
	

return false;
}
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
void drawNoTess(){

//simple double for loops to fill polygon useing the verticies
for(int i=0; i<coords.size()-1; i++){
 for(int j=1; j<coords.size()-1; j++){     
	glBegin(GL_POLYGON);
	 glVertex2i(coords.at(i).x,coords.at(i).y);
	 glVertex2i(coords.at(i+1).x,coords.at(i+1).y);
	 glVertex2i(coords.at(j%coords.size()).x,coords.at(j%coords.size()).y);
	 glVertex2i(coords.at(j+1%coords.size()).x,coords.at(j+1%coords.size()).y);
    	glEnd();

  }
 }
glFlush();
}

void drawTess(){

//fills in polygon by filling each triangle in the list of triangles
	for(int i=0; i<triList.size(); i++){
	glBegin(GL_POLYGON);
	 glVertex2i(triList.at(i).v1.x,triList.at(i).v1.y);
	 glVertex2i(triList.at(i).v2.x,triList.at(i).v2.y);
	 glVertex2i(triList.at(i).v3.x,triList.at(i).v3.y);
	 glVertex2i(triList.at(i).v1.x,triList.at(i).v1.y);
    	glEnd();
  }
 glFlush();
}
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
bool concave(int v1, int v2, int v3, vector<vertex>& temp){
//checks the concavity of the current 3 vertices

int L1x = (temp.at(v1%temp.size()).x)-(temp.at(v2%temp.size()).x);
int L1y = (temp.at(v1%temp.size()).y)-(temp.at(v2%temp.size()).y);
int L2x = (temp.at(v3%temp.size()).x)-(temp.at(v2%temp.size()).x);
int L2y = (temp.at(v3%temp.size()).y)-(temp.at(v2%temp.size()).y);
//cross product of lines that creat current angle
float cross = (L1x*L2y)-(L2x*L1y);

if(cross<0){return true;}
if(cross==0){temp.erase(temp.begin()+v2);}//removes midpoint if a straight line would be created

return false;
}
//////////////////////////////////////////////////////////////////
//method that checks to see if the new line to be created is inside of the polygon
bool insidePoly(int v0, int v1, int v2, int v3,vector<vertex>& temp){
	
//creating lines for cross and dot products
int L1x = (temp.at(v1%temp.size()).x)-(temp.at(v2%temp.size()).x);
int L1y = (temp.at(v1%temp.size()).y)-(temp.at(v2%temp.size()).y);
int L2x = (temp.at(v3%temp.size()).x)-(temp.at(v2%temp.size()).x);
int L2y = (temp.at(v3%temp.size()).y)-(temp.at(v2%temp.size()).y);
int L3x = (temp.at(v0%temp.size()).x)-(temp.at(v2%temp.size()).x);
int L3y = (temp.at(v0%temp.size()).y)-(temp.at(v2%temp.size()).y);

//cross product of the next angle to see if it is concave
float cross = (L1x*L2y)-(L2x*L1y);

     if(cross>=0){return true;}
     if(cross<0){	
	float numerA = (L1x*L3x)+(L1y*L3y);
	float denomA = sqrt(pow(L1x,2)+pow(L1y,2))*sqrt(pow(L3x,2)+pow(L3y,2));
	float angleA = acos(numerA/denomA);
		
	float numerB = (L1x*L2x)+(L1y*L2y);
	float denomB = sqrt(pow(L1x,2)+pow(L1y,2))*sqrt(pow(L2x,2)+pow(L2y,2));
	float angleB = acos(numerB/denomB);
		
	if(angleA<angleB){return true;}
	
	}
 
 return false;
}
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
//method that finds the area of each triangle that is made, and the total area of the polygon
void triAreas(){
cout<<"Area of all Triangles in Pixels"<<endl;
cout<<"-------------------------------"<<endl;
float totalA=0;
 for(int i=0; i<triList.size();i++){
	float area,Ax,Ay,Bx,By,Cx,Cy;
	Ax= triList.at(i).v1.x;
	Ay= triList.at(i).v1.y;
	Bx= triList.at(i).v2.x;
	By= triList.at(i).v2.y;
	Cx= triList.at(i).v3.x;
	Cy= triList.at(i).v3.y;
	
	area = fabs(((Ax*(By-Cy))+(Bx*(Cy-Ay))+(Cx*(Ay-By)))/2);
	totalA += area;
	cout<<area<<endl;

 }
cout<<"Total Area of Polygon = "<<totalA<<endl;

}
//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
// this method goes through the entire polygon and tessalates by the ear clipping method
void tessalate(){

// filling up a temp list
vector<vertex> temp;
for(int i=0; i<coords.size(); i++){
	temp.push_back(coords.at(i));
}	
  //cout<<coords.size()<<" size"<< endl;
  //cout<<"Line list size: "<<lineList.size()<<endl;
	
  //looping through the temp list of points and checking in groups of 3 to see if they are concave
  //seeing if the line that would be created is inside the polygon
  //if it is inside the polygon then we check to see if the line intersects with any line in the polygon
  //if we have no intersections then we add the vertices to the list of triangles, delete the middle verticies from the temp list, and draw the line

  for(int i=0; i<temp.size()-1; i++){
	//cout<<"in tessallate for loop   i= "<<i<<endl;
   if(concave(i,(i+1)%temp.size(),(i+2)%temp.size(),temp)){
	if(insidePoly(i,(i+1)%temp.size(),(i+2)%temp.size(),(i+3)%temp.size(),temp)){
				
		line newLine;
		newLine.a=temp.at(i);
		newLine.b=temp.at((i+2)%temp.size());
		lineList.push_back(newLine);

	      if(polyIntersect()){
		 lineList.pop_back();
			//cout<<"in polyintersect if"<<endl;
		
		}//end if polyIntersect
		else if(!polyIntersect()){
		   glBegin(GL_LINES);
	 	    glVertex2i(lineList.back().a.x,lineList.back().a.y);
		    glVertex2i(lineList.back().b.x,lineList.back().b.y);
	           glEnd();
		   glFlush();
			 glutSwapBuffers();
		   		    
		   //add triangle
		   triangle tempTri;
		   tempTri.v1 = temp.at(i%temp.size());
		   tempTri.v2 = temp.at((i+1)%temp.size());
                   tempTri.v3 = temp.at((i+2)%temp.size());

			
		   triList.push_back(tempTri);
		   //remove mid point	
		   temp.erase(temp.begin()+i+1);
			i=-1;
			
                 }//end else if	
     	}//end if insidePoly
	
    }//end if concave
   }//end for
//setup to add the last triangle to the list of triangles
triangle lastTri;
lastTri.v1=temp.at(0);
lastTri.v2=temp.at(1);
lastTri.v3=temp.at(2);
triList.push_back(lastTri);
//gives the area of the triangles and the total area
//triAreas();

}







///////////////////////////////////////////////////////////////////
void buildTranslate( float x, float y, float z, float *pA )
// Constructs tranlation matrix to translate along x, y, and z axes
{
     pA[ 0] = 1.0; pA[ 1] = 0.0; pA[ 2] = 0.0; pA[ 3] =   x;
     pA[ 4] = 0.0; pA[ 5] = 1.0; pA[ 6] = 0.0; pA[ 7] =   y;
     pA[ 8] = 0.0; pA[ 9] = 0.0; pA[10] = 1.0; pA[11] =   z;
     pA[12] = 0.0; pA[13] = 0.0; pA[14] = 0.0; pA[15] = 1.0;
}

void buildScale( float *pA, float scale)
{
     pA[ 0] = scale; pA[ 1] = 0.0; pA[ 2] = 0.0; pA[ 3] =   0.0;
     pA[ 4] = 0.0; pA[ 5] = scale; pA[ 6] = 0.0; pA[ 7] =   0.0;
     pA[ 8] = 0.0; pA[ 9] = 0.0; pA[10] = scale; pA[11] =   0.0;
     pA[12] = 0.0; pA[13] = 0.0; pA[14] = 0.0; pA[15] = 1.0;

}

void buildReflect(float rp, float *pA)
{
     pA[ 0] = rp; pA[ 1] = 0.0; pA[ 2] = 0.0; pA[ 3] =   0;
     pA[ 4] = 0.0; pA[ 5] = 1.0; pA[ 6] = 0.0; pA[ 7] =   0;
     pA[ 8] = 0.0; pA[ 9] = 0.0; pA[10] = 1.0; pA[11] =   0;
     pA[12] = 0.0; pA[13] = 0.0; pA[14] = 0.0; pA[15] = 1.0;
}

void buildRotateZ( float theta, float *pA )
{
// Constructs rotation matrix about Z axis

     float phi;

     // Convert degrees to radians

     phi = theta * M_PI / 180.0;

     pA[ 0] =  cos(phi); pA[ 1] = sin(phi); pA[ 2] = 0.0; pA[ 3] = 0.0;
     pA[ 4] = -sin(phi); pA[ 5] = cos(phi); pA[ 6] = 0.0; pA[ 7] = 0.0;
     pA[ 8] = 0.0;       pA[ 9] = 0.0;      pA[10] = 1.0; pA[11] = 0.0;
     pA[12] = 0.0;       pA[13] = 0.0;      pA[14] = 0.0; pA[15] = 1.0;
}      




void applyTransformation( float *vp, int vpts, float *TM ) 
// Applies the given transformation matrix TM to the vector vp containing
// all of the homegenous coordinates to define the object
{
	float temp[4];
	float *tmp;
        int i;

	tmp = &temp[0];

	for (i=0;i<vpts;i++)
	{
		*(tmp+0)= *(vp+(i*4)+0);
		*(tmp+1)= *(vp+(i*4)+1);
		*(tmp+2)= *(vp+(i*4)+2);
		*(tmp+3)= *(vp+(i*4)+3);
		vmatm( 4, TM, tmp );
		*(vp+(i*4)+0) = *(tmp+0); 
		*(vp+(i*4)+1) = *(tmp+1); 
		*(vp+(i*4)+2) = *(tmp+2); 
		*(vp+(i*4)+3) = *(tmp+3); 
        }
}

	
void PipeLine( float *vp, int vpts )
{
    /*  This routine will run the graphics transformation pipeline. 
     *  It is operating on x,y,z homogenous coordinates defined in a linear
     *  array.  These are converted to vertex points later for possible
     *  clipping before final display.
     */ 

    /* Set up useful temporary variables */
    float TransformationMatrix[16];
    float *TM;
 

    
    /* Don't forget to initialize the ponter! */
    TM = &TransformationMatrix[0];
    // Clip tree  	
	//SHPC(vp, vp, vpts, vpts, );


    // Translate to origin  
    buildTranslate(tX, tY, 0.0,  TM );
    applyTransformation( vp, vpts, TM );   	
    // Perform the rotation operation
    buildRotateZ( SPIN, TM );	
    applyTransformation( vp, vpts, TM );
    // Perform scaling
    buildScale(TM , SCALE);
    applyTransformation( vp, vpts, TM );
    // Perform reflection on y	
    buildReflect(rp,TM);
    applyTransformation( vp, vpts, TM );
	// Translate to origin  
    buildTranslate(WINDOW_MAX/2, WINDOW_MAX/2, 0.0,  TM );
    applyTransformation( vp, vpts, TM );

}
///////////////

///////////////
void defineTree( float *apts )
{


  apts[ 0] = 535.0;  apts[ 1] = 605.0; apts[ 2] = 0.0; apts[ 3] = 1.0;
  apts[ 4] = 650.0;  apts[ 5] = 525.0; apts[ 6] = 0.0; apts[ 7] = 1.0;
  apts[ 8] = 300.0;  apts[ 9] = 550.0; apts[10] = 0.0; apts[11] = 1.0;
  apts[12] = 300.0;  apts[13] = 450.0; apts[14] = 0.0; apts[15] = 1.0;
  apts[16] = 650.0;  apts[17] = 475.0; apts[18] = 0.0; apts[19] = 1.0;
  apts[20] = 535.0;  apts[21] = 395.0; apts[22] = 0.0; apts[23] = 1.0;
   
int pntX1 = 640; 
int pntY1 = 500;
int r = 148;
int j = 24;

	
	int x = 0;
	int y = r;
	float decision = 5/4 - r;
	//plot(x, y, apts);
	//apts[j] = x+pntX1;  apts[j+1] = y+pntY1; apts[j+2] = 0.0; apts[j+3] = 1.0;j+=4;
	
	while (y > x)
	{
		if (decision < 0)
		{
			x++; 
			decision += 2*x+1;
		}
		else
		{
			y--;
			x++;
			decision += 2*(x-y)+1;
		}
		
		
		
		apts[j] = (-x)+pntX1;  apts[j+1] = (-y)+pntY1; apts[j+2] = 0.0; apts[j+3] = 1.0;j+=4;
		apts[j] = x+pntX1;  apts[j+1] = (-y)+pntY1; apts[j+2] = 0.0; apts[j+3] = 1.0;j+=4;
		apts[j] = y+pntX1;  apts[j+1] = (-x)+pntY1; apts[j+2] = 0.0; apts[j+3] = 1.0;j+=4;		
		apts[j] = y+pntX1;  apts[j+1] = x+pntY1; apts[j+2] = 0.0; apts[j+3] = 1.0;j+=4;
		apts[j] = x+pntX1;  apts[j+1] = y+pntY1; apts[j+2] = 0.0; apts[j+3] = 1.0;j+=4;
		apts[j] = (-x)+pntX1;  apts[j+1] = y+pntY1; apts[j+2] = 0.0; apts[j+3] = 1.0;j+=4;
		
		
	}

  



}
///////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
void toVertex ( float *apts, struct vertex *vp, int pts )
{
	coords.clear();	
	int i;
	
        vertex temp;
	for (i=0;i<7;i++)
	{
	   (vp+i)->x = *(apts+(i*4)+0);
		temp.x = *(apts+(i*4)+0);
	   (vp+i)->y = *(apts+(i*4)+1);
		temp.y = *(apts+(i*4)+1);
	   (vp+i)->z = *(apts+(i*4)+2);
		temp.z = *(apts+(i*4)+2);
	   (vp+i)->w = *(apts+(i+4)+3);
		temp.w = *(apts+(i*4)+3);
	   coords.push_back(temp);
		
	   
	}

	int k = 6;
	
       for(int j=0; j<6; j++){
	for (i=j+6;i<pts-6;i+=6)
	{
	  if(i%2 == 0){
	   (vp+i)->x = *(apts+(i*4)+0);
		temp.x = *(apts+(i*4)+0);
	   (vp+i)->y = *(apts+(i*4)+1);
		temp.y = *(apts+(i*4)+1);
	   (vp+i)->z = *(apts+(i*4)+2);
		temp.z = *(apts+(i*4)+2);
	   (vp+i)->w = *(apts+(i+4)+3);
		temp.w = *(apts+(i*4)+3);
	   //coords.push_back(temp);
	   coords.insert(coords.begin()+k,1,temp);
		}
	  if(i%2 != 0){
	   (vp+i)->x = *(apts+(i*4)+0);
		temp.x = *(apts+(i*4)+0);
	   (vp+i)->y = *(apts+(i*4)+1);
		temp.y = *(apts+(i*4)+1);
	   (vp+i)->z = *(apts+(i*4)+2);
		temp.z = *(apts+(i*4)+2);
	   (vp+i)->w = *(apts+(i+4)+3);
		temp.w = *(apts+(i*4)+3);
	   coords.push_back(temp);
	  // coords.insert(coords.end(),1,temp);
		}
		
	 
	}
	k=coords.size();
       }

	
	for (i=0;i<3;i++)
	{
	  
	  temp = coords.at(0);
		  
	  coords.erase(coords.begin());
		
	  coords.push_back(temp);
	
	}



}

void drawTree(int points)
{
line temp;
glBegin(GL_LINES);
    for (int i=0;i<points-6;i++){
        glVertex2f( coords.at(i).x, coords.at(i).y );
	glVertex2f( coords.at(i+1).x, coords.at(i+1).y);
	temp.a = coords.at(i);
	temp.b = coords.at(i+1);
	lineList.push_back(temp);
	}
 	glVertex2f( coords.back().x, coords.back().y );
	glVertex2f( coords.front().x, coords.front().y);
	temp.a = coords.back();
	temp.b = coords.front();
	lineList.push_back(temp);

    glEnd();

}

void myinit( void )
{
/* attributes */

      glClearColor(0.0, 0.0, 0.0, 1.0); /* black background */
      glPointSize(1.0);

/* set up viewing */

      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluOrtho2D(0.0, (float) WINDOW_MAX, 
                 0.0, (float) WINDOW_MAX);
      glMatrixMode(GL_MODELVIEW);
}



void display( void )
{

    int inPoints;             // The number of points in the arrow 
    float point[MAX];         // Array to hold homogenous coordinates for arrow
    float *apts;              // Pointer for point array

    struct vertex inVertexArray[MAX/4];	/* array of vertices to hold points */
    struct vertex *invp;                /* Pointer for inVertexArray  */  

    /* Make sure to initialize the pointers! */ 
    apts = &point[0];         // the pointer to the array of points 
    invp = &inVertexArray[0]; // the pointer to the array of vertices

    inPoints = 630;             // the actual number of points in the arrow
    
    glClear(GL_COLOR_BUFFER_BIT);  /*clear the window */

    /* Define Viewport */
    glColor3f(1.0, 1.0, 1.0);
    glRecti(VIEWPORT_MIN,VIEWPORT_MIN,VIEWPORT_MAX,VIEWPORT_MAX);

    /* Define the arrow points */
    defineTree( apts );

    /* Now start the process of rotating */
    PipeLine( apts, inPoints );
    toVertex( apts, invp, inPoints );

    glColor3f(1.0, 0.0, 0.0);

    /* Draw Scaled and Rotated Arrow */
    //drawTrunk( invp, 6 );
    //drawLeaves(invp, inPoints);
    drawTree(inPoints);
    glutSwapBuffers();

 }


void SpinDisplay(void)
{
    SPIN = SPIN + DELTA_SPIN;
    if (SPIN > 360.0) SPIN = SPIN - 360.0;
    glutPostRedisplay();
}

void reDisplay()
{
 glutPostRedisplay();
 glutIdleFunc(SpinDisplay);
}


void mouse(int button, int state, int x, int y) 
{
    switch (button) {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN && (x<VIEWPORT_MAX && y<VIEWPORT_MAX ) && (x>VIEWPORT_MIN && y>VIEWPORT_MIN ))
            {
	        DELTA_SPIN = DELTA_SPIN - 1.0;
                glutIdleFunc(SpinDisplay);
            }
	    
	    if(state == GLUT_DOWN && (x>VIEWPORT_MAX || y>VIEWPORT_MAX ) || (x<VIEWPORT_MIN || y<VIEWPORT_MIN ))
	    {
		SCALE = SCALE*1.05;
		glutIdleFunc(reDisplay);
		
	    }
            break;
        case GLUT_RIGHT_BUTTON:
            if (state == GLUT_DOWN && (x<VIEWPORT_MAX && y<VIEWPORT_MAX ) && (x>VIEWPORT_MIN && y>VIEWPORT_MIN ))
            {
                DELTA_SPIN = DELTA_SPIN + 1.0;
                glutIdleFunc(SpinDisplay);
            }
	    if(state == GLUT_DOWN && (x>VIEWPORT_MAX || y>VIEWPORT_MAX ) || (x<VIEWPORT_MIN || y<VIEWPORT_MIN ))
	    {
		SCALE = SCALE*0.95;
		glutIdleFunc(reDisplay);
		
	    }
            break;
        default:
            break;
    }
}


void keyboard( unsigned char key, int x, int y )
{ 
    if ( key == 'q' || key == 'Q') exit(0);
    if ( key == 'f' || key == 'F') exit(0);
    if ( key == 't' || key == 'T') tessalate();
    if ( key == 'l' || key == 'L') exit(0);


    if ( key == 'i' || key == 'I') {
        SPIN = 0.0;
	DELTA_SPIN = 0.0;
	SCALE = 1.0;
	rp = 1.0;
	tX = -WINDOW_MAX/2;
	tY = -WINDOW_MAX/2;
        glutIdleFunc(display);
    }
    if ( key == 's' || key == 'S') {
	glutIdleFunc(NULL);
    }
    if ( key == 'r' || key == 'R'){
	rp = rp*-1.0;
	DELTA_SPIN = DELTA_SPIN*-1.0;
	glutIdleFunc(reDisplay);
    }

}

void arrowKeys(int key, int x, int y)
{
 switch(key)
  {
	case GLUT_KEY_UP:
	 tY+= 5.0;
	 glutIdleFunc(reDisplay);
	break;
	case GLUT_KEY_DOWN:
	 tY+= -5.0;
	 glutIdleFunc(reDisplay); 
	break;
	case GLUT_KEY_LEFT:
	 tX+= -5.0;
	 glutIdleFunc(reDisplay);
	break;
	case GLUT_KEY_RIGHT:
	 tX+= 5.0;
	 glutIdleFunc(reDisplay);
	break;

  }
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB); 
    glutInitWindowSize(WINDOW_MAX,WINDOW_MAX); 
    glutInitWindowPosition(0,0); 
    glutCreateWindow("The Tree"); 
    myinit(); 
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(arrowKeys);
    glutDisplayFunc(display); 
    glutMainLoop();
}

