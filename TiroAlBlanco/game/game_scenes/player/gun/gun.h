#pragma once

struct GunTDA;
typedef struct GunTDA* Gun;

Gun create(int x, int y);
void addAtInitialPosition(const Gun gun);
void moveToLeft(const Gun gun);
void moveToRight(const Gun gun);
void cleanGunFromScreen(const Gun gun);