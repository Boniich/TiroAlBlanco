#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "game/helpers/move_across_screen/move_across_screen.h"
#include "game/helpers/disable_mouse_input/disable_mouse_input.h"
#include "game/helpers/hide_cursor/hide_cursor.h"
#include "game/game_scenes/limits/limits.h"
#include "game/game_scenes/player/gun/gun.h"
#include "game/game_scenes/target/target.h"
#include "game/game_scenes/player/gun/charger/charger_stack/charger_stack.h"
#include "game/game_scenes/player/gun/charger/used_bullets_list/used_bullets_list.h"
#include "game/systems/goal_system/goal_system.h"

/*
 First version of game Tiro al blanco
 This version does not have a separation by layers
*/

int main()
{
    disableMouseInput();
    hideCursor();
    
 
    printLimits();

    Target target = create(50.0f, 5, 4, true, 10.0f, 3.0f,73.0f);
    Gun gun = create(50, 19,3,73);
    Goal goal = create(30, 10);

    //Test
    Bullet stack = nullptr;
    Bullet used_bullets = nullptr;
    loadBullets(&stack,5);

    moveAcrossScreen(10, 2); printf("%d",getAmountBullet(stack));
    moveAcrossScreen(70, 2); printf("%d/%d", getAccumulatedPoints(goal), getGoal(goal));

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
                    moveToLeft(gun);
                    break;
                case 77:
                    moveToRight(gun);
                    break;
                default:
                    break;
                }
            }
            
            
            if (key == 102) {
                if (!isStackEmpty(stack)) {
                    Bullet b = shootBullet(&stack, getX(gun) + 1, getY(gun) - 3);
                    recollectUsedBullet(&used_bullets, b);

                    if (getAmountBullet(stack) == 0) {
                        moveAcrossScreen(10, 2); printf("No hay mas balas");
                    }
                    else {
                        moveAcrossScreen(10, 2); printf("%d", getAmountBullet(stack));         
                    }
                }
            }
        }

        if (used_bullets != nullptr) {

            if (isBulletOut(used_bullets)) {
                destroyBullet(&used_bullets);
            }
            else {
                moveBullet(&used_bullets);
                if (isTargetImpact(used_bullets, target)) {
                    incressPoints(goal);
                    moveAcrossScreen(70, 2); printf("%d/%d", getAccumulatedPoints(goal), getGoal(goal));
                }

            }
            
        }

        if (archivedGoal(goal)) {
            moveAcrossScreen(20, 30); printf("Nivel terminado");
        }
    }
 
    Sleep(1000);

    return 0;
}