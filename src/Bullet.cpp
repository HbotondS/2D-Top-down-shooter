#include "Bullet.h"
#include "Entity.h"
#include <iostream>
#include <math.h>

Bullet::Bullet(float width, float height, float moveSpeed, float damage) : Entity(width, height, moveSpeed, nullptr ,0 , damage) {
	origoX = width / 2;
	origoY = height / 2;
	angle = 0;
	moveSpeed = 1;
	damage = 20;
}

Bullet::~Bullet() {}

float Bullet::getDamage() {
	return damage;
}

void Bullet::setDamage(float damage) {
	this->damage = damage;
}

float Bullet::getPositionX() {
	return x;
}
float Bullet::getPositionY() {
	return y;
}

void Bullet::setPositionX(float x) {
	this->x = x;
}

void Bullet::setPositionY(float y) {
	this->y = y;
}

void Bullet::setAngle(float angle) {
	this->angle = angle;
}

float Bullet::getAngle() {
	return angle;
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

