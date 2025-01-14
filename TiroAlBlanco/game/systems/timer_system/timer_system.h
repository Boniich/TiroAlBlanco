#pragma once
#include <atomic>
struct TimerSystemTDA;
typedef struct TimerSystemTDA* Timer;

Timer createTimer(int minutes, int seconds);
Timer createTimer(int seconds);
void destroy(Timer timer);
void runTimer(Timer timer, std::atomic<bool>& ends_game_timer);
bool isTimerEnd(const Timer timer);
int getMinutes(const Timer timer);
int getSeconds(const Timer timer);
void resetTimer(Timer timer, const int seconds);
