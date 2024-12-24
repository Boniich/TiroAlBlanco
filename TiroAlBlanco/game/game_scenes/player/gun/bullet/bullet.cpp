#include "bullet.h"
#include <stdio.h>


struct BulletTDA {
	float x = 10;
	float y = 0;
	BulletTDA* next_bullet = nullptr;
};


void loadBullets(Bullet* stack,const int amount)
{
	for (int i = 0; i < amount; i++) {
		Bullet new_bullet = new BulletTDA;

		if (!new_bullet) return;

		new_bullet->next_bullet = (*stack);
		(*stack) = new_bullet;
	}
}

//Como logro darle las posiciones del arma
//a la bala?
Bullet shootBullet(Bullet* stack);
bool isStackEmpty(Bullet stack); // comprueba si la pila esta vacia
void moveBullet(Bullet stack); // mueve la bala que sale de la pila
bool isBulletOut(Bullet stack); // comprueba si la bala paso al blanco
void destroyBullet(Bullet stack); // destruye la bala cuando termina su proposito
int getAmountBullet(Bullet stack); // devuelve la cantidad de balas disponibles
//bool isTargetImpact(Target target); /