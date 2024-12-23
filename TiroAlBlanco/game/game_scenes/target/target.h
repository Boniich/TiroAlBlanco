#pragma once

struct TargetTDA;
typedef struct TargetTDA* Target;

Target create(const float x, const int y_top, const int y_bottom, const bool left, const bool right);
void addAtInitialPosition(const Target target);
void moveTarget(const Target target);
void moveToLeft(const Target target);
void moveToRight(const Target target);
void cleanFromScreen(const Target target);