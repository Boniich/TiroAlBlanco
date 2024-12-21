#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "game/helpers/move_across_screen/move_across_screen.h"
#include "game/helpers/hide_cursor/hide_cursor.h"
#include "game/game_scenes/limits/limits.h"
#include "game/game_scenes/player/gun/gun.h"

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

    // add the target to the game
    moveAcrossScreen(50, 5); printf("%c%c%c%c",192,196,196,217);
    moveAcrossScreen(50, 4); printf("%c%c%c%c", 218, 196,196, 191);

    Gun gun = create(50, 19,3,73);

    addAtInitialPosition(gun);

    int x = 50;
    bool move_to_right = true;
    bool move_to_left = false;

    while (true) {

        if (x > 2 && x < 74) {

            if (x > 2 && move_to_right) {
                moveAcrossScreen(x, 5); printf("    ");
                moveAcrossScreen(x, 4); printf("    ");
                x = x + 1;

                moveAcrossScreen(x, 5); printf("%c%c%c%c", 192, 196, 196, 217);
                moveAcrossScreen(x, 4); printf("%c%c%c%c", 218, 196, 196, 191);


                if (x == 73) {
                    move_to_right = false;
                    move_to_left = true;
                }
            }
       
            if (x < 74 && move_to_left) {
                moveAcrossScreen(x, 5); printf("    ");
                moveAcrossScreen(x, 4); printf("    ");
                x = x - 1;
                moveAcrossScreen(x, 5); printf("%c%c%c%c", 192, 196, 196, 217);
                moveAcrossScreen(x, 4); printf("%c%c%c%c", 218, 196, 196, 191);

                if (x == 3) {
                    move_to_right = true;
                    move_to_left = false;
                }
            }
            Sleep(35);
        }


       

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