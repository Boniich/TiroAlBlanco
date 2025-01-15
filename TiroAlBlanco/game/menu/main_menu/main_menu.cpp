#include "main_menu.h"
#include <Windows.h>
#include <iostream>
#include "../../helpers/move_across_screen/move_across_screen.h"
#include "../../game_scenes/limits/limits.h"

void startMenu() {
    bool endGame = false;
    int opcion;


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
                system("cls");
                std::cout << "Jugar";
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
                moveAcrossScreen(10, 12); printf("--------------------------------------------");
                moveAcrossScreen(10, 13); printf("La opcion no es valida. Vuelve a intentarlo ");
                moveAcrossScreen(10, 14); printf("-------------------------------------------");

                Sleep(3000);
                moveAcrossScreen(10, 12); printf("                                            ");
                moveAcrossScreen(10, 13); printf("                                            ");
                moveAcrossScreen(10, 14); printf("                                            ");
                break;
            }
        }
        else {
            moveAcrossScreen(10, 12); printf("---------------------------------------");
            moveAcrossScreen(10, 13); printf("Error: se ingreso un caracter no valido");
            moveAcrossScreen(10, 14); printf("---------------------------------------");
            std::cin.clear();
            std::cin.ignore();

            Sleep(3000);

            moveAcrossScreen(10, 12); printf("                                       ");
            moveAcrossScreen(10, 13); printf("                                       ");
            moveAcrossScreen(10, 14); printf("                                       ");
        }



    } while (!endGame);

}