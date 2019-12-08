#include <GL/freeglut.h>
#include <iostream>
#include <cmath>
#include "MenuObject.h"
#include "Game.h"

MenuObject menu;

Game* game = new Game();

void displayMe(void) {
	game->draw();

	// menu.draw();
}

void MouseShoot(int, int, int, int);
void keyboard(unsigned char, int, int);
void mouseMove(int, int);
void reshape(int, int);
void timer(int);
void onMouse(int button, int state, int x, int y);

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
	glutMouseFunc(MouseShoot);
	glutMainLoop();
	return 0;
}


void MouseShoot(int button, int state, int x, int y) {
	game->onMouseClicked(button, state, x, y);
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
	game->onKeyPressed(key, x, y);
}

void mouseMove(int x, int y) {
	game->onMouseMove(x, y);
}

void reshape(int width, int height) {
	glViewport(0, 0, (GLsizei) width, (GLsizei) height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT), 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}

void timer(int value) {
	game->timer(timer);
}