/*
 * Performance.cpp
 *
 *  Created on: Mar 29, 2015
 *      Author: careyc
 */
#include <stdlib.h>
#include "Performance.h"

Performance::Performance(Runner * runner) {
	this -> runner = runner;
	double adjust = 1 + (((double) (rand() % 2000)) - 1000.0) / 10000.0;
	this -> time = baseFinishTime + (((double) runner -> getBaseTalent()) * adjust);

	runner->appendPerformance(this);
}

int Performance::getTime() {
	return time;
}

Runner * Performance::getRunner() {
	return runner;
}

