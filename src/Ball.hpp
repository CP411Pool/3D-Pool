#ifndef Ball_H
#define Ball_H

#include <windows.h>
#include <GL/glut.h>
#include "Shape.hpp"

class Ball: public Shape {
public:

	GLfloat radius;
	GLint slices, stacks;
	GLuint textureID;
	GLUquadric *quad;
	Ball();
	void draw();
};

#endif
