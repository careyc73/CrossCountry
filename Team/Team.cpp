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
