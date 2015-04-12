/*
 * DualMeet.cpp
 *
 *  Created on: Apr 10, 2015
 *      Author: careyc
 */

#include "DualMeet.h"

DualMeet::~DualMeet() {}

void DualMeet::score() {
	Team * winningTeam = this->teams[0]->getTeam();
	Team * losingTeam = this->teams[1]->getTeam();
	season->augmentScore(winningTeam, 2);
	season->incrementWins(winningTeam);
	season->incrementLosses(losingTeam);
}



