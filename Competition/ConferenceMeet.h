/*
 * ConferenceMeet.h
 *
 *  Created on: Apr 5, 2015
 *      Author: careyc
 */

#ifndef CONFERENCEMEET_H_
#define CONFERENCEMEET_H_

#include "Meet.h"
#include "ConferenceSeason.h"

class ConferenceMeet : public Meet {
private:
	int week;

protected:
	ConferenceSeason * season;

public:
	ConferenceMeet(Conference * conference, std::vector<Team *> teams, int week);
	~ConferenceMeet();

	int getWeek();
	virtual void score() = 0;
};


#endif /* CONFERENCEMEET_H_ */
