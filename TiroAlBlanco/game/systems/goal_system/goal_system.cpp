#include "goal_system.h"

struct GoalSystemTDA {
	int goal = 0;
	int accumulated_points = 0;
	int points_per_impact = 0;
};

Goal create(const int goal, const int points_per_impact) {
	Goal new_goal = new GoalSystemTDA;
	new_goal->goal = goal;
	new_goal->points_per_impact = points_per_impact;
	
	return new_goal;
}

void destroy(Goal goal) {
	delete goal;
}

void incressPoints(Goal goal) {
	goal->accumulated_points += goal->points_per_impact;
}

bool archivedGoal(const Goal goal) {
	return (goal->goal == goal->accumulated_points) ? true :false;
}

int	 getGoal(const Goal goal) {
	return goal->goal;
}
int  getAccumulatedPoints(const Goal goal) {
	return goal->accumulated_points;
}

