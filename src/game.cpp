/*
 * game.cpp
 *
 *  Created on: Nov 28, 2017
 *      Author: garre
 */
#include "MainControl.hpp"
void init(void){
	glClearColor(1.0, 1.0, 1.0, 0.0); // Set display-window color to white
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, winWidth, winHeight, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glFlush();


}
void reset(void){

		glDisable(GL_CULL_FACE);
		glDisable(GL_DEPTH_TEST);
		glDisable(GL_NORMALIZE);
		glDisable(GL_COLOR_MATERIAL);
		glDisable( GL_LIGHTING );
		glDisable(GL_LIGHT0);
		glFlush();
		glutPostRedisplay();
}
void close(void){
	exit(1);
}
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	myWorld.draw_world();//draw table, balls,
	myTable.draw();
	glutPostRedisplay();
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
