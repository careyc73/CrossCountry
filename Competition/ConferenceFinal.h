/*
 * ConferenceFinal.h
 *
 *  Created on: Apr 11, 2015
 *      Author: careyc
 */

#ifndef CONFERENCEFINAL_H_
#define CONFERENCEFINAL_H_

#include "ConferenceMeet.h"

class ConferenceFinal : public ConferenceMeet {
public:
	ConferenceFinal(Conference * conference, std::vector<Team *> teams, int week)
		: ConferenceMeet(conference, teams, week) {}
	~ConferenceFinal();

	void score();
};



#endif /* CONFERENCEFINAL_H_ */
