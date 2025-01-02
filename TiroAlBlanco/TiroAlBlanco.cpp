#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "game/helpers/move_across_screen/move_across_screen.h"
#include "game/helpers/disable_mouse_input/disable_mouse_input.h"
#include "game/helpers/hide_cursor/hide_cursor.h"
#include "game/game_scenes/limits/limits.h"
#include "game/game_scenes/player/gun/gun.h"
#include "game/game_scenes/target/target.h"
#include "game/game_scenes/player/gun/bullet/bullet.h"

/*
 First version of game Tiro al blanco
 This version does not have a separation by layers
*/

int main()
{
    hideCursor();
    disableMouseInput();
 
    printLimits();

    Target target = create(50.0f, 5, 4, true, 10.0f, 3.0f,73.0f);
    Gun gun = create(50, 19,3,73);

    //Test
    Bullet stack = nullptr;
    Bullet used_bullets = nullptr;
    loadBullets(&stack,5);

    moveAcrossScreen(10, 2); printf("%d",getAmountBullet(stack));

    printfTarget(target);
    addAtInitialPosition(gun);


    while (true) {

       moveTarget(target);

        if (_kbhit()) {
            int key = _getch();
            moveAcrossScreen(10, 0); printf("%d", key);
            if (key == 0 || key == 224) {
                int second_key = _getch();

                switch (second_key)
                {

                case 75:
                   // moveAcrossScreen(10, 2); printf("Entro");
                    //se mueve para la izquierda usando la flecha izquierda
                    moveToLeft(gun);
                    break;
                case 77:
                    //moveAcrossScreen(10, 2); printf("Entro");
                    //se mueve para la derecha usando la flecha derecha

                    moveToRight(gun);
                    break;
                default:
                    break;
                }
            }
            
            
            if (key == 102) {
                //moveAcrossScreen(10, 0); printf("%d",key);
                if (!isStackEmpty(stack)) {
                    Bullet b = shootBullet(&stack, getX(gun) + 1, getY(gun) - 3);

                    moveAcrossScreen(10, 2); printf("%d", getAmountBullet(stack));
                    if (getAmountBullet(stack) == 0) {
                        moveAcrossScreen(10, 2); printf("No hay mas balas");
                    }

                    recollectUsedBullet(&used_bullets, b);
                }
            }
        }

        if (used_bullets != nullptr) {

            if (isBulletOut(used_bullets)) {
                moveBullet(&used_bullets);

                isTargetImpact(used_bullets, target);
            }
            else {
                destroyBullet(&used_bullets);
            }
            
        }


    }
 
    Sleep(1000);

    return 0;
}