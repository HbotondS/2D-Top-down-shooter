#include <iostream>
#include <GL/freeglut.h>
#include "Player.h"
#include "Bullet.h"

class Game : IDrawable {
private:
	char *filename;
	Player* player;
	Bullet* bullet;
public:
	Game();
	void onKeyPressed(unsigned char key, int x, int y);
	void onMouseClicked(int button, int state, int x, int y);
	void onMouseMove(int x, int y);
	void timer(void (*t)(int));
	void draw();
};