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


Table *table;



void setupTable(float length)
{
	table = new Table(length);
}
void drawTable()
{
	glPushMatrix();
	{
		glTranslatef(border, border, 0);
		glColor3f(0, 1, 1);
		glRectf(0, 0, converted_table_length, converted_table_width);
	}
	glPopMatrix();
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

	glPushMatrix();
		drawTable();

	glPopMatrix();

	glFlush();
	glutSwapBuffers();
}

void reshape(int width, int height)
{

}


