/*
 * Meet.h
 *
 *  Created on: Apr 4, 2015
 *      Author: careyc
 */

#ifndef MEET_H_
#define MEET_H_

#include <vector>
#include "TeamPerformance.h"
#include "Performance.h"

class Meet {
private:
	std::vector<TeamPerformance *> teams;
	std::vector<Performance *> runners;

public:
	Meet(std::vector<Team *> teams);
	~Meet();

	std::vector<TeamPerformance *> getTeams();
	std::vector<Performance *> getRunners();

	void outputRunnerResults();
	void outputTeamResults();
};



#endif /* MEET_H_ */
