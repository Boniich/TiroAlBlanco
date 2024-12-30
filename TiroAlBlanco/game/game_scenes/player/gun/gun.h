#pragma once

struct GunTDA;
typedef struct GunTDA* Gun;

Gun create(const int x, const int y, const int left_limit, const int righ_limit);
void addAtInitialPosition(const Gun gun);
void moveToLeft(const Gun gun);
void moveToRight(const Gun gun);
void cleanGunFromScreen(const Gun gun);
int getX(const Gun gun);
int getY(const Gun gun);