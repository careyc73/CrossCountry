/*
 * Team.cpp
 *
 *  Created on: Mar 31, 2015
 *      Author: careyc
 */

#include "Team.h"
#include "../Runner/RunnerUtilities.cpp"

Team::Team() {
	for (int i = 0 ; i < teamSize ; i++) {
		runners[i] = RunnerUtilities::newRunner();
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


