#pragma once
#include "Entity.h"

class Enemy : public Entity {

public:
	Enemy(float, float, float, char*, float, float);
	~Enemy() {};
	float getPositionX();
	float getPositionY();
	void setPositionX(float);
	void setPositionY(float);
	void setAngle(float);
	float getAngle();
	float getMoveSpeed();
	void moveEnemy();
	void draw();
	void setDamage(float);
	void setHealth(float);
	float getHealth();
	float getDamage();


};

