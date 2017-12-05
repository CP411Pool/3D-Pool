#ifndef Ball_H
#define Ball_H
#include <GL/glut.h>

#include "vector.hpp"
class Ball
{
	public:
		Ball();;
		Vector position;
		Vector velocity;
};

#endif
