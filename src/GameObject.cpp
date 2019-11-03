#include "GameObject.h"
#include <iostream>

GameObject::GameObject(float width, float height): width(width), height(height) {
	x = 0.0;
	y = 0.0;
}

void GameObject::draw() {
	std::cout << "draw";
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glVertex2f(x, y);
	glVertex2f(x + width, y);
	glVertex2f(x + width, y + height);
	glVertex2f(x, y + height);
	glEnd();
	glFlush();
}
