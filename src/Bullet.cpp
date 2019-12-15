#include "Bullet.h"
#include "Entity.h"
#include <iostream>
#include <math.h>

Bullet::Bullet(float width, float height, float moveSpeed, float damage)
	: Entity(width, height, moveSpeed, nullptr, 0, damage) {

	origoX = width / 2;
	origoY = height / 2;
	angle = 0;
	moveSpeed = 1;
	damage = 20;
}

Bullet::Bullet(float width, float height, float moveSpeed, char* textureLocation, float health, float damage)
	: Entity(width, height, moveSpeed, textureLocation, health, damage) {

	sprite = new Sprite(width, height, textureLocation);
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
	glRotatef(angle * 180 / 3.15, 0, 0, 1);
	sprite->draw();
	glPopMatrix();
}

