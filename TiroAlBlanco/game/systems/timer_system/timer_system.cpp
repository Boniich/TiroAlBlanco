#include "timer_system.h"
#include <chrono>
#include <thread>
#include <atomic>
#include "../../helpers/move_across_screen/move_across_screen.h"

struct TimerSystemTDA {
	int minutes;
	int seconds;
};

Timer createTimer(int minutes, int seconds) {
	Timer new_timer = new TimerSystemTDA;
	new_timer->minutes = minutes;
	new_timer->seconds = seconds;

	return new_timer;
}
Timer createTimer(int seconds) {
	Timer new_timer = new TimerSystemTDA;
	new_timer->minutes = 0;
	new_timer->seconds = seconds;

	return new_timer;
}
void destroy(Timer timer) {
	delete timer;
}
void runTimer(Timer timer,std::atomic<bool>& ends_game_timer) {

	while (!ends_game_timer) {
		if (timer->minutes == 1) {
			timer->minutes = 00;
			timer->seconds = 59;
		}
		else {
			timer->seconds--;
		}
		std::this_thread::sleep_for(std::chrono::seconds(1));
		ends_game_timer = isTimerEnd(timer);
	}
}
bool isTimerEnd(const Timer timer) {
	return (timer->minutes == 00 && timer->seconds == 00) ? true : false;
}
int getMinutes(const Timer timer) {
	return timer->minutes;
}
int getSeconds(const Timer timer) {
	return timer->seconds;
}