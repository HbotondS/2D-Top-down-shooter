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

Sprite::Sprite(float x, float y, float width, float height, char* filename) {
	angle = 0;
	this->filename = filename;
}

Sprite::~Sprite() {}

void Sprite::initTexture(char* filename) {
	glGenTextures(1, &textureName);
	glBindTexture(GL_TEXTURE_2D, textureName);
	loadTextureFromFile(filename);
}

void Sprite::draw() {
	initTexture(filename);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	glPushMatrix();
	glTranslatef(20, 20, 0.0f);
	glRotatef(angle, 0, 0, 1);


	glBindTexture(GL_TEXTURE_2D, textureName);

	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0); glVertex3f(0.0, 0.0, 0.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.0, 100.0, 0.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(100.0, 100.0, 0.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(100.0, 0.0, 0.0);
	glEnd();


	glPopMatrix();
	glFlush();
	glDisable(GL_TEXTURE_2D);
}

void Sprite::setAngle(float angle) {
	this->angle = angle;
}

float Sprite::getAngle() {
	return angle;
}
