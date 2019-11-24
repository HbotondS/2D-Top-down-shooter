#include "MenuObject.h"
#include <iostream>


void RenderString(float x, float y, void* font, float r, float g, float b, const unsigned char* string)
{
	char* c;
	glColor3f(r, g, b);
	glRasterPos2f(x, y);
	glutBitmapString(font, string);
}

MenuObject::MenuObject() {
	
}



 

void MenuObject::draw_menu_item(const unsigned char* title, float offset)
{
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

	std::cout << "draw";
	unsigned char* tmpBuffer = &titleNewGame[0];

	float offset = 0;
	
	glStencilFunc(GL_ALWAYS,  1, -1);
	draw_menu_item(tmpBuffer,offset); //kirajzol egy darab menu pontot

	offset = height + space;

	tmpBuffer = &titleSettings[0];
	glStencilFunc(GL_ALWAYS, 2, -1);
	draw_menu_item(tmpBuffer, offset); //kirajzol egy darab menu pontot

	offset += height + space;

	tmpBuffer = &titleExit[0];
	glStencilFunc(GL_ALWAYS, 3, -1);
	draw_menu_item(tmpBuffer, offset); //kirajzol egy darab menu pontot
}


