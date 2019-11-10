#include <GL/freeglut.h>
#include "GameObject.h"
#include <iostream>

GameObject gameObject(0.5, 0.5);

void displayMe(void) {

	gameObject.draw();
	
}
//I've also tried this, but didn't work so ff at 20 min 
/*
void keyboard(unsigned char key, int x, int y) {
	 gameObject.keyboard_down(key,x,y);
}*/

int main(int argc, char** argv) {
	unsigned char key;
	int x = 0, y = 0;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Hello world :D");
	glutDisplayFunc(displayMe);
	//glutKeyboardFunc(gameObject.keyboard_down(key,x,y));
	glutKeyboardFunc(gameObject.keyboard_down);
	glutMainLoop();
	return 0;

}


