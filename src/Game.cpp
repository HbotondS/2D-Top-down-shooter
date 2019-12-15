#include "Game.h"
#include <time.h>

Game::Game() {
	filename = _strdup("res/player2_2.bmp");
	filename2 = _strdup("res/enemy.bmp");
	player = new Player(100, 100, 5, filename, 100);
}

void Game::setGameMode(unsigned int mode)
{
	int health = 100;
	switch (mode) {
	case 0: health = 120; break;
	case 1: health = 100; break;
	case 2: health = 80; break;
	}
	player->setHealth(health);
}

// found in OpenGL Game Development by Example just rewrote to be compatible with this program 
void Game::SpawnEnemy() {
	enemy = new Enemy(70, 70, 1, filename2, 100, 10);
	float marginX = enemy->getWidth();
	float marginY = enemy->getHeight();
	float spawnX = (rand() % (int)(glutGet(GLUT_WINDOW_WIDTH) - (marginX * 2))) + marginX;
	float spawnY = glutGet(GLUT_WINDOW_HEIGHT) - ((rand() % (int)(player->getHeight() - (marginY * 2))) + marginY);
	enemy->setPositionX(spawnX);
	enemy->setPositionY(spawnY);
}


void Game::moveEnemy() {
	float dirX = player->getPositionX() - enemy->getPositionX();
	float dirY = player->getPositionY() - enemy->getPositionY();
	float normalize = sqrt(dirX * dirX + dirY * dirY);
	dirX /= normalize;
	dirY /= normalize;
	enemy->setPositionX(enemy->getPositionX() + dirX * enemy->getMoveSpeed());
	enemy->setPositionY(enemy->getPositionY() + dirY * enemy->getMoveSpeed());

	double angle = atan2(dirY, dirX) * 180 / 3.15;
	enemy->setAngle(angle);
}

void Game::onKeyPressed(unsigned char key, int x, int y) {
	switch(key) {
	case 'w':
		player->moveUP();
		break;
	case 's':
		player->moveDown();
		break;
	case 'a':
		player->moveLeft();
		break;
	case 'd':
		player->moveRight();
		break;
	case 033:
		glutLeaveMainLoop();
		break;
	}
}

void Game::onMouseClicked(int button, int state, int x, int y) {
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		bullet = new Bullet(10, 10, 50, 20);
		bullet->setPositionX(player->getPositionX());
		bullet->setPositionY(player->getPositionY());
		double angle = atan2((float) y - player->getPositionY(), (float) x - player->getPositionX());
		bullet->setAngle(angle);
	}
}

void Game::onMouseMove(int x, int y) {
	double angle = atan2((float) y - player->getPositionY(), (float) x - player->getPositionX()) * 180 / 3.15;
	player->setAngle(angle);
}

void Game::timer(void(*t)(int)) {
	if(bullet != nullptr) {
		bullet->moveBullet();
		if(bullet->getPositionX() > glutGet(GLUT_WINDOW_WIDTH) || bullet->getPositionY() > glutGet(GLUT_WINDOW_HEIGHT)) {
			delete bullet;
			bullet = nullptr;
		}
	}
	if (enemy != nullptr) {
		moveEnemy();
	}

	if (detectCollision(enemy, bullet)) {

		enemy->setHealth(enemy->getHealth() - bullet->getDamage());
		pushBack(bullet, enemy);
		delete bullet;
		bullet = nullptr;
		if (enemy->getHealth() == 0) {
			enemy = nullptr;
			delete enemy;
		}
	}

	if (detectCollision(player, enemy)) {
		player->setHealth(player->getHealth() - enemy->getDamage());
		pushBack(enemy, player);
		if (player->getHealth() <= 0) {
			exit(0);
		}
	}

	glutPostRedisplay();
	glutTimerFunc(1, t, 0);
}

void Game::draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	player->draw();
	if(bullet != nullptr) {
		bullet->draw();
	}
	if (enemy == nullptr) {
		SpawnEnemy();
	} else {
		enemy->draw();
	}
	glutSwapBuffers();

	glFlush();
}

// AABB (axis-aligned bounding box) collision
bool Game::detectCollision(Entity* entity1, Entity* entity2) {
	if(entity2 == nullptr) {
		return false;
	}
	bool collisionX = entity1->getPositionX() + entity1->getWidth() >= entity2->getPositionX() &&
		entity2->getPositionX() + entity2->getWidth() >= entity1->getPositionX();
	bool collisionY = entity1->getPositionY() + entity1->getHeight() >= entity2->getPositionY() &&
		entity2->getPositionY() + entity2->getHeight() >= entity1->getPositionY();

	return collisionX && collisionY;
}

void Game::pushBack(Entity* entity1, Entity* entity2) {
		// bal felso sarokba loki 
	if (entity1->getPositionX() > entity2->getPositionX() && entity1->getPositionY() > entity2->getPositionY())
	{
		entity2->setPositionX(entity2->getPositionX() - 30);
		entity2->setPositionY(entity2->getPositionY() - 30);
	}
		//bal also sarokba loki
	if (entity1->getPositionX() > entity2->getPositionX() && entity1->getPositionY() < entity2->getPositionY()) {
		entity2->setPositionX(entity2->getPositionX() - 30);
		entity2->setPositionY(entity2->getPositionY() + 30);
	}
		//jobb felso sarokba loki
	if (entity1->getPositionX() < entity2->getPositionX() && entity1->getPositionY() > entity2->getPositionY()) {
		entity2->setPositionX(entity2->getPositionX() + 30);
		entity2->setPositionY(entity2->getPositionY() - 30);
	}
		//jobb also sarokba loki
	if (entity1->getPositionX() < entity2->getPositionX() && entity1->getPositionY() < entity2->getPositionY()) {
		entity2->setPositionX(entity2->getPositionX() + 30);
		entity2->setPositionY(entity2->getPositionY() + 30);
	}
		// felfele loki
	if (entity1->getPositionX() == entity2->getPositionX() && entity1->getPositionY() > entity2->getPositionY())
		entity2->setPositionY(entity2->getPositionY() - 30);
		
		//lefele loki
	if (entity1->getPositionX() == entity2->getPositionX() && entity1->getPositionY() < entity2->getPositionY())
		entity2->setPositionY(entity2->getPositionY() + 30);
						
		//jobbra loki 
	if (entity1->getPositionX() < entity2->getPositionX() && entity1->getPositionY() == entity2->getPositionY())
		entity2->setPositionX(entity2->getPositionX() + 30);
								
		//balra loki
	if (entity1->getPositionX() > entity2->getPositionX() && entity1->getPositionY() == entity2->getPositionY())
		entity2->setPositionX(entity2->getPositionX() - 30);

}