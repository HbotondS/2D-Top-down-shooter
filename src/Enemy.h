#pragma once
#include "Entity.h"

class Enemy: public Entity {

public:
	Enemy(float, float, float, char*, float, float);
	~Enemy() {};
	float getMoveSpeed();
	void draw();
	void setDamage(float);
	void setHealth(float);
	float getHealth();
	float getDamage();
};

