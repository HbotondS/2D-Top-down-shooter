#include <GL/freeglut.h>
#include <iostream>
#include <cmath>
#include "MenuObject.h"
#include "Game.h"

#define _WIN32_WINNT 0x500

MenuObject menu;

Game* game = new Game();

void displayMenu(void) {
	menu.draw();
}

void displayGame(void) {
	game->draw();
}

void startNewGame();
void startSettings();
void MouseShoot(int, int, int, int);
void keyboard(unsigned char, int, int);
void mouseMove(int, int);
void reshape(int, int);
void timer(int);
void onMouseMenu(int button, int state, int x, int y);

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(600, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Hello world :D");
	glutDisplayFunc(displayMenu);
	glutMouseFunc(onMouseMenu);
	glutMainLoop();
	return 0;
}


void MouseShoot(int button, int state, int x, int y) {
	game->onMouseClicked(button, state, x, y);
}

void onMouseMenu(int button, int state, int x, int y) {
	if (state != GLUT_DOWN)
		return;

	int window_width = glutGet(GLUT_WINDOW_WIDTH);
	int window_height = glutGet(GLUT_WINDOW_HEIGHT);

	GLbyte color[4];
	GLfloat depth;
	GLuint index;

	glReadPixels(x, window_height - y - 1, 1, 1, GL_STENCIL_INDEX, GL_UNSIGNED_INT, &index);

	int selected = index;
	switch (selected) {
		case 1: {
			startNewGame();
			break;
		}
		case 2: {
			startSettings();
			break;
		}
		case 3: {
			exit(0);
		}
	}
}

void keyboard(unsigned char key, int x, int y) {
	game->onKeyPressed(key, x, y);
}

void mouseMove(int x, int y) {
	game->onMouseMove(x, y);
}

void startSettings() {
	// todo
}

// initialize Game functions such as Mouse and Keyboard, change the menu draw function
// into game draw function
void startNewGame() {
	glutDisplayFunc(displayGame);
	glutPassiveMotionFunc(mouseMove);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(reshape);
	glutTimerFunc(1, timer, 0);
	glutMouseFunc(MouseShoot);
	glutFullScreen();
}

void reshape(int width, int height) {
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT), 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}

void timer(int value) {
	game->timer(timer);
}