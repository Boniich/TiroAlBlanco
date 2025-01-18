#include <iostream>
#include "win_loss_feedback.h"
#include "../move_across_screen/move_across_screen.h"
#include "../../game_scenes/limits/limits.h"

void showFeedback(const WinLossData data) {
    system("cls");
    printLimits();
    moveAcrossScreen(data.title_x, data.title_y); printf("%s",data.title);
    moveAcrossScreen(data.sub_title_x, data.sub_title_y); printf("%s", data.sub_title);
}