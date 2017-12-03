#ifndef TABLE_HPP
#define TABLE_HPP

#include <GL/glut.h>

class Table
{
	public:
		Table(float length);
		Table(float length, float width);
		float length;
		float width;
};

#endif
