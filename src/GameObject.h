#pragma once
#include "IDrawable.h"
#include "Sprite.h"
#include <GL/freeglut.h>

class GameObject : public IDrawable {
protected:
	float x, y;
	float width, height;
	float origoX, origoY;
	float moveSpeed;
	float angle;
	Sprite* sprite;
public:
	GameObject(float, float, float, char*);
	float getPositionX();
	float getPositionY();
	void setPositionX(float);
	void setPositionY(float);
	void setAngle(float);
	float getAngle();
	void draw();
	void moveUP(unsigned char,int,int);
	void moveDown(unsigned char,int,int);
	void moveRight(unsigned char,int,int);
	void moveLeft(unsigned char,int,int);
};
