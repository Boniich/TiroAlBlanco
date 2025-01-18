#include "win_loss_sub_menu.h"
#include <iostream>
#include <Windows.h>
#include "../../helpers/win_loss_feeback/win_loss_feedback.h"
#include "../../helpers/move_across_screen/move_across_screen.h"
#include "../../core_game/play_game/play_game.h"
#include "../../helpers/error_msg/error_msg.h"
#include "../../helpers/win_loss_feeback/win_loss_data.h"

void showWinLossScreenWithSubMenu() {

    bool play_again = false;

    do {
        if (playGame()) {
            showFeedback(WIN);
            winLossSubMenu(play_again);
        }
        else {
            showFeedback(LOSS);
            winLossSubMenu(play_again);
        }
        system("cls");
    } while (play_again);
}

void winLossSubMenu(bool& play_again) {
    int opcion;
    moveAcrossScreen(10, 8); printf("--- Menu --- ");
    moveAcrossScreen(10, 9); printf("1- Jugar de nuevo ");
    moveAcrossScreen(10, 10); printf("2- Volver al menu principal ");
    moveAcrossScreen(10, 12); printf("Selecciona una opcion: ");
    if (std::cin >> opcion) {
        bool opcionSeleccionada = false;
        do {

            switch (opcion)
            {
            case 1:
                play_again = true;
                break;
            case 2:
                play_again = false;
                break;

            default:
                opcionSeleccionada = true;
                showError("La opcion no es valida. Vuelve a intentarlo");
                Sleep(3000);
                cleanError();
                break;
            }

        } while (opcionSeleccionada);
    }
    else {
        showError("Error: se ingreso un caracter no valido");
        Sleep(3000);
        cleanError();
    }
}