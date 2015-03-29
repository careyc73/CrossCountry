/*
 * Main.cpp
 *
 *  Created on: Mar 25, 2015
 *      Author: careyc
 */

#include "Runner/Runner.h"
#include "Runner/RunnerFactory.cpp"
using namespace std;

int main() {
	srand(time(NULL));
	Runner * runnerOne = RunnerFactory::newRunner();

	cout << runnerOne->toString();
}

