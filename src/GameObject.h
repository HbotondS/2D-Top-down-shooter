#pragma once
#include "IDrawable.h"
#include <GL/freeglut.h>

class GameObject: public IDrawable {
private:
	float x, y;
	float width, height;
public:
	GameObject(float, float);
	void draw();
};

