#ifndef Ball_H
#define Ball_H

#include <windows.h>
#include <GL/glew.h>
#include <GL/glut.h>

class Ball {
public:

	GLfloat radius;
	GLint slices, stacks;
	GLuint textureID;
	GLUquadric *quad;
	Ball();
	void draw();
	void setTexture(GLuint);
};

#endif
