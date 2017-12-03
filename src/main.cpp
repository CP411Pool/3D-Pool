/*
 * main.cpp
 *
 *  Created on: Dec 3, 2017
 *      Author: Keega
 */
#include "game.hpp"

extern const int window_width;
extern const int window_height;

int main( int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(window_width, window_height);

	glutCreateWindow("Billiard");
	setupRenderingContext();
	setupGame();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
}



