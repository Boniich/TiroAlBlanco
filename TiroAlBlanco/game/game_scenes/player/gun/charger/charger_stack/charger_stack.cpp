#include "charger_stack.h"
#include "../bullet/bullet.h"

void loadBullets(Bullet* stack, const int amount)
{
	int contadora = 20;
	for (int i = 0; i < amount; i++) {
		Bullet new_bullet = create();

		if (!new_bullet) return;

		addNextBullet(&new_bullet, (*stack));

		(*stack) = new_bullet;		
	}	
}

Bullet shootBullet(Bullet* stack, int x, int y)
{
	Bullet bullet = (*stack);

	(*stack) = getNextBullet((*stack));
	addNextBullet(&bullet, nullptr);
	setX(bullet, x);
	setY(bullet, y);

	return bullet;
}

bool isStackEmpty(Bullet stack) {

	if (stack == nullptr) {
		return true;
	}
	return false;

}

int getAmountBullet(Bullet stack) {
	return 0;
}