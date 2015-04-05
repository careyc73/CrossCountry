/*
 * Team.cpp
 *
 *  Created on: Mar 31, 2015
 *      Author: careyc
 */

#include "Team.h"
#include "../UtilityFunctions.h"

Team::Team(char * teamName) {
	this->teamName = teamName;

	for (int i = 0 ; i < teamSize ; i++) {
		runners[i] = UtilityFunctions::newRunner(this);
	}
}

Team::~Team() {
	for (int i = 0 ; i < teamSize ; i++) {
		delete runners[i];
	}
}

Runner * Team::getRunner(int runner) {
	return runners[runner];
}

char * Team::getName() const {
	return teamName;
}

void Team::appendPerformances(std::vector<Performance *> & performances) {
	for (int i = 0 ; i < teamSize ; i++) {
		srand(time(NULL));
		performances.push_back(new Performance(runners[i]));
	}
}

void Team::age() {
	for (int i = 0 ; i < teamSize ; i++) {
		if (runners[i]->getYear() == school_year::Senior) {
			delete runners[i];
			runners[i] = UtilityFunctions::newRunner(this);
		}
		else {
			runners[i]->age();
		}
	}
}
