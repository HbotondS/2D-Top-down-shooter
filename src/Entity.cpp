#include "Entity.h"
#include <iostream>

Entity::Entity(float width, float height, float moveSpeed, char* textureLocation, float health, float damage)
	: width(width), height(height), moveSpeed(moveSpeed), health(health), damage(damage) {

	sprite = new Sprite(width, height, textureLocation);
	x = 100;
	y = 100;
	origoX = width / 2;
	origoY = height / 2;
	angle = 0;
}

float Entity::getPositionX() {
	return x;
}

float Entity::getPositionY() {
	return y;
}

void Entity::setPositionX(float x) {
	this->x = x;
}

void Entity::setPositionY(float y) {
	this->y = y;
}

float Entity::getWidth() {
	return width;
}

float Entity::getHeight() {
	return height;
}

void Entity::setAngle(float angle) {
	this->angle = angle;
}

float Entity::getAngle() {
	return angle;
}
