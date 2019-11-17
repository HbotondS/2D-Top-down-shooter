#include <GL/freeglut.h>
#include "GameObject.h"
#include "MenuObject.h"

void displayMe(void) {
	//GameObject gameObject(0.5, 0.5);
	//gameObject.draw();

	MenuObject menu;
	menu.draw();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(600, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Hello world :D");
	glutDisplayFunc(displayMe);
	glutMainLoop();
	return 0;
}