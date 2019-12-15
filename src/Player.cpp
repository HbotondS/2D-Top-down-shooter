#include "Player.h"

Player::Player(float width, float height, float moveSpeed, char* textureLocation, float health): Entity(width, height, moveSpeed, textureLocation, health, NULL) {
	sprite = new Sprite(width, height, textureLocation);
	x = 100;
	y = 100;
	origoX = width / 2;
	origoY = height / 2;
	angle = 0;
	setHealth(health);
}
void Player::setHealth(float health) {
	this->health = health;
}

float Player::getHealth() {
	return health;
}

float Player::getPositionX() {
	return x;
}
float Player::getPositionY() {
	return y;
}

void Player::setPositionX(float x) {
	this->x = x;
}

void Player::setPositionY(float y) {
	this->y = y;
}

void Player::setAngle(float angle) {
	this->angle = angle;
}

float Player::getAngle() {
	return angle;
}

void Player::draw() {
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(x, y, 0);
	glRotatef(angle, 0, 0, 1);
	sprite->draw();
	glPopMatrix();
	glFlush();
}

void Player::moveUP() {
	y -= moveSpeed;
}

void Player::moveDown() {
	y += moveSpeed;
}

void Player::moveLeft() {
	x -= moveSpeed;
}

void Player::moveRight() {
	x += moveSpeed;
}
