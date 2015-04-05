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
#include "../Team/Team.h"

using namespace std;

enum school_year {Freshman = 9, Sophmore = 10, Junior = 11, Senior = 12};

class Performance;
class Team;

class Runner
{
private:
	char * firstName;
	char * lastName;
	school_year year;
	char * fullName;
	int baseTalent;
	Team * team;

	std::vector<Performance *> performances;

public:
	Runner(char * firstName, char * lastName, school_year year, int baseTalent, Team * team);
	~Runner();

	int getBaseTalent();
	void appendPerformance(Performance * performance);
	Team * getTeam();
	char * getName();
	school_year getYear();

	void age();
};


#endif /* RUNNER_H_ */
