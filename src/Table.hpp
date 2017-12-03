/*
 * Table.hpp
 *
 *  Created on: Nov 28, 2017
 *      Author: garre
 */
#include "Shape.hpp"
#ifndef TABLE_HPP_
#define TABLE_HPP_

class Table{
public:
	Table();
	GLfloat vertex[8][3];
	GLint face[6][4];
	void setTexture(GLint);
	void draw();
};

#endif /* TABLE_HPP_ */
