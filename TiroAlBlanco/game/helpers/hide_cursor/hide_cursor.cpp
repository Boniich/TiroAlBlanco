#include "hide_cursor.h"
#include <Windows.h>

void hideCursor() {
	HANDLE handle;
	CONSOLE_CURSOR_INFO cursor_info;

	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	cursor_info.dwSize = 50;
	cursor_info.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &cursor_info);
}
