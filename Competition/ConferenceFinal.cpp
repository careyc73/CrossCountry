/*
 * ConferenceFinal.cpp
 *
 *  Created on: Apr 11, 2015
 *      Author: careyc
 */

#include "ConferenceFinal.h"

ConferenceFinal::~ConferenceFinal() {}

void ConferenceFinal::score() {
	double pointsForNextTeam = teams.size() * 2.5;

	for (uint i = 0 ; i < teams.size() ; i++) {
		Team * nextTeam = teams[i]->getTeam();
		this->season->augmentScore(nextTeam, pointsForNextTeam);
		pointsForNextTeam -= 2.5;
	}
}


