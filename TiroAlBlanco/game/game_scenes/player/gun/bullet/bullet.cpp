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



bool isStackEmpty(Bullet stack) {

	if (stack == nullptr) {
		return true;
	}
	return false;

}
void moveBullet(Bullet* bullet) {
	moveAcrossScreen(50, 20); printf("%d", (*bullet)->y);
	moveAcrossScreen((*bullet)->x, (*bullet)->y); printf(" ");
	(*bullet)->y--;
	moveAcrossScreen((*bullet)->x, (*bullet)->y); printf("*");		
}
bool isBulletOut(Bullet bullet) {
	if (bullet->y > 4) return true;
	return false;
}
void destroyBullet(Bullet* bullet) {
	moveAcrossScreen((*bullet)->x, (*bullet)->y); printf(" ");
	Bullet temp = (*bullet);
	(*bullet) = (*bullet)->next_bullet;

	delete temp;
}
int getAmountBullet(Bullet stack) {
	int counter = 0;

	while (stack != nullptr) {
		counter++;
		stack = stack->next_bullet;
	}
	return counter;
}

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

bool isTargetImpact(Bullet bullet, Target target) {

	if ((bullet->x >= getX(target) && bullet->x < getX(target)+4) && getY(target) == bullet->y) {
		moveAcrossScreen(50, 25); printf("               ");
		moveAcrossScreen(50, 25); printf("hubo impacto");
		return true;
	}
	moveAcrossScreen(50, 25); printf("NO hubo impacto");
	return false;
}