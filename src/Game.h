#include <iostream>
#include <GL/freeglut.h>
#include "Entity.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

class Game: IDrawable {
private:
	char* filename;
	char* filename2;
	char* filename3;
	Player* player;
	Bullet* bullet;
	Enemy* enemy;
public:
	Game();
	void onKeyPressed(unsigned char key, int x, int y);
	void onMouseClicked(int button, int state, int x, int y);
	void onMouseMove(int x, int y);
	void timer(void (*t)(int));
	void draw();
	bool detectCollision(Entity* entity1, Entity* entity2);
	void SpawnEnemy();
	void moveEnemy();
	void pushBack(Entity* entity1, Entity* entity2);
};
