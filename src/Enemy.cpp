
#include "Enemy.h"
#include <math.h>

Enemy::Enemy(float width, float height, float moveSpeed, char* textureLocation, float health, float damage) : Entity(width, height, moveSpeed, textureLocation, health, damage) {
	sprite = new Sprite(width, height, textureLocation);
	x = 100;
	y = 100;
	origoX = width / 2;
	origoY = height / 2;
	angle = 0;
	health = 100;
	damage = 10;
}

void Enemy::setDamage(float damage){
	this->damage = damage;
}

float Enemy::getDamage() {
	return damage;
}

void Enemy::setHealth(float health) {
	this->health = health;
}

float Enemy::getHealth() {
	return health;
}

float Enemy::getPositionX() {
	return x;
}
float Enemy::getPositionY() {
	return y;
}

void Enemy::setPositionX(float x) {
	this->x = x;
}

void Enemy::setPositionY(float y) {
	this->y = y;
}

void Enemy::setAngle(float angle) {
	this->angle = angle;
}

float Enemy::getAngle() {
	return angle;
}

float Enemy::getMoveSpeed() {
	return moveSpeed;
}

/*
void Enemy::moveEnemy() {
	glPushMatrix();
	glTranslatef(x, y, 0);
	glRotatef(angle, 0, 0, 1);
	x += moveSpeed * cos(angle);
	y += moveSpeed * sin(angle);
	glPopMatrix();
	draw();
}
*/
void Enemy::draw() {
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(x, y, 0);
	glRotatef(angle, 0, 0, 1);
	sprite->draw();
	glPopMatrix();
}