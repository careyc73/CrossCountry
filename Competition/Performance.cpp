/*
 * Performance.cpp
 *
 *  Created on: Mar 29, 2015
 *      Author: careyc
 */
#include <stdlib.h>
#include <cstdlib>
#include "Performance.h"

Performance::Performance(Runner * runner) {
	this -> runner = runner;
	double adjust = 1 + (((double) (rand() % 2000)) - 1000.0) / 10000.0;
	int talentOffset = ((double) runner->getBaseTalent()) * adjust;
	this -> time = baseFinishTime + (((double) runner -> getBaseTalent()) * adjust);

	runner->appendPerformance(this);
}

int Performance::getTime() {
	return time;
}

Runner * Performance::getRunner() {
	return runner;
}

void Performance::setPlace(int place) {
	this->place = place;
}

int Performance::getPlace() {
	return this->place;
}

