#pragma once
#include "../bullet/bullet.h"
#include "../../../../target/target.h"

void recollectUsedBullet(Bullet* list, Bullet bullet);
void moveBullet(Bullet* stack);
bool isBulletOut(Bullet bullet);
bool isTargetImpact(Bullet bullet, Target target);
void destroyBullet(Bullet* stack);