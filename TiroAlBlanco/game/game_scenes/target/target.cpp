#include "target.h"
#include "../../helpers/move_across_screen/move_across_screen.h"
#include <stdio.h>

struct TargetTDA {
	int x;
	int y_top;
	int y_bottom;
	bool move_to_left;
	bool move_to_right;
	
};

Target create(const int x, const int y_top, const int y_bottom, const bool left, const bool right) {
	TargetTDA* target = new TargetTDA;
	target->x = x;
	target->y_top = y_top;
	target->y_bottom = y_bottom;
	target->move_to_left = left;
	target->move_to_right = right;

	return target;

}
void addAtInitialPosition(const Target target) {
	moveAcrossScreen(target->x, target->y_top); printf("%c%c%c%c", 192, 196, 196, 217);
	moveAcrossScreen(target->x,target->y_bottom); printf("%c%c%c%c", 218, 196, 196, 191);
}

void moveTarget(const Target target) {

	if (target->x > 2 && target->x < 74) {
		moveToRight(target);
		moveToLeft(target);
	}
}

void moveToLeft(const Target target) {
	if (target->x < 74 && target->move_to_left) {
		cleanFromScreen(target);
		target->x--;
		moveAcrossScreen(target->x, target->y_top); printf("%c%c%c%c", 192, 196, 196, 217);
		moveAcrossScreen(target->x, target->y_bottom); printf("%c%c%c%c", 218, 196, 196, 191);

		if (target->x == 3) {
			target->move_to_right = true;
			target->move_to_left = false;
		}
	}
}
void moveToRight(const Target target) {
	if (target->x > 2 && target->move_to_right) {
		cleanFromScreen(target);
		target->x++;
		moveAcrossScreen(target->x, target->y_top); printf("%c%c%c%c", 192, 196, 196, 217);
		moveAcrossScreen(target->x, target->y_bottom); printf("%c%c%c%c", 218, 196, 196, 191);

		if (target->x == 73) {
			target->move_to_right = false;
			target->move_to_left = true;
		}

	}
}
void cleanFromScreen(const Target target) {
	moveAcrossScreen(target->x, target->y_top); printf("    ");
	moveAcrossScreen(target->x, target->y_bottom); printf("    ");
}