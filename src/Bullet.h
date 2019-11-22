#pragma once
#include "IDrawable.h"
#include <GL/freeglut.h>
#include "GameObject.h"

class Bullet : public GameObject, public IDrawable  {
private:
	float x, y;
	float width, height;
	float origoX, origoY;
	float moveSpeed;
	float angle;
public:

	Bullet(float, float, int);
	void draw();
	void moveBullet();
	
};
