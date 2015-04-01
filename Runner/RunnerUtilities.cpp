/*
 * RunnerFactory.cpp
 *
 *  Created on: Mar 26, 2015
 *      Author: careyc
 */

#include <stdlib.h>
#include <stdio.h>
#include "Runner.h"

using namespace std;

static const int numNames = 14;

static char *allFirstNames[numNames] = {"Chris", "Gabe", "Travis",
"Matt", "Mike", "Tom", "Joe", "Bob", "Myles", "Bryon", "Todd", "Lee",
"Kurt", "Cooper"};

static char *allLastNames[numNames] = {"Carey", "Jones", "Jennings",
"Smith", "Kramer", "Schroeder", "Erickson", "Miller", "Downs", "Kluever",
"Kenas", "Solinsky", "Bechtel", "Hecht"};

class RunnerUtilities {

public:
	static Runner * newRunner() {
		char * firstName = allFirstNames[rand() % numNames];
		char * lastName = allLastNames[rand() % numNames];
		int yearRand = rand() % 100;
		school_year year;

		if (yearRand < 65) {
			year = Freshman;
		}
		else if (yearRand < 80) {
			year = Sophmore;
		}
		else if (yearRand < 90) {
			year = Junior;
		}
		else {
			year = Senior;
		}

		return new Runner(firstName, lastName, year, rand() % 270);
	}

	static char * translateTime(int time) {
		char * timeString = new char[5];

		sprintf(timeString, "%02d:%02d", time / 60, time % 60);

		return timeString;
	}
};

