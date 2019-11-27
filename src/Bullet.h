#pragma once
#include "IDrawable.h"
#include <GL/freeglut.h>
#include "GameObject.h"
#include <iostream>
#include <vector>


class Bullet : public GameObject, public IDrawable {

public:
	Bullet(float, float, float);
	~Bullet();
	void draw();
	void moveBullet();
	std::vector<Bullet> bullets;
};