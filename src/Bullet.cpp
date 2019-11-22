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




Bullet::Bullet(float width, float height, int moveSpeed) :GameObject(width,height,moveSpeed) {
	x = 10;
	y = 10;
	origoX = width / 2;
	origoY = height / 2;
	angle = 0;
	

}

void Bullet::moveBullet() {
	int i = 0;
	
	for (i = 0; i < max_bullet; i++) {

				x = getPositionX();
				y = getPositionY();
				angle = getAngle();
				origoX = -max_velocity * sin(angle);
				origoY = max_velocity * cos(angle);
				break;
				glutPostRedisplay();
	}

	 // eliminating those bullets which have gone past the window 
	for (i = 0; i < max_bullet; i++) {
		
			x = x + origoX;
			y = y + origoY;
			glutPostRedisplay();
		
		if (x > width || x < 0 || y < height || y < 0)
		{
			x = 0;
			y = 0;
			glutPostRedisplay();
	    }
	}

}


void Bullet::draw() {
	
			std::cout << "draw";
			glLineWidth(0.5);
			glClear(GL_COLOR_BUFFER_BIT);
			myTranslate2D(x, y);
			myRotate2D(angle);
			myScale2D(1.0f, 1.0f);
			glBegin(GL_TRIANGLES);
			glVertex2f(x, y);
			glVertex2f(x + width, y);
			glVertex2f(x + width, y + height);
			glVertex2f(x, y + height);
			glEnd();
			glPopMatrix();
			
	}

