#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "game.hpp"
#include <time.h>
#include <GL/glut.h>

#define NUM_OF_BALLS 16
#define NUM_OF_POCKETS 6

GLfloat winWidth = window_width - 2 * border;
GLfloat winHeight = window_height - 2 * border;
GLint length=winWidth,width=winWidth/2;
GLfloat xBorder2=winWidth+border, yBorder2=winHeight+border;
Table *table;
Ball *balls[NUM_OF_BALLS];
Ball *pockets[NUM_OF_POCKETS];
bool ballVisible[NUM_OF_BALLS];

void setupTable(float length)
{
	table = new Table(length);

}
bool onTable(GLint x, GLint y){
	if(x>xBorder1 && y>yBorder1 && x <xBorder2 && y <yBorder2){
		return true;
	}else{
		return false;
	}
}
void setupBalls(GLint radius, int numOfBalls)
{
	for (int i = 0; i < numOfBalls; i++)
	{
		balls[i] = new Ball(radius, i);
		ballVisible[i] = true;
	}
	int x = window_width/3-2*border;
	int y = 245;
	balls[0]->position.set(x, y, 0);

	x = x * 3-80;
	int counter = 0;
	for (int i = 1; i < numOfBalls; i++)
	{
		if (i == 2 || i == 4 || i == 7 || i == 11){
			x = x +radius*2;
			y=y-radius;
			counter = 0;
		}

		balls[i]->position.set(x, y + 2 * counter * radius+2*radius, 0);
		counter++;
	}
}
void setupPockets(float radius, int numOfPockets)
{
	for (int i = 0; i < numOfPockets; i++)
	{
		pockets[i] = new Ball(radius, i);
	}

	int x = 0.0f;
	int y = 0.0f;

	for (int i = 0; i < numOfPockets; i++)
	{
		if (i == 3)
		{
			x = 0;
			y = width;
		}

		pockets[i]->position.set(x, y, 0);
		x = x + width;
	}


}
void drawTable(){
	glPushMatrix();
	glColor3f(0.545, 0.271, 0.075);
	glRectf(0,0,winWidth*1.5, winHeight*1.5);
	glPopMatrix();
	glPushMatrix();

		glTranslatef(border, border, 0);
		glColor3f(0, 0.5, 0);
		glRectf(0, 0, winWidth, winHeight);


	glPopMatrix();
}

void drawCircle(int radius){
   glBegin(GL_POLYGON);

   for (int i=0; i<360; i++)
   {
      float newDeg = i*radius; //FIX
      glVertex2f(cos(newDeg)*radius, sin(newDeg)*radius);
   }

   glEnd();
}
void drawBalls()
{
	for (int i = 0; i < NUM_OF_BALLS; i++)
	{
		if (!ballVisible[i])
		{
			continue;
		}
		glPushMatrix();
		{
			glTranslatef(balls[i]->position.x,balls[i]->position.y, 0.0f);

			if (i == 0)
				glColor3f(1,1,1);
			else if(i == 1 || i == 9){
				glColor3f(1,1,0);
			}
			else if(i == 2 || i == 10){
				glColor3f(0,0,1);
			}
			else if(i == 3 || i == 11){
				glColor3f(1.0,0.5,0.5);
			}else if(i == 4 || i == 12){
				glColor3f(0,1,1);
			}else if(i == 5 || i == 13){
				glColor3f(1,0.5,1);
			}else if(i == 6 || i == 14){
				glColor3f(0.5,1,0.5);
			}else if(i == 7 || i == 15){
				glColor3f(1,0,0);
			}else if(i == 8){
				glColor3f(0,0,0);
			}

			drawCircle(radius);
		}
		glPopMatrix();
	}
}

void drawPockets()
{
	for (int i = 0; i < NUM_OF_POCKETS; i++)
	{
		glPushMatrix();
		{
			glTranslatef(border + pockets[i]->position.x ,
						border + pockets[i]->position.y , 0.0f);

			glColor3f(0,0,0);

			drawCircle(pocket_radius);
		}
		glPopMatrix();
	}
}
void resetGame()
{
	setupGame();
}

void init()
{
	glClearColor(1.0,1.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, window_width, window_height, 0.0);
	glFlush();
	setupGame();

}

void setupGame()
{

	setupBalls(radius, NUM_OF_BALLS);
	setupPockets(pocket_radius, NUM_OF_POCKETS);

}
void initLights()
{
	GLfloat ambient[] = {0.2, 0.2, 0.2, 1.0};
	GLfloat position[] = {0.0, 0.0, 2.0, 1.0};
	GLfloat mat_diffuse[] = {0.6, 0.6, 0.6, 1.0};
	GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat mat_shininess[] = {50.0};

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_POSITION, position);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}
void mouseAction(GLint button, GLint state, GLint xMouse, GLint yMouse) {

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		moving = 1;
	//	xBegin = xMouse;
	//	yBegin = yMouse;

	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		moving = 0;
	}


	glutPostRedisplay();
}
void setPixel(GLint x, GLint y){
	glPointSize(2.0);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	//glutPostRedisplay();
}
void drawLine(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2) {
	static const double TWOPI = 6.2831853071795865;
	    double theta = atan2(y2-y1, x2 - x1);
	    if (theta < 0.0)
	        theta += TWOPI;
	GLfloat angle=theta;
	GLfloat x0,y0,d=30;
	GLfloat s = sin(angle);
		GLfloat c = cos(angle);
	x0=x2-c*d;
	y0=y2-s*d;
	glLineWidth(3.0f);
		glBegin(GL_LINES);
		glVertex2f(x1,y1);
		glVertex2f(x0,y0);
		glEnd();
		glutPostRedisplay();
}
void mouseMotion(GLint x, GLint y) {
	if (moving) {

		//comment
		if(onTable(x,y)==true){
			xBegin=x;
			yBegin=y;
		//	glPushMatrix();
		//	glColor3f(1.0,0.0,0.0);

		//	drawLine(balls[0]->position.x,balls[0]->position.y,x,y);

		}
	}

	glutPostRedisplay();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	drawTable();
		drawBalls();
		drawPockets();
	if(moving){
		printf("x:%f,y:%f",xBegin,yBegin);
		drawLine(xBegin,yBegin,balls[0]->position.x,balls[0]->position.y);


	}

	glFlush();
	glutSwapBuffers();
}

void reshape(GLint newWidth, GLint newHeight)
{
	glViewport(0, 0, newWidth, newHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, GLdouble(newWidth), GLdouble(newHeight), 0.0);
	/* Reset display-window size parameters. */
	window_width = newWidth;
	window_height = newHeight;
	glFlush();
}
int main( int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(window_width, window_height);

	glutCreateWindow("Billiard");
	init();

	glutDisplayFunc(display);
	glutMotionFunc(mouseMotion);
	glutMouseFunc(mouseAction);
	//glutReshapeFunc(reshape);
	glutMainLoop();
}




