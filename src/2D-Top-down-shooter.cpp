#include <GL/freeglut.h>
#include "GameObject.h"
#include "MenuObject.h"

GameObject gameObject(0.5, 0.5);
MenuObject menu;

void displayMe(void) {
	gameObject.draw();

	menu.draw();
}

void keyboard(unsigned char, int, int);
void onMouse(int button, int state, int x, int y);

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(600, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Hello world :D");
	glutDisplayFunc(displayMe);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(onMouse);
	glutMainLoop();
	return 0;

}

void onMouse(int button, int state, int x, int y) {
	if (state != GLUT_DOWN)
		return;

	int window_width = glutGet(GLUT_WINDOW_WIDTH);
	int window_height = glutGet(GLUT_WINDOW_HEIGHT);

	GLbyte color[4];
	GLfloat depth;
	GLuint index;

	glReadPixels(x, window_height - y - 1, 1, 1, GL_STENCIL_INDEX, GL_UNSIGNED_INT, &index);

	int selected=index;
	switch (selected) {
	case 3:exit(0);
		break;
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