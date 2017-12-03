/*
 * Table.cpp
 *
 *  Created on: Nov 28, 2017
 *      Author: garre
 */

#include "Table.hpp"

Table::Table() {
	// TODO Auto-generated constructor stub
}

void Table::draw(){
	int appW = glutGet(GLUT_WINDOW_WIDTH);
			int appH = glutGet(GLUT_WINDOW_HEIGHT);
			int center1 = appW/2;
			int center2 = appH/2;
			glColor3f(1.0,0.0,0.0);
			glRectf(center1-50,center2-75,100,150);
glutPostRedisplay();
}
void Table::setTexture(GLint i){

}
