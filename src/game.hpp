/*
 * game.hpp
 *
 *  Created on: Dec 3, 2017
 *      Author: Keega
 */

#ifndef GAME_HPP
#define GAME_HPP
#include <GL/glut.h>

#include "Ball.hpp"
#include "Table.hpp"


const int border = 40;
const int window_width = 980;
const int window_height = (window_width / 2) + border;
const float table_length = 2.7f;

const int fps = 25;

void setupGame();
void initLights(void);
void setupRenderingContext(void);
void display(void);;
void reshape(int width, int height);
void mouse(int button, int state, int x, int y);
void motion(int x, int y);


#endif /* 3D_POOL_SRC_GAME_HPP_ */
