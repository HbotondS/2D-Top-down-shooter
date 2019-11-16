#pragma once
#include "IDrawable.h"
#include <GL/freeglut.h>

class GameObject : public IDrawable {
private:
	float x, y;
	float width, height;
	float moveSpeed;
public:
	GameObject(float, float, float);
	void draw();
	void moveUP(unsigned char,int,int);
	void moveDown(unsigned char,int,int);
	void moveRight(unsigned char,int,int);
	void moveLeft(unsigned char,int,int);
};
