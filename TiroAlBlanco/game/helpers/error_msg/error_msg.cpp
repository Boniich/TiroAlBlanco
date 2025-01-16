#include "error_msg.h"
#include <iostream>
#include "../move_across_screen/move_across_screen.h"

void showError(const char * msg) {
    moveAcrossScreen(10, 12); printf("--------------------------------------------");
    moveAcrossScreen(10, 13); printf("%s",msg);
    moveAcrossScreen(10, 14); printf("--------------------------------------------");
    std::cin.clear();
    std::cin.ignore();
}
void cleanError() {
    moveAcrossScreen(10, 12); printf("                                       ");
    moveAcrossScreen(10, 13); printf("                                       ");
    moveAcrossScreen(10, 14); printf("                                       ");
}