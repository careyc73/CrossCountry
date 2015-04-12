/*
 * DualMeet.h
 *
 *  Created on: Apr 10, 2015
 *      Author: careyc
 */

#ifndef DUALMEET_H_
#define DUALMEET_H_

#include "ConferenceMeet.h"

class DualMeet : public ConferenceMeet {
public:
	DualMeet(Conference * conference, std::vector<Team *> teams, int week)
		: ConferenceMeet(conference, teams, week) {}
	~DualMeet();

	void score();
};



#endif /* DUALMEET_H_ */
