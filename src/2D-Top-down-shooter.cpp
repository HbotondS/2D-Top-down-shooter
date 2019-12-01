#include <GL/freeglut.h>
#include <iostream>
#include <cmath>
#include "Bullet.h"
#include "MenuObject.h"
#include "Player.h"
#define max_bullet 5

Bullet* bullet;
MenuObject menu;
char filename[] = "res/player2_2.bmp";

Player player(100, 100, 5, filename);

void displayMe(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	player.draw();
	if(bullet != nullptr) {
		bullet->draw();
	}
	glutSwapBuffers();

	//menu.draw();
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
   if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
	{
	   bullet = new Bullet(10, 10, 50);
	   bullet->setPositionX(player.getPositionX());
	   bullet->setPositionY(player.getPositionY());
	   double angle2 = atan2((float) y - player.getPositionY(), (float) x - player.getPositionX());
	   bullet->setAngle(angle2);
	}
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
		player.moveUP();
		break;
	case 's':
		player.moveDown();
		break;
	case 'a':
		player.moveLeft();
		break;
	case 'd':
		player.moveRight();
		break;
	case 033:
		glutLeaveMainLoop();
		break;
	}	
}

void mouseMove(int x, int y) {
	double angle = atan2((float) y - player.getPositionY(), (float) x - player.getPositionX()) * 180 / 3.15;
	player.setAngle(angle);
}

void reshape(int width, int height) {
	glViewport(0, 0, (GLsizei) width, (GLsizei) height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT), 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}

void timer(int value) {
	if(bullet != nullptr) {
		bullet->moveBullet();
		if(bullet->getPositionX() > glutGet(GLUT_WINDOW_WIDTH) || bullet->getPositionY() > glutGet(GLUT_WINDOW_HEIGHT)) {
			delete bullet;
			bullet = nullptr;
		}
	}

	glutPostRedisplay();
	glutTimerFunc(1, timer, 0);
}