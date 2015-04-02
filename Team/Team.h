/*
 * Team.h
 *
 *  Created on: Mar 31, 2015
 *      Author: careyc
 */

#ifndef TEAM_H_
#define TEAM_H_

#include <string>
#include "../Runner/Runner.h"

static const int teamSize = 8;

class Runner;

class Team {
private:
	Runner * runners[teamSize];
	char * teamName;

public:
	Team(char * teamName);
	~Team();

	Runner * getRunner(int runner);
	char * getName() const;
};


#endif /* TEAM_H_ */
