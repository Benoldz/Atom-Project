//Example https://www.youtube.com/watch?v=dBNhHe064oE //
#include <math.h>
#include <GL\glut.h>

const double PI = 3.14159265359; 
int angle = 0;   
int n = 0;
int delay = 60;

void path1(GLfloat r){
float x,y, z;
x = 0;
float radius = r;
glColor3f(.48,.48,.48);
glBegin(GL_LINES);
glLineWidth(2);
z = (float)radius *  cos(359 * PI/180.0f);
y = (float)radius * sin(359 * PI/180.0f);
	for (int j = 0; j < 360; j++){
		glPushMatrix();
		glVertex3f(x, y, z);
		z = (float)radius * cos(j * PI/180.0f);
		y = (float)radius * sin(j * PI/180.0f);
		glVertex3f(x,y,z);
	}
 glEnd();
 }

void path2(GLfloat r){
float x,y, z;
y = 0;
float radius = r;
glColor3f(.48,.48,.48);
glBegin(GL_LINES);
glLineWidth(2);
x = (float)radius * cos(359 * PI/180.0f);
z = (float)radius *  cos(359 * PI/180.0f);
	for (int j = 0; j < 360; j++){
		glPushMatrix();
		glVertex2f(x, y);
		x = (float)radius * cos(j * PI/180.0f);
		z = (float)radius * sin(j * PI/180.0f);
		glVertex3f(x,y,z);
	}
 glEnd();
 }
 
   void init() {
       GLfloat light_direction[] = { 0.0, 2.0, -1.0, 1.0 };
       GLfloat light_intensity[] = { 0.7, 0.7, 0.7, 1.0 };
       GLfloat ambient_intensity[] = { 0.3, 0.3, 0.3, 1.0 };
    
       glClearColor(0, 0, 0, 0.0);   
    
       glEnable(GL_DEPTH_TEST);            
    
       glEnable(GL_LIGHTING);              
       glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient_intensity);
    
       glEnable(GL_LIGHT0);               
       glLightfv(GL_LIGHT0, GL_POSITION, light_direction);
       glLightfv(GL_LIGHT0, GL_DIFFUSE, light_intensity);
    
       glEnable(GL_COLOR_MATERIAL);       
       glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
   }
    
   
   void draw() {
       glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	   glLoadIdentity();
	   //p
	   path2(.70);
	   path1(.55);
       glColor3f(0, 1, 1);
       glShadeModel(GL_SMOOTH);

	   glScalef(.3, .3, .3);
       glutSolidSphere(1.0, 40, 40);
	   
	   glColor3f(0, 0, 1.0);
	   glPushMatrix();
	   glRotatef(angle,1,0,0);
	   glTranslatef(0, 1.8, 1);
	   glScalef(.3, .3, .3);
	   glutSolidSphere(1, 40, 40);
	   glPopMatrix();

	   glPushMatrix();
	   glRotatef(angle,1,0,0);
	   glTranslatef(0, -1.8, 0);
	   glScalef(.3, .3, .3);
	   glutSolidSphere(1, 40, 40);
	   glPopMatrix();

	   glPushMatrix();
	   glRotatef(angle,0,1,0);
	   glTranslatef(-2, 0, 1);
	   glScalef(.3, .3, .3);
	   glutSolidSphere(1, 40, 40);
	   glPopMatrix();

	   glPushMatrix();
	   glRotatef(angle,0,1,0);
	   glTranslatef(-2.2, 0, 0);
	   glScalef(.3, .3, .3);
	   glutSolidSphere(1, 40, 40);
	   glPopMatrix();

	   glPushMatrix();
	   glRotatef(angle,0,1,0);
	   glTranslatef(2.2, 0, 0);
	   glScalef(.3, .3, .3);
	   glutSolidSphere(1, 40, 40);
	   glPopMatrix();

	   glPushMatrix();
	   glRotatef(angle,0,1,0);
	   glTranslatef(2, 0, 1);
	   glScalef(.3, .3, .3);
	   glutSolidSphere(1, 40, 40);
	   glPopMatrix();

		glutSwapBuffers();
   }
   
   
   void idle(int n) {
	angle+=5;
	glutPostRedisplay();
	glutTimerFunc(delay,idle,n);
   }
    
   int main(int argc, char **argv) {
       glutInit(&argc, argv);
       glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
       glutInitWindowPosition(50, 100);   
       glutInitWindowSize(1280,720);
       glutCreateWindow("Carbon");
    
       init();
       glutDisplayFunc(draw);
	   glutTimerFunc(delay,idle,n);
	   glutMainLoop();
	   return 0;
   }
