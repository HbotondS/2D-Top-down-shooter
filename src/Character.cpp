#include "Character.h"
#include <GL/freeglut.h>


void Character::draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.8f,0.15f, 0.25f);

	glBegin(GL_POLYGON);

	glVertex2f(x, y);
	glVertex2f(x + width, y);
	glVertex2f(x + width, y + height);
	glVertex2f(x, y + height);
	glEnd();
	// RenderString(x + (width / 4), y - offset + (height / 3), GLUT_BITMAP_TIMES_ROMAN_24, 255, 255, 255, title);

	glFlush();
}

void Character::game(const char* title, int width, int hight, bool fullscreen)
{
	int flags = 0;
	if (fullscreen) {


	}
}
