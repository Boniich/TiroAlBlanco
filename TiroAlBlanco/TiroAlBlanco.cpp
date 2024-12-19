#include <iostream>
#include "game/helpers/move_across_screen/move_across_screen.h"
#include "game/helpers/hide_cursor/hide_cursor.h"
#include "game/game_scenes/limits/limits.h"

/*
 First version of game Tiro al blanco
 This version does not have a separation by layers
*/

int main()
{
    hideCursor();

 
    printLimits();
    //moveAcrossScreen(50, 50);
    //printf("*");
 
 
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
}