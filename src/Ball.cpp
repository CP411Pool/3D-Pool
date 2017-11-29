#include "Ball.hpp"

Ball::Ball() {
	radius = 1.0, slices = 50, stacks = 50;
	textureID = 0;
	this->quad = gluNewQuadric();

	gluQuadricTexture(this->quad, GL_TRUE);
	gluQuadricOrientation(this->quad, GLU_OUTSIDE);
	gluQuadricNormals(this->quad, GLU_SMOOTH);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}


void Ball::draw() {

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureID);

	glPushMatrix();
	this->ctm_multiply();
	gluSphere(this->quad, radius, slices, stacks);
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
}

