#include <GL/freeglut.h>
#include "GameObject.h"
#include "MenuObject.h"

void displayMe(void) {
	GameObject gameObject(0.5, 0.5);
	gameObject.draw();

	MenuObject menu;
	//menu.draw();
}

void keyboard(unsigned char, int, int);

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(600, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Hello world :D");
	glutDisplayFunc(displayMe);
	glutKeyboardFunc(keyboard);
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