/*
 * Cue.hpp
 *
 *  Created on: Nov 28, 2017
 *      Author: garre
 */
#include "Ball.hpp"
#include <GL/glew.h>
#include <GL/glut.h>
#ifndef SRC_PLAYER_HPP_
#define SRC_PLAYER_HPP_

class Player{
public:
	Ball* sunk[7]; //balls sunk by this player
	GLint shots; //counter of shots taken
	Player();
	void draw();
	void setName(char*); //idk how strings work in c++ and am too lazy to google right now

};

#endif /* SRC_CUE_HPP_ */
