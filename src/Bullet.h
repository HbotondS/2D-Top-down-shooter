#pragma once
#include "IDrawable.h"
#include <GL/freeglut.h>
#include "Entity.h"
#include <iostream>
#include <vector>

class Bullet : public Entity {

public:
	std::vector<Bullet> bullets;

	Bullet(float, float, float, float);
	~Bullet();
	void draw();
	void moveBullet();
	float getPositionX();
	float getPositionY();
	void setPositionX(float);
	void setPositionY(float);
	void setAngle(float);
	float getAngle();
	void setDamage(float);
	float getDamage();
};