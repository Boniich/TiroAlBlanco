#pragma once
struct GoalSystemTDA;
typedef struct GoalSystemTDA* Goal;

Goal create(const int goal, int point_per_impact);
void incressPoints(const Goal goal);
bool archivedGoal(const Goal goal);
int	 getGoal(const Goal goal);
int  getAccumulatedPoints(const Goal goal);