#include "Bullet.h"
#include "GameObject.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define RAD2DEG 180.0/M_PI
#define DEG2RAD M_PI/180.0
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#define max_bullet 10
#define max_velocity 5
#define myTranslate2D(x,y) glTranslated(x, y, 0.0)
#define myScale2D(x,y) glScalef(x, y, 1.0)
#define myRotate2D(angle) glRotatef(RAD2DEG*angle, 0.0, 0.0, 1.0)


Bullet::Bullet(float width, float height, int moveSpeed):GameObject(width, height, moveSpeed) {
	x = 10;
	y = 10;
	origoX = width / 2;
	origoY = height / 2;
	angle = 0;
}

void Bullet::moveBullet() {
	for(int i = 0; i < max_bullet; i++) {
		glPushMatrix();
		glTranslatef(x, y, 0);
		glRotatef(angle, 0, 0, 1);
		x += moveSpeed * cos(angle);
		y += moveSpeed * sin(angle);
		glPopMatrix();
		draw();
	}
}


void Bullet::draw() {
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(x, y, 0);
	glRotatef(angle, 0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex2f(-origoX, -origoY);
	glVertex2f(-origoX + width, -origoY);
	glVertex2f(-origoX + width, -origoY + height);
	glVertex2f(-origoX, -origoY + height);
	glEnd();
	glPopMatrix();
}

