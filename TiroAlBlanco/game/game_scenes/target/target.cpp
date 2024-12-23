#include "target.h"
#include "../../helpers/move_across_screen/move_across_screen.h"
#include <stdio.h>
#include <chrono>
#include <thread>

struct TargetTDA {
	float x;
	int y_top;
	int y_bottom;
	bool move_to_left;
	bool move_to_right;
	//
	bool is_move_to_right;
	float movement_speed;
};

std::chrono::steady_clock::time_point last_time;

Target create(const float x, const int y_top, const int y_bottom, const bool left, const bool right) {
	TargetTDA* target = new TargetTDA;
	target->x = x;
	target->y_top = y_top;
	target->y_bottom = y_bottom;
	target->move_to_left = left;
	target->move_to_right = right;

	last_time = std::chrono::high_resolution_clock::now();

	return target;

}
void addAtInitialPosition(const Target target) {
	moveAcrossScreen(static_cast<int>(target->x), target->y_top); printf("%c%c%c%c", 192, 196, 196, 217);
	moveAcrossScreen(static_cast<int>(target->x),target->y_bottom); printf("%c%c%c%c", 218, 196, 196, 191);
}

void moveTarget(const Target target) {

	cleanFromScreen(target);
	std::chrono::steady_clock::time_point actual_time = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> delta_time = actual_time - last_time;

	if (target->move_to_right) {
		target->x += 15.0f * delta_time.count();
		if (target->x >= 73.0f) {
			target->x = 73.0f;
			target->move_to_right = false;
			target->move_to_left = true;
		}
	}

	if (target->move_to_left) {
		target->x -= 15.0f * delta_time.count();
		if (target->x <= 3.0f) {
			target->x = 3.0f;
			target->move_to_right = true;
			target->move_to_left = false;
		}
	}
	last_time = actual_time;

	moveAcrossScreen(static_cast<int>(target->x), target->y_top); printf("%c%c%c%c", 192, 196, 196, 217);
	moveAcrossScreen(static_cast<int>(target->x), target->y_bottom); printf("%c%c%c%c", 218, 196, 196, 191);


	std::this_thread::sleep_for(std::chrono::milliseconds(10));
}

void moveToLeft(const Target target) {
	if (static_cast<int>(target->x) < 74 && target->move_to_left) {
		cleanFromScreen(target);
		std::chrono::steady_clock::time_point actual_time = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> delta_time = actual_time - last_time;


		target->x -= 10.0f * delta_time.count();

		moveAcrossScreen(static_cast<int>(target->x), 25); printf("%f", target->x);
		//target->x--;
		moveAcrossScreen(static_cast<int>(target->x), target->y_top); printf("%c%c%c%c", 192, 196, 196, 217);
		moveAcrossScreen(static_cast<int>(target->x), target->y_bottom); printf("%c%c%c%c", 218, 196, 196, 191);

		if (static_cast<int>(target->x) == 3) {
			target->move_to_right = true;
			target->move_to_left = false;
		}
	}
}
void moveToRight(const Target target) {
	if (static_cast<int>(target->x) > 2 && target->move_to_right) {
		cleanFromScreen(target);
		std::chrono::steady_clock::time_point actual_time = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> delta_time = actual_time - last_time;
		
		
		target->x  +=  10.0f * delta_time.count();
		last_time = actual_time;
		int t = static_cast<int>(target->x);
		moveAcrossScreen(static_cast<int>(target->x), 25); printf("%f", target->x);
		//target->x++;
		moveAcrossScreen(static_cast<int>(target->x), target->y_top); printf("%c%c%c%c", 192, 196, 196, 217);
		moveAcrossScreen(static_cast<int>(target->x), target->y_bottom); printf("%c%c%c%c", 218, 196, 196, 191);

		if (static_cast<int>(target->x) == 73) {
			target->x = 73.0f;
			moveAcrossScreen(static_cast<int>(target->x), 30); printf("Entra");
			target->move_to_right = false;
			target->move_to_left = true;
		}

	}
}
void cleanFromScreen(const Target target) {
	moveAcrossScreen(static_cast<int>(target->x), target->y_top); printf("    ");
	moveAcrossScreen(static_cast<int>(target->x), target->y_bottom); printf("    ");
}