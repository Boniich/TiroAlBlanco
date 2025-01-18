#pragma once
#include <atomic>
#include "../../systems/goal_system/goal_system.h"
struct TimerSystemTDA;
typedef struct TimerSystemTDA* Timer;

Timer createTimer(int minutes, int seconds);
Timer createTimer(int seconds);
void destroy(Timer timer);
void runTimer(Timer timer, std::atomic<bool>& ends_game_timer, Goal main_goal);
bool isTimerEnd(const Timer timer);
int getMinutes(const Timer timer);
int getSeconds(const Timer timer);
void resetTimer(Timer timer, const int seconds);
