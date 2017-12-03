#ifndef Ball_H
#define Ball_H
#include "vector.hpp"
class Ball
{
	public:
		Ball();
		Ball(float radius, int id = -1);
		int id;
		float radius;
		float friction;
		float bounciness;
		Vector position;
		Vector velocity;
		void setFriction(const float value);
		void setBounciness(const float value);
};

#endif
