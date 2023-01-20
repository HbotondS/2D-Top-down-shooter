#include "IDrawable.h"
#include <GL/freeglut.h>

class MenuObject: public IDrawable {

private:
	float x = -0.4, y = 0.3, space = 0.2;
	float width = 0.6, height = 0.2;
	void drawMenuItem(const unsigned char* title, float offset);
	unsigned char titleNewGame[9] = "New Game";
	unsigned char titleSettings[9] = "Settings";
	unsigned char titleExit[5] = "Exit";
	unsigned char titleEasy[5]= "Easy";
	unsigned char titleNormal[7] = "Normal";
	unsigned char titleHard[5] = "Hard";
	unsigned char titleBack[5] = "Back";
	static unsigned char selectedItem; //0- None 1 - New Game, 2- Settings, 3 - Exit
	unsigned int gameMode=0; // 0 easy, 1 normal, 2 hard

public:
	MenuObject();
	void draw();
	void changeGameMode();
	void drawSettings();
	unsigned int getGameMode();
};