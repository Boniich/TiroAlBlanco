#include <limits.h>
#include <iostream>
#include "../../helpers/move_across_screen/move_across_screen.h"


struct LineLimit {
	int start_line;
	int line_length;
	int y_coord_to_top_line;
	int y_coord_to_bottom_line;
};

struct Limits {
	LineLimit horizontal_line;
	LineLimit vertical_line;
};


const LineLimit horizontal_line = { 2, 78, 3, 20 };
const LineLimit vertical_line = { 4,20,2,77 };

const Limits game_limits = { horizontal_line,vertical_line };

void printLimits() {
	for (int i = game_limits.horizontal_line.start_line; i < game_limits.horizontal_line.line_length; i++) {
		moveAcrossScreen(i, game_limits.horizontal_line.y_coord_to_top_line); printf("%c", 205);
		moveAcrossScreen(i, game_limits.horizontal_line.y_coord_to_bottom_line); printf("%c", 205);
	}

	for (int i = game_limits.vertical_line.start_line; i < game_limits.vertical_line.line_length; i++) {
		moveAcrossScreen(game_limits.vertical_line.y_coord_to_top_line,i); printf("%c", 186);
		moveAcrossScreen(game_limits.vertical_line.y_coord_to_bottom_line,i); printf("%c", 186);
	}

	moveAcrossScreen(game_limits.horizontal_line.start_line, game_limits.horizontal_line.y_coord_to_top_line);
	printf("%c", 201);

	moveAcrossScreen(game_limits.horizontal_line.start_line, game_limits.horizontal_line.y_coord_to_bottom_line);
	printf("%c", 200);

	moveAcrossScreen(game_limits.vertical_line.y_coord_to_bottom_line, game_limits.horizontal_line.y_coord_to_top_line);
	printf("%c", 187);

	moveAcrossScreen(game_limits.vertical_line.y_coord_to_bottom_line, game_limits.horizontal_line.y_coord_to_bottom_line);
	printf("%c", 188);

}