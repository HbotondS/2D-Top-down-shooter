#include "Bullet.h"
#include "GameObject.h"
#include <iostream>
#include <math.h>


Bullet::Bullet(float width, float height, int moveSpeed):GameObject(width, height, moveSpeed) {
	
	x = GameObject::getPositionX();
	y = GameObject::getPositionY();
	origoX = width / 2;
	origoY = height / 2;
	angle = 0;
	moveSpeed = 1;
	
}




void Bullet::moveBullet() {

	//bullets.push_back(Bullet(x, y, moveSpeed));
	for (auto it = bullets.begin(); it != bullets.end(); ++it) 
	{  

		if (x > glutGet(GLUT_WINDOW_WIDTH) || x < 0 || y > glutGet(GLUT_WINDOW_HEIGHT) || y < 0)
		{
			bullets.erase(it--);
		}
		else
		{
			glPushMatrix();
			glTranslatef(x, y, 0);
			glRotatef(angle, 0, 0, 1);
			draw();
		    x = x + moveSpeed * cos(angle);
		    y = y + moveSpeed * sin(angle);
			glPopMatrix();
			
			++it;
		}

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

