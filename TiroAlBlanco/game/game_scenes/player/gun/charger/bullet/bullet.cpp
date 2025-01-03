#pragma once
#include "bullet.h"

struct BulletTDA {
	int x = 10;
	int y = 0;
	BulletTDA* next_bullet = nullptr;
};

Bullet create() {
	Bullet new_bullet = new BulletTDA;
	return new_bullet;
}

void destroy(Bullet bullet) {
	delete bullet;
}

int getX(Bullet bullet) {
	return bullet->x;
}

void setX(Bullet bullet, const int x) {
	bullet->x = x;
}

int getY(Bullet bullet) {
	return bullet->y;
}

void setY(Bullet bullet,const int y) {
	bullet->y = y;
}

Bullet getNextBullet(Bullet bullet) {
	return bullet->next_bullet;
}

void addNextBullet(Bullet* bullet, Bullet next_bullet) {
	(*bullet)->next_bullet = next_bullet;
}