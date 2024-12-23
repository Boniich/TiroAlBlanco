#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "game/helpers/move_across_screen/move_across_screen.h"
#include "game/helpers/hide_cursor/hide_cursor.h"
#include "game/game_scenes/limits/limits.h"
#include "game/game_scenes/player/gun/gun.h"
#include "game/game_scenes/target/target.h"

/*
 First version of game Tiro al blanco
 This version does not have a separation by layers
*/

int main()
{
    hideCursor();

 
    printLimits();

    Target target = create(50.0f, 5, 4, true, 10.0f, 3.0f,73.0f);
    Gun gun = create(50, 19,3,73);

    printfTarget(target);
    addAtInitialPosition(gun);


    while (true) {

        moveTarget(target);

        if (_kbhit()) {
            int key = _getch();
            if (key == 0 || key == 224) {
                int second_key = _getch();

                switch (second_key)
                {

                case 75:
                    //se mueve para la izquierda usando la flecha izquierda
                    moveToLeft(gun);
                    break;
                case 77:
                    //se mueve para la derecha usando la flecha derecha

                    moveToRight(gun);
                    break;
                default:
                    break;
                }
            }
        }
    }
 
    Sleep(1000);
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "" << std::endl;

    return 0;
}