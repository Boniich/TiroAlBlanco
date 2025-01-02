#include "disable_mouse_input.h"
#include <Windows.h>

void disableMouseInput() {
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(hInput, &mode);
	mode &= ~ENABLE_MOUSE_INPUT;
	SetConsoleMode(hInput, mode);
}