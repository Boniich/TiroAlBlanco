#pragma once

struct BulletTDA;
typedef struct BulletTDA* Bullet;

void loadBullets(Bullet* stack, const int amount); // carga las balas a la pila
Bullet shootBullet(Bullet* stack, int x, int y); //saca la ultima pila en ser ingresada
bool isStackEmpty(Bullet stack); // comprueba si la pila esta vacia
void moveBullet(Bullet stack); // mueve la bala que sale de la pila
bool isBulletOut(Bullet stack); // comprueba si la bala paso al blanco
void destroyBullet(Bullet stack); // destruye la bala cuando termina su proposito
int getAmountBullet(Bullet stack); // devuelve la cantidad de balas disponibles
//bool isTargetImpact(Target target); // detecta si la bala toco al blanco
void recollectUsedBullet(Bullet* list, Bullet bullet);