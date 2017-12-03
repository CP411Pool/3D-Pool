/*
 * Table.cpp
 *
 *  Created on: Nov 28, 2017
 *      Author: garre
 */

#include "Table.hpp"

Table::Table() {
	// TODO Auto-generated constructor stub
	vertex[0][0] = -1;vertex[0][1] = -1;vertex[0][2] = -1;
	    vertex[1][0] = -1;vertex[1][1] = 1; vertex[1][2] = -1;
	    vertex[2][0] = 1;vertex[2][1] = -1; vertex[2][2] = -1;
	    vertex[3][0] = 1;vertex[3][1] = 1;vertex[3][2] = -1;
	    vertex[4][0] = -1;vertex[4][1] = -1;vertex[4][2] = 1;
	    vertex[5][0] = -1;vertex[5][1] = 1; vertex[5][2] = 1;
	    vertex[6][0] = 1;vertex[6][1] = -1;vertex[6][2] = 1;
	    vertex[7][0] = 1;vertex[7][1] = 1;vertex[7][2] = 1;

	    face[0][0] = 0;face[0][1] = 1;face[0][2] = 3; face[0][3] = 2;
	    face[1][0] = 3;face[1][1] = 7;face[1][2] = 6;face[1][3] = 2;
	    face[2][0] = 7;face[2][1] = 5;face[2][2] = 4;face[2][3] = 6;
	    face[3][0] = 4;face[3][1] = 5;face[3][2] = 1;face[3][3] = 0;
	    face[4][0] = 5;face[4][1] = 7;face[4][2] = 3;face[4][3] = 1;
	    face[5][0] = 6;face[5][1] = 4;face[5][2] = 0;face[5][3] = 2;
}

void Table::draw(){
	glPushMatrix();
	int appW = glutGet(GLUT_WINDOW_WIDTH);
			int appH = glutGet(GLUT_WINDOW_HEIGHT);
			int center1 = appW/2;
			int center2 = appH/2;
			glColor3f(1.0,0.0,0.0);
			glRectf(center1-50,center2-75,100,150);
	glPopMatrix();

}
void Table::setTexture(GLint i){

}
