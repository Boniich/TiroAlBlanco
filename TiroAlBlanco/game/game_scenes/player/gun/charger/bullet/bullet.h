#pragma once
struct BulletTDA;
typedef struct BulletTDA* Bullet;

Bullet create();
void destroy(Bullet bullet);
int getX(Bullet bullet);
void setX(Bullet bullet, const int x);
int getY(Bullet bullet);
void setY(Bullet bullet, const int y);
Bullet getNextBullet(Bullet bullet);

void addNextBullet(Bullet* bullet, Bullet next_bullet);