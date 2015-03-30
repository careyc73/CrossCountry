/*
 * Main.cpp
 *
 *  Created on: Mar 25, 2015
 *      Author: careyc
 */

#include "Runner/Runner.h"
#include "Runner/RunnerUtilities.cpp"
#include "Competition/Performance.h"

using namespace std;

int main() {
	srand(time(NULL));
	Runner * runnerOne = RunnerUtilities::newRunner();

	cout << runnerOne->toString();

	Performance * performance = new Performance(runnerOne);

	cout << RunnerUtilities::translateTime(performance->getTime());

	delete runnerOne;
}

