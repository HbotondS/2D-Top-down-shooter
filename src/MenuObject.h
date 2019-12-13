#pragma once

#include "IDrawable.h"
#include <GL/freeglut.h>

class MenuObject : public IDrawable
{
private:
	float x = -0.4, y = 0.3, space = 0.2;
	float width = 0.6, height = 0.2;
	void draw_menu_item(const unsigned char* title, float offset);
	unsigned char titleNewGame[9] = "New Game";
	unsigned char titleSettings[9] = "Settings";
	unsigned char titleExit[5] = "Exit";

	static unsigned char selectedItem; //0- None 1 - New Game, 2- Settings, 3 - Exit



public:
	MenuObject();
	void draw();
};

