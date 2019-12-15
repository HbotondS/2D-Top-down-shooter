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
	virtual float getPositionX();
	virtual float getPositionY();
	virtual void setPositionX(float);
	virtual void setPositionY(float);
	virtual float getWidth();
	virtual float getHeight();
	virtual void setAngle(float);
	virtual float getAngle();
	virtual void draw() = 0;
};
