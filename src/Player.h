#pragma once
#include "Entity.h"

class Player : public Entity {
public:
	Player(float, float, float, char*);
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
};

