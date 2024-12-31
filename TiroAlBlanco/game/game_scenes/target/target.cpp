#include "target.h"
#include "../../helpers/move_across_screen/move_across_screen.h"
#include <stdio.h>
#include <chrono>
#include <thread>

struct TargetTDA {
	float x;
	int y_top;
	int y_bottom;
	bool is_move_to_right;
	float movement_speed;
	float left_limit;
	float right_limit;
};

std::chrono::steady_clock::time_point last_time;

Target create(const float x, const int y_top, const int y_bottom, 
	const bool is_move_to_right, const float movement_speed,
	const float left_limit, const float right_limit) {
	TargetTDA* target = new TargetTDA;
	target->x = x;
	target->y_top = y_top;
	target->y_bottom = y_bottom;
	target->is_move_to_right = is_move_to_right;
	target->movement_speed = movement_speed;
	target->left_limit = left_limit;
	target->right_limit = right_limit;

	last_time = std::chrono::high_resolution_clock::now();

	return target;

}

void printfTarget(const Target target) {
	moveAcrossScreen(static_cast<int>(target->x), target->y_top); printf("%c%c%c%c", 192, 196, 196, 217);
	moveAcrossScreen(static_cast<int>(target->x),target->y_bottom); printf("%c%c%c%c", 218, 196, 196, 191);
}

void moveTarget(const Target target) {

	cleanFromScreen(target);
	std::chrono::steady_clock::time_point actual_time = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> delta_time = actual_time - last_time;

	if (target->is_move_to_right) {
		target->x += target->movement_speed * delta_time.count();
		if (target->x >= target->right_limit) {
			target->x = target->right_limit;
			target->is_move_to_right = false;
		}
	}
	else {
		target->x -= target->movement_speed * delta_time.count();
		if (target->x <= target->left_limit) {
			target->x = target->left_limit;
			target->is_move_to_right = true;
		}
	}
	last_time = actual_time;

	printfTarget(target);
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
}

void cleanFromScreen(const Target target) {
	moveAcrossScreen(static_cast<int>(target->x), target->y_top); printf("    ");
	moveAcrossScreen(static_cast<int>(target->x), target->y_bottom); printf("    ");
}

int getX(const Target target) {
	return static_cast<int>(target->x);
}
int getY(const Target target) {
	return static_cast<int>(target->y_bottom);
}