#include <GL/freeglut.h>
#include "Entity.h"
#include <iostream>
#include <vector>

class Bullet: public Entity {

public:
	std::vector<Bullet> bullets;

	Bullet(float, float, float, float);
	Bullet(float, float, float, char*, float, float);
	~Bullet();
	void draw();
	void moveBullet();
	void setDamage(float);
	float getDamage();
};