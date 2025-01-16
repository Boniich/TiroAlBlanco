#include <iostream>
#include "win_loss_feedback.h"
#include "../move_across_screen/move_across_screen.h"
#include "../../game_scenes/limits/limits.h"

void showFeedback(const char* title, const char* sub_title) {
    system("cls");
    printLimits();
    moveAcrossScreen(35, 5); printf("%s",title);
    moveAcrossScreen(25, 6); printf("%s", sub_title);
}