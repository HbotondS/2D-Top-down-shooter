#pragma once
#include "IDrawable.h"
#include "Sprite.h"
#include <GL/freeglut.h>

class Entity: public IDrawable {
protected:
	float x, y;
	float width, height;
	float origoX, origoY;
	float moveSpeed;
	float angle;
	Sprite* sprite;
	float health, damage;
public:
	Entity(float, float, float, char*, float, float);
	virtual float getPositionX() = 0;
	virtual float getPositionY() = 0;
	virtual void setPositionX(float) = 0;
	virtual void setPositionY(float) = 0;
	virtual float getWidth();
	virtual float getHeight();
	virtual void setAngle(float) = 0;
	virtual float getAngle() = 0;
	virtual void draw() = 0;
};
