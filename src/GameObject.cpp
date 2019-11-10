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

void GameObject::keyboard_down(unsigned char key, int xmouse, int ymouse) 
{
	switch (key)
	{
	case 033: // octal equivalent of the Escape key
		glutLeaveMainLoop();
		break;
	case 'w':
		// increase the camera's Z velocity
		x++;
		std::cout << x << std::endl;
		glutPostRedisplay();
		break;
	case 's':
		// decrease the camera's Z velocity
		x--;
		std::cout << x << std::endl;
		glutPostRedisplay();
		break;
	case 'a':
		// decrease the camera's X velocity
		y--;
		std::cout << y << std::endl;
		glutPostRedisplay();
		break;
	case 'd':
		// increase the camera's X velocity
		y++;
		std::cout << y << std::endl;
		glutPostRedisplay();
		break;
	}
}


