#ifndef Ball_H
#define Ball_H
#include <GL/glut.h>

#include "vector.hpp"
class Ball
{
	public:
		GLint xBorder=40,yBorder=40,xBorder1=940,yBorder1=490;
		Ball();;
		Vector position;
		Vector velocity;
		bool isBallHit(Ball *b);
		void resolve(Ball *b);
		GLfloat radius;
		bool isInHole;
		bool hitLeft();
		bool hitRight();
		bool hitTop();
		bool hitBot();
};

#endif
