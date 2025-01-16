#include "ask_name.h"
#include <iostream>
#include "../../helpers/move_across_screen/move_across_screen.h"
#include "../../game_scenes/limits/limits.h"

std::string askName() {

    std::string name;

    system("cls");
    moveAcrossScreen(35, 5); printf("TIRO AL BLANCO");
    printLimits();
    moveAcrossScreen(10, 10); printf("Introduce tu nombre: ");
    std::cin >> name;

    system("cls");

    return name;
}