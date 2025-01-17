#include "play_game.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <thread>
#include <atomic>
#include "../../helpers/move_across_screen/move_across_screen.h"
#include "../../helpers/disable_mouse_input/disable_mouse_input.h"
#include "../../helpers/hide_cursor/hide_cursor.h"
#include "../../game_scenes/limits/limits.h"
#include "../../game_scenes/target/target.h"
#include "../../game_scenes/player/gun/gun.h"
#include "../../game_scenes/player/gun/charger/charger_stack/charger_stack.h"
#include "../../game_scenes/player/gun/charger/used_bullets_list/used_bullets_list.h"
#include "../../systems/goal_system/goal_system.h"
#include "../../systems/timer_system/timer_system.h"

void playGame() {


	disableMouseInput();
	hideCursor();


	printLimits();
	std::atomic<bool> temporizadorTerminado(false);
	std::atomic<bool> is_reload_finish(false);
	bool recarga_activada = false;

	Target target = create(50.0f, 5, 4, true, 10.0f, 3.0f, 73.0f);
	Gun gun = create(50, 19, 3, 73);
	Goal goal = create(30, 10);
	Timer game_timer = createTimer(30);
	Timer reload_gun = createTimer(5);

	//Test
	Bullet stack = nullptr;
	Bullet used_bullets = nullptr;
	loadBullets(&stack, 5);

	moveAcrossScreen(10, 2); printf("Disparos: %d", getAmountBullet(stack));
	moveAcrossScreen(70, 2); printf("%d/%d", getAccumulatedPoints(goal), getGoal(goal));
	moveAcrossScreen(35, 2); printf("Time: %.2d:%.2d ", getMinutes(game_timer), getSeconds(game_timer));

	printfTarget(target);
	addAtInitialPosition(gun);

	Sleep(3000);

	std::thread temporizadorHilo(runTimer, game_timer, std::ref(temporizadorTerminado));

	while (!temporizadorTerminado) {

		moveAcrossScreen(35, 2); printf("Time: %.2d:%.2d ", getMinutes(game_timer), getSeconds(game_timer));

		moveTarget(target);

		if (_kbhit()) {
			int key = _getch();
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
				}
			}
		}



		if (getAmountBullet(stack) == 0) {
			moveAcrossScreen(10, 2); printf("Recargando... (%d s)", getSeconds(reload_gun));
			if (!recarga_activada) {
				std::thread reload_gun_thread(runTimer, reload_gun, std::ref(is_reload_finish));
				recarga_activada = true;
				reload_gun_thread.detach();
			}

			if (is_reload_finish) {
				moveAcrossScreen(10, 2); printf("                   ");
				loadBullets(&stack, 5);
				resetTimer(reload_gun, 5);
				recarga_activada = false;
				is_reload_finish = false;
			}

		}
		else {
			moveAcrossScreen(10, 2); printf("Disparos: %d", getAmountBullet(stack));
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
			moveAcrossScreen(20, 25); printf("Nivel terminado");
		}
	}

	// Esperar a que el hilo termine antes de salir
	if (temporizadorHilo.joinable()) {
		temporizadorHilo.join();
	}

}