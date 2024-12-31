#pragma once

struct TargetTDA;
typedef struct TargetTDA* Target;

Target create(const float x, const int y_top, const int y_bottom,
	const bool is_move_to_right, const float movement_speed,
	const float left_limit, const float right_limit);

void printfTarget(const Target target);
void moveTarget(const Target target);
void cleanFromScreen(const Target target);
int getX(const Target target);
int getY(const Target target);