#include <GL/freeglut.h>
#include "GameObject.h"
#include "RgbImage.h"
#include "Sprite.h"
#include <iostream>
#include <cmath>

char filename[] = "res/player2_2.bmp";

GameObject gameObject(100, 100, 5, filename);

void displayMe(void) {
	gameObject.draw();
}

int main(int argc, char** argv);

void keyboard(unsigned char, int, int);
void mouseMove(int, int);
void reshape(int, int);
void timer(int);

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Hello world :D");
	glutDisplayFunc(displayMe);
	glutPassiveMotionFunc(mouseMove);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(reshape);
	glutTimerFunc(1, timer, 0);
	glutMainLoop();
	return 0;
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
	glOrtho(0, glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT), 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}

void timer(int value) {
	glutPostRedisplay();
	glutTimerFunc(1, timer, 0);
}