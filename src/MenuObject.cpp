#include "MenuObject.h"
#include "Sprite.h"
#include <iostream>

Sprite* newGame;
Sprite* settings;
Sprite* exitGame;


void RenderString(float x, float y, void* font, float r, float g, float b, const unsigned char* string)
{
	char* c;
	glColor3f(r, g, b);
	glRasterPos2f(x, y);
	glutBitmapString(font, string);
}

MenuObject::MenuObject() {
	char* filenameNewGame = _strdup("res/player2_3.bmp");
	char* filenameSettings = _strdup("res/settings.bmp");
	char* filenameExit = _strdup("res/player2_3.bmp");

	newGame = new Sprite(width, height, filenameNewGame);
	settings = new Sprite(width, height, filenameSettings);
	exitGame =  new Sprite(width, height, filenameExit);
}


void MenuObject::draw_menu_item(int offset, Sprite* sprite)
{
	//
	glLoadIdentity();
	glPopMatrix();

	glTranslatef(x, y + height + offset, 0);
	sprite->draw();
	glPopMatrix();
	glFlush();

}

void MenuObject::draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	glEnable(GL_STENCIL_TEST);
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);


	unsigned char* tmpBuffer = &titleNewGame[0];

	float offset = 0;
	

	glStencilFunc(GL_ALWAYS,  1, -1);
	//draw_menu_item(tmpBuffer,offset); //kirajzol egy darab menu pontot
	draw_menu_item(offset,newGame);
	//newGame->draw();

	offset = height + space;

	tmpBuffer = &titleSettings[0];
	glStencilFunc(GL_ALWAYS, 2, -1);
	draw_menu_item(offset, settings);
	//draw_menu_item(tmpBuffer, offset); //kirajzol egy darab menu pontot
	//settings->draw();

	offset += height + space;

	tmpBuffer = &titleExit[0];
	glStencilFunc(GL_ALWAYS, 3, -1);
	draw_menu_item(offset, exitGame);
	//exitGame->draw();
	//draw_menu_item(tmpBuffer, offset); //kirajzol egy darab menu pontot
}


