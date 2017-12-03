/*
 * game.cpp
 *
 *  Created on: Nov 28, 2017
 *      Author: garre
 */
#include "MainControl.hpp"
void init(void){
	//myLight.translate(1.5, 1.5, 1.5);
	glClearColor(0.0, 0.0, 0.0, 1.0);

	// Smooth out lines
	glEnable(GL_LINE_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_CULL_FACE);
				glEnable(GL_DEPTH_TEST);
				glEnable(GL_NORMALIZE);
				glEnable(GL_LIGHTING);
				glEnable(GL_LIGHT0);

	//load and set vertex and fragement shader
    //....
	ProgramObject = InitShader( "vertexshader.txt", "fragmentshader.txt" );
	glUseProgram(0);

	//set textures for the balls, table n shit
	/**
	pix[0].makeCheckerboard();
	pix[0].setTexture(0);
	pix[1].readBMPFile("mandrill.bmp");
	pix[1].setTexture(1);
	pix[2].readBMPFile("sun.bmp");
	pix[2].setTexture(2);
	pix[3].readBMPFile("earth.bmp");
	pix[3].setTexture(3);
	pix[4].readBMPFile("moon.bmp");
	pix[4].setTexture(4);
	pix[5].readBMPFile("draw.bmp");
		pix[5].setTexture(5);
		pix[6].readBMPFile("stars.bmp");
		pix[6].setTexture(6);
**/


}
void reset(void){
		glUseProgram(0);

		glDisable(GL_CULL_FACE);
		glDisable(GL_DEPTH_TEST);
		glDisable(GL_NORMALIZE);
		glDisable(GL_COLOR_MATERIAL);
		glDisable( GL_LIGHTING );
		glDisable(GL_LIGHT0);
		myWorld.reset();
		glFlush();
		glutPostRedisplay();
}
void close(void){
	exit(1);
}
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	myCamera.setProjectionMatrix();  // change to 3D view
//	myWorld.draw_world();//draw table, balls,
	myTable.draw();
	glFlush();
	glutSwapBuffers();

}
void winReshapeFcn(GLint newWidth, GLint newHeight) {
	glViewport(0, 0, newWidth, newHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	winWidth = newWidth;
	winHeight = newHeight;
}
void mouseAction(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		moving = 1;
		xBegin = x;
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		moving = 0;
	}

	glutPostRedisplay();
}
void mouseMotion(GLint x, GLint y) {

}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("3D-Pool");
	glewInit(); // for using GSLS
	init();
	//menu();
	glutDisplayFunc(display);
	glutMotionFunc(mouseMotion);
	glutMouseFunc(mouseAction);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}
