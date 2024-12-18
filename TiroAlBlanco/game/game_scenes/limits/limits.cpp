#include <limits.h>
#include <iostream>
#include "../../helpers/move_across_screen/move_across_screen.h"


struct Limits {
	int start_line;
	int vertical_line_length;
	int y_coord_to_top_vertical_line;
	int y_coord_to_bottom_vertical_line;
	//int horizontal_line_length;
	//int y_coord_to_bottom_horizontal_line;
};

const Limits game_limits = { 2,78,3,33 };

void printLimits() {
	for (int i = game_limits.start_line; i < game_limits.vertical_line_length; i++) {
		moveAcrossScreen(i, game_limits.y_coord_to_top_vertical_line); printf("%c", 205);
		moveAcrossScreen(i, game_limits.y_coord_to_bottom_vertical_line); printf("%c", 205);
	}
}