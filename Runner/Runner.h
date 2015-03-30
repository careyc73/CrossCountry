/*
 * Runner.h
 *
 *  Created on: Mar 25, 2015
 *      Author: careyc
 */

#ifndef RUNNER_H_
#define RUNNER_H_

#include <iostream>
#include <string>
#include <vector>

#include "../Competition/Performance.h"

using namespace std;

enum school_year {Freshman = 9, Sophmore = 10, Junior = 11, Senior = 12};

class Performance;

class Runner
{
private:
	char * firstName;
	char * lastName;
	school_year year;
	char * presentation;
	int baseTalent;

	std::vector<Performance *> performances;

public:
	Runner(char * firstName, char * lastName, school_year year, int baseTalent);
	~Runner();

	int getBaseTalent();
	char * toString();
	void appendPerformance(Performance * performance);
};


#endif /* RUNNER_H_ */
