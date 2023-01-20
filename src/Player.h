#include "Entity.h"

class Player: public Entity {
public:
	Player(float, float, float, char*, float);
	~Player() {};
	void draw();
	void moveUP();
	void moveDown();
	void moveRight();
	void moveLeft();
	void setHealth(float);
	float getHealth();
};

