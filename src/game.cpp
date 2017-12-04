#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "game.hpp"
#include <time.h>

#define NUM_OF_BALLS 16
#define NUM_OF_POCKETS 6

const float converted_table_length = window_width - 2 * border;
const float converted_table_width = window_height - 2 * border;
const float meter_to_coord = converted_table_length/table_length;
const float converted_ball_radius = ball_radius * meter_to_coord;
const float converted_pocket_radius = pocket_radius * meter_to_coord;
const float degree_to_radian = 3.14159265f/180.f;
Table *table;
Ball *balls[NUM_OF_BALLS];
Ball *pockets[NUM_OF_POCKETS];
bool ballVisible[NUM_OF_BALLS];
GLfloat white[] = {1, 1, 1, 1};
GLfloat red[] = {1, 0, 0, 1};




void setupTable(float length)
{
	table = new Table(length);
}
void setupBalls(float radius, int numOfBalls)
{
	for (int i = 0; i < numOfBalls; i++)
	{
		balls[i] = new Ball(radius, i);
		ballVisible[i] = true;
	}

	radius += 0.0005f;

	const float root_three = sqrt(3);
	float x = table->length/4;
	float y = table->length/4;
	balls[0]->position.set(x, y, 0.0f);

	x = x * 3;
	int counter = 0;
	for (int i = 1; i < numOfBalls; i++)
	{
		if (i == 2 || i == 4 || i == 7 || i == 11)
		{
			x = x + root_three * radius;
			y = y - radius;
			counter = 0;
		}

		balls[i]->position.set(x, y + 2 * counter * radius, 0.0f);
		counter++;
	}
}
void setupPockets(float radius, int numOfPockets)
{
	for (int i = 0; i < numOfPockets; i++)
	{
		pockets[i] = new Ball(radius, i);
	}

	float x = 0.0f;
	float y = 0.0f;

	for (int i = 0; i < numOfPockets; i++)
	{
		if (i == 3)
		{
			x = 0.0f;
			y = table->width;
		}

		pockets[i]->position.set(x, y, 0.0f);
		x = x + table->width;
	}


}
void drawTable(){
	glPushMatrix();
	glColor3f(0.545, 0.271, 0.075);
	glRectf(0,0,converted_table_length*1.5, converted_table_width*1.5);
			glPopMatrix();
	glPushMatrix();
	{
		glTranslatef(border, border, 0);
		glColor3f(0, 1, 0);
		glRectf(0, 0, converted_table_length, converted_table_width);

	}
	glPopMatrix();
}

void drawCircle(float radius){
   glBegin(GL_LINE_LOOP);

   for (int i=0; i<360; i++)
   {
      float newDeg = i*degree_to_radian;
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
			glTranslatef(border + balls[i]->position.x * meter_to_coord,
						border + balls[i]->position.y * meter_to_coord, 0.0f);

			if (i == 0)
				glColor4fv(white);
			else
				glColor4fv(red);

			drawCircle(converted_ball_radius);
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
			glTranslatef(border + pockets[i]->position.x * meter_to_coord,
						border + pockets[i]->position.y * meter_to_coord, 0.0f);

			glColor4fv(white);

			drawCircle(converted_pocket_radius);
		}
		glPopMatrix();
	}
}
void resetGame()
{
	setupGame();
}

void setupRenderingContext()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(0.0f, window_width, window_height, 0.0f, 0.0f, 1.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glDisable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
	glClearColor(0.0, 0.0, 0.0, 0.0);

}

void setupGame()
{
	setupTable(table_length);
	setupBalls(ball_radius, NUM_OF_BALLS);
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


void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();{
		drawTable();
		drawPockets();
		drawBalls();
	}
	glPopMatrix();

	glFlush();
	glutSwapBuffers();
}

void reshape(int width, int height)
{

}


