#include <GL/freeglut.h>
#include "GameObject.h"
#include "Bullet.h"
#include <iostream>
#include <cmath>
#include "MenuObject.h"

GameObject gameObject(50, 50, 5);
Bullet bullet(10, 10, 1);
MenuObject menu;

void displayMe(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	gameObject.draw();
	bullet.draw();
	glutSwapBuffers();

	//menu.draw();
}

void MouseShoot(int, int, int, int);
void keyboard(unsigned char, int, int);
void mouseMove(int, int);
void reshape(int, int);
void timer(int);

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(600, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Hello world :D");
	glutDisplayFunc(displayMe);
	glutPassiveMotionFunc(mouseMove);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(MouseShoot);
	glutReshapeFunc(reshape);
	glutTimerFunc(1, timer, 0);
	glutMainLoop();
	return 0;
}

void MouseShoot(int button, int state, int x, int y) {
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		double angle2 = atan2((float) y - bullet.getPositionY(), (float) x - bullet.getPositionX());
		bullet.setAngle(angle2);
		bullet.moveBullet();
	}
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'w':
		gameObject.moveUP(key, x, y);
		break;
	case 's':
		gameObject.moveDown(key, x, y);
		break;
	case 'a':
		gameObject.moveLeft(key, x, y);
		break;
	case 'd':
		gameObject.moveRight(key, x, y);
		break;
	case 033:
		glutLeaveMainLoop();
		break;
	}
		
}

void mouseMove(int x, int y) {
	double angle2 = atan2((float) y - gameObject.getPositionY(), (float) x - gameObject.getPositionX()) * 180 / 3.15;
	gameObject.setAngle(angle2);
}

void reshape(int width, int height) {
	glViewport(0, 0, (GLsizei) width, (GLsizei) height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 300, 300, 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}

void timer(int value) {

	glutPostRedisplay();
	glutTimerFunc(1, timer, 0);
}