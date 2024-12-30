#include "bullet.h"
#include "../../../../helpers/move_across_screen/move_across_screen.h"
#include <stdio.h>


struct BulletTDA {
	int x = 10;
	int y = 0;
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
Bullet shootBullet(Bullet* stack, int x, int y)
{
	Bullet bullet = (*stack);

	(*stack) = (*stack)->next_bullet;

	bullet->next_bullet = NULL;
	bullet->x = x;
	bullet->y = y;

	return bullet;
}



bool isStackEmpty(Bullet stack); // comprueba si la pila esta vacia
void moveBullet(Bullet bullet) {

	
	if (bullet != nullptr) {
		moveAcrossScreen(bullet->x, bullet->y); printf("*");

		
	}
	
	

	//if (bullet != nullptr) {
	//	Bullet* b = (Bullet*)bullet;

	//	while (bullet->next_bullet != nullptr) {

			//moveAcrossScreen((*b)->x, (*b)->y); printf(" ");
			//(*b)->y--;
			//moveAcrossScreen((*b)->x, (*b)->y); printf("*");

			//bullet->next_bullet = bullet;
		//}
	//}

	


}
bool isBulletOut(Bullet stack); // comprueba si la bala paso al blanco
void destroyBullet(Bullet stack); // destruye la bala cuando termina su proposito
int getAmountBullet(Bullet stack); // devuelve la cantidad de balas disponibles
//bool isTargetImpact(Target target); /

void recollectUsedBullet(Bullet* list, Bullet bullet) {
	
	if ((*list) == nullptr) {
		(*list) = bullet;
	}
	else {
		Bullet last_node = (*list);
		while (last_node->next_bullet != nullptr) {
			last_node = last_node->next_bullet;
		}

		last_node->next_bullet = bullet;
	}



}