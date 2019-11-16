#include <GL/freeglut.h>
#include "GameObject.h"
#include <iostream>

GameObject gameObject(50, 50, 5);

void displayMe(void) {
	gameObject.draw();
}

int main(int argc, char** argv);

void keyboard(unsigned char, int, int);
void mouseMove(int, int);
void reshape(int, int);

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
	std::cout << "mouse moved: " << x << ", " << y << std::endl;
}

void reshape(int width, int height) {
	glViewport(0, 0, (GLsizei) width, (GLsizei) height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 300, 0, 300, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}