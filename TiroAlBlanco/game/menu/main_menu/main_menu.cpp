#include "main_menu.h"
#include <Windows.h>
#include <iostream>
#include "../../helpers/move_across_screen/move_across_screen.h"
#include "../../game_scenes/limits/limits.h"
#include "../../core_game/play_game/play_game.h"
#include "../../helpers/error_msg/error_msg.h"
#include "../../menu/win_loss_sub_menu/win_loss_sub_menu.h"
#include "../../helpers/ask_name/ask_name.h"

void startMenu() {
    bool endGame = false;
    int opcion;
    bool play_again = false;


    printLimits();

    moveAcrossScreen(35, 5); printf("TIRO AL BLANCO");

    moveAcrossScreen(10, 8); printf("--- Menu --- ");
    moveAcrossScreen(10, 9); printf("1- Jugar ");
    moveAcrossScreen(10, 10); printf("2- Historial ");
    moveAcrossScreen(10, 11); printf("3- Salir");
    

    do
    {
        moveAcrossScreen(10, 12); printf("Selecciona una opcion: ");
        if (std::cin >> opcion) {
            switch (opcion)
            {
            case 1:
                askName();
                showWinLossScreenWithSubMenu();
                break;
            case 2:
                system("cls");
                std::cout << "Historial" << std::endl;
                break;
            case 3:
                std::cout << "Adios! hasta la proxima!" << std::endl;
                endGame = true;
                break;
            default:
                showError("La opcion no es valida. Vuelve a intentarlo");
                Sleep(3000);
                cleanError();
                break;
            }
        }
        else {
            showError("Error: se ingreso un caracter no valido");
            Sleep(3000);
            cleanError();
        }



    } while (!endGame);

}