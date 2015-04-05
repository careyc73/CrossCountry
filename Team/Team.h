/*
 * Team.h
 *
 *  Created on: Mar 31, 2015
 *      Author: careyc
 */

#ifndef TEAM_H_
#define TEAM_H_

#include <string>
#include <vector>
#include "../Runner/Runner.h"
#include "../Competition/Performance.h"

static const int teamSize = 8;

class Runner;
class Performance;

class Team {
private:
	Runner * runners[teamSize];
	char * teamName;

public:
	Team(char * teamName);
	~Team();

	Runner * getRunner(int runner);
	char * getName() const;
	void appendPerformances(std::vector<Performance *> & performances);

	void age();
};


#endif /* TEAM_H_ */
