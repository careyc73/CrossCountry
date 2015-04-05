/*
 * TeamPerformance.cpp
 *
 *  Created on: Apr 3, 2015
 *      Author: careyc
 */

#include "TeamPerformance.h"
#include "Performance.h"

TeamPerformance::TeamPerformance(Team * team, std::vector<Performance *> runnerPerformances) {
	this->score = 0;
	this->team = team;
	this->runnerPerformances = runnerPerformances;

	for (int i = 0 ; i < 5 ; i++) {
		this->score += (runnerPerformances[i]->getPlace());
	}
}

Team * TeamPerformance::getTeam() {
	return this->team;
}

int TeamPerformance::getScore() {
	return this->score;
}

