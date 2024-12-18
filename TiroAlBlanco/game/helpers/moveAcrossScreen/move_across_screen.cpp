#include "move_across_screen.h"
#include <Windows.h>

void moveAcrossScreen(const int x, const int y) {

	HANDLE handle;
	COORD coords;

	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	coords.X = x;
	coords.Y = y;

	SetConsoleCursorPosition(handle, coords);
}