#include "Entity.h"
#include <iostream>

Entity::Entity(float width, float height, float moveSpeed, char* textureLocation): width(width), height(height), moveSpeed(moveSpeed) {
	sprite = new Sprite(width, height, textureLocation);
	x = 100;
	y = 100;
	origoX = width / 2;
	origoY = height / 2;
	angle = 0;
}