/*
 * RunnerPerformance.h
 *
 *  Created on: Mar 29, 2015
 *      Author: careyc
 */

#ifndef RUNNERPERFORMANCE_H_
#define RUNNERPERFORMANCE_H_

#include "../Runner/Runner.h"

class Runner;

class Performance {
private:
	static const int baseFinishTime = 1260;

	const Runner * runner;
	int time;
//	const Meet * meet;

public:
	Performance(Runner * runner);;

	int getTime();
};



#endif /* RUNNERPERFORMANCE_H_ */
