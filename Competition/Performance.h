/*
 * RunnerPerformance.h
 *
 *  Created on: Mar 29, 2015
 *      Author: careyc
 */

#ifndef RUNNERPERFORMANCE_H_
#define RUNNERPERFORMANCE_H_

#include "../Runner/Runner.h"
#include <algorithm>
#include <vector>

class Runner;

class Performance {
private:
	static const int baseFinishTime = 990;

	const Runner * runner;
	int time;
//	const Meet * meet;

public:
	Performance(Runner * runner);

	int getTime();
	const Runner * getRunner();

	static bool comparePerformances(Performance * runnerOne, Performance * runnerTwo) {
		return runnerOne->time < runnerTwo->time;
	}
};



#endif /* RUNNERPERFORMANCE_H_ */
