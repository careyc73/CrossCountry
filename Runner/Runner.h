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
using namespace std;

enum school_year {Freshman = 9, Sophmore = 10, Junior = 11, Senior = 12};

class Runner
{
private:
	char * firstName;
	char * lastName;
	school_year year;
	char * presentation;
	int baseTalent;

	static const int baseFinishTime = 1260;

public:
	Runner(char * firstName, char * lastName, school_year year, int baseTalent);

	int run();

	char * toString();
};


#endif /* RUNNER_H_ */
