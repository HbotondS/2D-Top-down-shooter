#include "GameObject.h"
#include <iostream>



GameObject::GameObject(float width, float height, float moveSpeed): width(width), height(height), moveSpeed(moveSpeed) {
	x = 0.0;
	y = 0.0;
}

void GameObject::draw() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glVertex2f(x, y);
	glVertex2f(x + width, y);
	glVertex2f(x + width, y + height);
	glVertex2f(x, y + height);
	glEnd();
	glFlush();
}


void GameObject::moveUP(unsigned char key, int xmouse, int ymouse){
	key = 'w';
	y += moveSpeed;
	// std::cout << y << std::endl;
	glutPostRedisplay();
}

void GameObject::moveDown(unsigned char key, int xmouse, int ymouse){
	key = 's';
	y -= moveSpeed;
	// std::cout << y << std::endl;
	glutPostRedisplay();
}

void GameObject::moveLeft(unsigned char key,int xmouse, int ymouse){
	key = 'a';
	x -= moveSpeed;
	// std::cout << x << std::endl;
	glutPostRedisplay();
}

void GameObject::moveRight(unsigned char key, int xmouse, int ymouse) {
	key = 'd';
	x += moveSpeed;
	// std::cout << x << std::endl;
	glutPostRedisplay();
}