/*
 * game.hpp
 *
 *  Created on: Dec 3, 2017
 *      Author: Keega
 */

#ifndef GAME_HPP
#define GAME_HPP
#include <GL/glut.h>
#include <math.h>
#include "Ball.hpp"
#include "Table.hpp"


const int border = 40;
GLint window_width = 980;
GLint window_height = (window_width / 2) + border;
float radius = 12;
float pocket_radius = 20;
bool isMoving = false;
GLint moving = 0,xBorder1=40,yBorder1=40;
GLfloat xBegin,yBegin;
void setupGame();
void initLights(void);
void setupRenderingContext(void);
void display(void);;
void reshape(int width, int height);
void mouseAction(GLint button, GLint state, GLint x, GLint y);
void mouseMotion(GLint x, GLint y);


#endif /* 3D_POOL_SRC_GAME_HPP_ */
