#include "Game.h"

Game::Game() {
	filename = _strdup("res/player2_2.bmp");
	player = new Player(100, 100, 5, filename);
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

	glutPostRedisplay();
	glutTimerFunc(1, t, 0);
}

void Game::draw() {
	glClear(GL_COLOR_BUFFER_BIT);
	player->draw();
	if(bullet != nullptr) {
		bullet->draw();
	}
	glutSwapBuffers();
}
