#include "used_bullets_list.h"
#include "../bullet/bullet.h"
#include "../../../../target/target.h"
#include "../../../../../helpers/move_across_screen/move_across_screen.h"
#include "stdio.h"


void recollectUsedBullet(Bullet* list, Bullet bullet) {

	if ((*list) == nullptr) {
		(*list) = bullet;
	}
	else {
		Bullet last_node = (*list);
		while (getNextBullet(last_node) != nullptr) {
			last_node = getNextBullet(last_node);
		}
		addNextBullet(&last_node, bullet);
	}
}

void moveBullet(Bullet* bullet) {
	moveAcrossScreen(getX((*bullet)), getY((*bullet))); printf(" ");
	setY((*bullet), getY((*bullet))-1);
	moveAcrossScreen(getX((*bullet)), getY((*bullet))); printf("*");
}

bool isBulletOut(Bullet bullet) {
	if (getY(bullet) <= 4) return true;
	return false;
}

bool isTargetImpact(Bullet bullet, Target target) {

	if ((getX(bullet) >= getX(target) && getX(bullet) < getX(target) + 4) && getY(target) == getY(bullet)) {
		moveAcrossScreen(50, 25); printf("               ");
		moveAcrossScreen(50, 25); printf("hubo impacto");
		return true;
	}
	moveAcrossScreen(50, 25); printf("NO hubo impacto");
	return false;
}

void destroyBullet(Bullet* bullet) {
	moveAcrossScreen(getX((*bullet)), getY((*bullet))); printf(" ");
	Bullet temp = (*bullet);
	(*bullet) = getNextBullet((*bullet));
	destroy(temp);
}