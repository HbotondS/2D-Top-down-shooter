#include "Game.h"

Game::Game() {
	filename = _strdup("res/player2_2.bmp");
	player = new Player(100, 100, 5, filename);
}

// found in OpenGL Game Development by Example 
void Game::SpawnEnemy() {
	enemy = new Enemy(100, 100, 5, filename);
	float marginX = enemy->getWidth();
	float marginY = enemy->getHeight();
	float spawnX = (rand() % (int)(glutGet(GLUT_WINDOW_WIDTH) - (marginX * 2))) + marginX;
	float spawnY = glutGet(GLUT_WINDOW_HEIGHT) - ((rand() % (int)(player->getHeight() - (marginY * 2))) + marginY);
	enemy->setPositionX(spawnX);
	enemy->setPositionY(spawnY);
	enemy->setAngle(player->getAngle());
}


void Game::moveEnemy() {
	float dirX = player->getPositionX() - enemy->getPositionX();
	float dirY = player->getPositionY() - enemy->getPositionY();
	float normalize = sqrt(dirX * dirX + dirY * dirY);
	dirX /= normalize;
	dirY /= normalize;
	enemy->setPositionX(enemy->getPositionX() + dirX * enemy->getMoveSpeed());
	enemy->setPositionY(enemy->getPositionY() + dirY * enemy->getMoveSpeed());
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
		bullet = new Bullet(10, 10, 50);
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

	glutPostRedisplay();
	glutTimerFunc(1, t, 0);
}

void Game::draw() {
	glClear(GL_COLOR_BUFFER_BIT);
	player->draw();
	if(bullet != nullptr) {
		bullet->draw();
	}
	if (enemy == nullptr) {
		SpawnEnemy();
		enemy->draw();
	}
	glutSwapBuffers();
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
