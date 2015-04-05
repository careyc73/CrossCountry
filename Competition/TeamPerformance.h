/*
 * TeamPerformance.h
 *
 *  Created on: Apr 3, 2015
 *      Author: careyc
 */

#ifndef TEAMPERFORMANCE_H_
#define TEAMPERFORMANCE_H_

#include "Performance.h"
#include "../Team/Team.h"
#include <vector>

class TeamPerformance {
private:
	Team * team;
	std::vector<Performance *> runnerPerformances;
	int score;

public:
	TeamPerformance(Team * team, std::vector<Performance *> performances);
	~TeamPerformance();

	Team * getTeam();
	int getScore();

	static bool comparePerformances(TeamPerformance * teamOne, TeamPerformance * teamTwo) {
		return teamOne->score < teamTwo->score;
	}
};



#endif /* TEAMPERFORMANCE_H_ */
