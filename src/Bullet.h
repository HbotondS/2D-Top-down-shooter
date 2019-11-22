#pragma once
#include "IDrawable.h"
#include <GL/freeglut.h>
#include "GameObject.h"

class Bullet : public GameObject, public IDrawable {
public:
	Bullet(float, float, int);
	void draw();
	void moveBullet();	
};
