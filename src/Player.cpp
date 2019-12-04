#include "Player.h"

Player::Player(float width, float height, float moveSpeed, char* textureLocation): Entity(width, height, moveSpeed, textureLocation) {
	sprite = new Sprite(width, height, textureLocation);
	x = 100;
	y = 100;
	origoX = width / 2;
	origoY = height / 2;
	angle = 0;
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
