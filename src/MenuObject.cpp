#include "MenuObject.h"
#include <iostream>


void RenderString(float x, float y, void* font, float r, float g, float b, const unsigned char* string) {
	char* c;
	glColor3f(r, g, b);
	glRasterPos2f(x, y);
	glutBitmapString(font, string);
}

MenuObject::MenuObject() {}

void MenuObject::drawMenuItem(const unsigned char* title, float offset) {
	glColor3f(255, 0, 0);

	glBegin(GL_POLYGON);
	glVertex2f(x, y - offset);
	glVertex2f(x + width, y - offset);
	glVertex2f(x + width, y + height - offset);
	glVertex2f(x, y + height - offset);
	glEnd();

	RenderString(x + (width / 4), y - offset + (height / 3), GLUT_BITMAP_TIMES_ROMAN_24, 255, 255, 255, title);

	glFlush();
}

void MenuObject::draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	glEnable(GL_STENCIL_TEST);
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

	float offset = 0;

	glStencilFunc(GL_ALWAYS, 1, -1);
	drawMenuItem(titleNewGame, offset);

	offset = height + space;

	glStencilFunc(GL_ALWAYS, 2, -1);
	drawMenuItem(titleSettings, offset);
	offset += height + space;

	glStencilFunc(GL_ALWAYS, 3, -1);
	drawMenuItem(titleExit, offset);
}


void MenuObject::changeGameMode() {
	if (gameMode < 2) gameMode++;
	else gameMode = 0;
}


void MenuObject::drawSettings() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	glLoadIdentity(); // Reset The Projection Matrix
	glEnable(GL_STENCIL_TEST);
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
	
	unsigned char* tmpBuffer =&titleEasy[0] ;

	switch (gameMode) {
	case 0: tmpBuffer = &titleEasy[0]; break;
	case 1: tmpBuffer = &titleNormal[0]; break;
	case 2: tmpBuffer = &titleHard[0]; break;
	}

	float offset = 0;

	glStencilFunc(GL_ALWAYS, 1, -1);
	drawMenuItem(tmpBuffer, offset);

	offset = height + space;

	tmpBuffer = &titleBack[0];
	glStencilFunc(GL_ALWAYS, 2, -1);
	drawMenuItem(tmpBuffer, offset);
}

unsigned int MenuObject::getGameMode() {
	return gameMode;
}