/*
 * Cue.hpp
 *
 *  Created on: Dec 4, 2017
 *      Author: garre
 */
#ifndef CUE_H
#define CUE_H
#include "ball.hpp"

class Cue{
public:
	GLfloat x,y;
	Cue();
	void draw(Ball w,GLfloat,GLfloat);
};



#endif /* 3D_POOL_SRC_CUE_HPP_ */
