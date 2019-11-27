#include "Bullet.h"
#include "GameObject.h"
#include <iostream>
#include <math.h>


Bullet::Bullet(float width, float height, float moveSpeed):GameObject(width, height, moveSpeed, nullptr) {
	x = GameObject::getPositionX();
	y = GameObject::getPositionY();
	origoX = width / 2;
	origoY = height / 2;
	angle = 0;
	moveSpeed = 1;
}

Bullet::~Bullet() {
}

void Bullet::moveBullet() {
	glPushMatrix();
	glTranslatef(x, y, 0);
	glRotatef(angle, 0, 0, 1);
	x += moveSpeed * cos(angle);
	y += moveSpeed * sin(angle);
	glPopMatrix();
	draw();
}


void Bullet::draw() {
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
}

