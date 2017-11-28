/*
 * MainControl.hpp
 *
 *  Created on: Nov 28, 2017
 *      Author: garre
 */

#ifndef SRC_MAINCONTROL_HPP_
#define SRC_MAINCONTROL_HPP_
#include "glsl/Angel.h"
#include <GL/glew.h>
#include <GL/glut.h>
#include "glaux.h" // for reading bmp files

#include "World.hpp"
#include "Camera.hpp"
#include "Light.hpp"
#include "Cue.hpp"


#include "pixmap/RGBpixmap.h"

RGBpixmap pix[7];   // make six pixmaps
World myWorld;
GLint moving = 0, xBegin = 0;
Camera myCamera;
Light myLight;
Cue playerOne;
Cue playerTwo;
GLint winWidth = 800, winHeight = 800;
//declare shader program object
GLuint ProgramObject;

// light properties
GLfloat ambient[] = { 0.1f, 0.1f, 0.3f, 1.0f };
GLfloat diffuse[] = { .6f, .6f, 1.0f, 1.0f };
GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat positionSolar[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat position[] = { 1.8, 1.8, 1.5, 1.0 };
GLfloat lmodel_ambient[] = { 0.5, 0.5, 0.5, 1.0 };
GLfloat local_view[] = { 0.0 };

//Material
GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_ambient[] = { 0.7, 0.7, 0.7, 1.0 };
GLfloat mat_ambient_color[] = { 1, 1, 1, 1 };
GLfloat mat_diffuse[] = { 0.1, 0.5, 0.8, 1.0 };
GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat high_shininess[] = { 100.0 };
GLfloat mat_emission[] = { 1, 1, 1, 1 };

//function prototypes
void reset(void);
void close(void);




#endif /* SRC_MAINCONTROL_HPP_ */
