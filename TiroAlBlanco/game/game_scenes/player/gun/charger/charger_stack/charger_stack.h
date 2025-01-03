#pragma once
#include "../bullet/bullet.h"


void loadBullets(Bullet* stack,const int amount);
Bullet shootBullet(Bullet* stack, int x, int y);
bool isStackEmpty(Bullet stack); 
int getAmountBullet(Bullet stack); 