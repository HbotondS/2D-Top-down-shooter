#pragma once
#include "Entity.h"

class Player : public Entity {
public:
	Player(float, float, float, char*, float );
	~Player() {};
	float getPositionX();
	float getPositionY();
	void setPositionX(float);
	void setPositionY(float);
	void setAngle(float);
	float getAngle();
	void draw();
	void moveUP();
	void moveDown();
	void moveRight();
	void moveLeft();
	void setHealth(float);
	float getHealth();
};

