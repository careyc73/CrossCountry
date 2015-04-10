/*
 * ConferenceMeet.h
 *
 *  Created on: Apr 5, 2015
 *      Author: careyc
 */

#ifndef CONFERENCEMEET_H_
#define CONFERENCEMEET_H_

#include "Meet.h"

class ConferenceMeet : public Meet {
private:
	int week;

public:
	ConferenceMeet(std::vector<Team *> teams, int week);

	int getWeek();
};


#endif /* CONFERENCEMEET_H_ */
