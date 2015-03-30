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
	this -> time = baseFinishTime - runner -> getBaseTalent() + ((rand() % 60) - 30);

	runner->appendPerformance(this);
}

int Performance::getTime() {
	return time;
}


