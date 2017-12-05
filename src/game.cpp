#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "game.hpp"
#include <time.h>
#include <GL/glut.h>

/*                   HOTKEYS
	*******************************************
	*  Press the 'r' key to reset the game    *
	*  Press the 'esc' key to close the game  *
	*******************************************
 */

GLfloat winWidth = window_width - 2 * border;
GLfloat winHeight = window_height - 2 * border;
GLint length=winWidth,width=winWidth/2;
GLfloat xBorder2=winWidth+border, yBorder2=winHeight+border;
Table *table;

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
		balls[i] = new Ball();
		ballVisible[i] = true;
	}
	int x = window_width/3-2*border;
	int y = 245;
	balls[0]->position.set(x, y+25, 0);

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
		pockets[i] = new Ball();
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
				glColor3f(0.8,0.5,0.2);
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
void update(){
	float d;
	float dt;
	for (int i=0; i<NUM_OF_BALLS; ++i){



		float dt=balls[i]->dt;
		if ( balls[i]->velocity.length()< 0.02){
			balls[i]->velocity.x = 0.0;
		balls[i]->velocity.y = 0.0;
		balls[i]->velocity.z = 0.0;
		}
		else {
			balls[i]->velocity.normalize();
			Vector acc;
			acc.x = balls[i]->velocity.x*-0.1f;
			acc.y = balls[i]->velocity.y*-0.1f;
			acc.z = balls[i]->velocity.z*-0.1f;
			balls[i]->velocity.x = balls[i]->velocity.x + acc.x*dt;
			balls[i]->velocity.y = balls[i]->velocity.y + acc.y*dt;
			balls[i]->velocity.z = balls[i]->velocity.z + acc.z*dt;

		}
		//float stepLength = balls[i]->velocity.length()*dt;
		//float rotateAngle = stepLength*180/(M_PI*balls[i]->radius);
		if ( balls[i]->isInHole==false && dt>0.02){
			balls[i]->position.x = balls[i]->position.x +  balls[i]->velocity.x*dt;
			balls[i]->position.y = balls[i]->position.y +  balls[i]->velocity.y*dt;
			balls[i]->position.z = balls[i]->position.z +  balls[i]->velocity.z*dt;
		}
		balls[i]->dt=dt+0.03;


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
void resolveTable(Ball *ball){
	if ( ball->hitLeft() ){
			ball->velocity.x = -ball->velocity.x;
			ball->position.x = xBorder1 + ball->radius;
		} else
		if ( ball->hitRight()){
			ball->velocity.x = -ball->velocity.x;
			ball->position.x = xBorder2 - ball->radius;
		}

		if ( ball->hitTop()){
			ball->velocity.y = -ball->velocity.y;
			ball->position.y = yBorder2 - ball->radius;
		} else
		if (ball->hitBot()){
			ball->velocity.y = -ball->velocity.y;
			ball->position.y = yBorder1 + ball->radius;
		}
}
void checkCollisions(){
	for (int i=0; i< NUM_OF_BALLS; ++i){
		for (int j=i+1; j< NUM_OF_BALLS; ++j){
			if ( !balls[i]->isInHole  && !balls[j]->isInHole && balls[i]->isBallHit(balls[j]) ){
				balls[i]->resolve(balls[j]);

				balls[i]->dt=balls[i]->velocity.length();
				balls[j]->dt=balls[j]->velocity.length();

			}
		}
		if ( !balls[i]->isInHole ) resolveTable(balls[i]);
	}
}

void strikeBall(){
	Vector cueVel;
	cueVel.x= balls[0]->position.x-cue.x;
	cueVel.y=balls[0]->position.y-cue.y;
			//Vector(position.x, table.heigh + balls[0]->radius, position.z);
	cueVel.normalize();
	cueVel.x = cueVel.x* (float)(force/100);
	cueVel.y = cueVel.y* (float)(force/100);
	cueVel.z = cueVel.z* (float)(force/100);
	balls[0]->velocity = cueVel;
	balls[0]->dt=balls[0]->velocity.length();
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
	printf("                 HOTKEYS                   \n");;
		printf("*******************************************\n");
		printf("*  Press the 'r' key to reset the game    *\n");
		printf("*  Press the 'esc' key to close the game  *\n");
		printf("*******************************************\n");
}
void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
		case 27: // Escape key
			exit(0);
			break;
		case 114: // r key
			resetGame();
			break;
	}
}

void setupGame()
{
	setupBalls(radius, NUM_OF_BALLS);
	setupPockets(pocket_radius, NUM_OF_POCKETS);
}


void mouseAction(GLint button, GLint state, GLint xMouse, GLint yMouse) {

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		moving = 1;
		strikeBall();
		isMoving=true;
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		moving = 0;
		isMoving=false;
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

void movement(void){

}
/*
void hitCue(){
	Vector cueVel = new Vector();
}*/

void mouseMotion(GLint x, GLint y) {
				xBegin=x;
				yBegin=y;

	if (isMoving) {
		//BALL HIT HERE

	}

	glutPostRedisplay();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	checkCollisions();
	drawTable();
		drawBalls();
		drawPockets();
		if(xBegin!=0 && !isMoving){
			cue.draw(*balls[0],xBegin,yBegin);
		}else{

		}

update();


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
static void Timer(int value){
	ticks++;
    glutTimerFunc(100, Timer, 0);

}
int main( int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(window_width, window_height);

	glutCreateWindow("Billiard");
	init();

	glutDisplayFunc(display);
	glutPassiveMotionFunc(mouseMotion);
	glutMouseFunc(mouseAction);
	glutKeyboardFunc(keyboard);
	//glutReshapeFunc(reshape);
	Timer(0);


	glutMainLoop();
}




