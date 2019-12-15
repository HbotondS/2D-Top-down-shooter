#include "Player.h"

Player::Player(float width, float height, float moveSpeed, char* textureLocation, float health): Entity(width, height, moveSpeed, textureLocation, health, NULL) {
	sprite = new Sprite(width, height, textureLocation);
	x = 100;
	y = 100;
	origoX = width / 2;
	origoY = height / 2;
	angle = 0;
	health = 100;
}
void Player::setHealth(float health) {
	this->health = health;
}

float Player::getHealth() {
	return health;
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
