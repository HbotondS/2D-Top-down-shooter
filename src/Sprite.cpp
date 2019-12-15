#include "Sprite.h"
#include <iostream>

void Sprite::loadTextureFromFile(char* filename) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);

	RgbImage theTexMap(filename);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, theTexMap.GetNumCols(), theTexMap.GetNumRows(),
		GL_RGB, GL_UNSIGNED_BYTE, theTexMap.ImageData());
}

void Sprite::drawTextureQuad() {}

Sprite::Sprite(float x, float y, float width, float height, char* filename)
		: x(x), y(y), width(width), height(height), filename(filename) {
	angle = 0;
	origoX = width / 2;
	origoY = height / 2;
}

Sprite::Sprite(float width, float height, char* filename)
		: width(width), height(height), filename(filename) {
	angle = 0;
	origoX = width / 2;
	origoY = height / 2;
}

Sprite::~Sprite() {}

void Sprite::initTexture(char* filename) {
	glGenTextures(1, &textureName);
	glBindTexture(GL_TEXTURE_2D, textureName);
	loadTextureFromFile(filename);
}

void Sprite::draw() {
	initTexture(filename);

	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	glPushMatrix();

	glBindTexture(GL_TEXTURE_2D, textureName);

	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex2f(-origoX, -origoY);
	glTexCoord2f(0.0, 1.0); glVertex2f(-origoX + width, -origoY);
	glTexCoord2f(1.0, 1.0); glVertex2f(-origoX + width, -origoY + height);
	glTexCoord2f(1.0, 0.0); glVertex2f(-origoX, -origoY + height);
	glEnd();


	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

void Sprite::setAngle(float angle) {
	this->angle = angle;
}

float Sprite::getAngle() {
	return angle;
}
