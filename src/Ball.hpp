#ifndef Ball_H
#define Ball_H
#include <GL/glut.h>
#include "glm/glm.hpp"
#include "glm/gtx/vector_angle.hpp"
class Ball
{
	public:
		Ball();;
		glm::vec2 position;
		glm::vec2 velocity;
		GLfloat radius;
		GLfloat mass;
		bool isInHole;
		void isBallHit(Ball);
		void resToBallHit(Ball);

};

#endif
