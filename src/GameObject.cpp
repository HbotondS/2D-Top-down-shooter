#include "GameObject.h"
#include <iostream>



GameObject::GameObject(float width, float height, float moveSpeed): width(width), height(height), moveSpeed(moveSpeed) {
	x = 100;
	y = 100;
	origoX = width / 2;
	origoY = height / 2;
	angle = 0;
}

void GameObject::draw() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(x, y, 0);
	glRotatef(angle, 0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex2f(-origoX, -origoY);
	glVertex2f(-origoX + width, -origoY);
	glVertex2f(-origoX + width, -origoY + height);
	glVertex2f(-origoX, -origoY + height);
	glEnd();
	glPopMatrix();
	glutSwapBuffers();
}


float GameObject::getPositionX() {
	return x;
}
float GameObject::getPositionY() {
	return y;
}

void GameObject::setAngle(float angle) {
	this->angle = angle;
}

float GameObject::getAngle() {
	return angle;
}

void GameObject::moveUP(unsigned char key, int xmouse, int ymouse){
	key = 'w';
	y -= moveSpeed;
	// std::cout << y << std::endl;
	glutPostRedisplay();
}

void GameObject::moveDown(unsigned char key, int xmouse, int ymouse){
	key = 's';
	y += moveSpeed;
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
