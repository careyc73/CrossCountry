/*
 * Team.h
 *
 *  Created on: Mar 31, 2015
 *      Author: careyc
 */

#ifndef TEAM_H_
#define TEAM_H_

#include "../Runner/Runner.h"

static const int teamSize = 8;

class Team {
private:
	Runner * runners[teamSize];

public:
	Team();
	~Team();

	Runner * getRunner(int runner);
};


#endif /* TEAM_H_ */
