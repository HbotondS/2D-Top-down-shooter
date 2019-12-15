#pragma once

#include <GL/freeglut.h>
#include "IDrawable.h"
#include "RgbImage.h"

class Sprite: IDrawable {
private:
	float x, y;
	float width, height;
	float origoX, origoY;
	float angle;
	GLuint textureName;
	char* filename;
	void loadTextureFromFile(char*);
	void initTexture(char*);

public:
	Sprite(float, float, float, float, char*);
	Sprite(float, float, char*);
	~Sprite();
	void draw();
	void setAngle(float);
	float getAngle();
};

