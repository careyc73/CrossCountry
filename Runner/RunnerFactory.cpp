/*
 * RunnerFactory.cpp
 *
 *  Created on: Mar 26, 2015
 *      Author: careyc
 */

#include <stdlib.h>
#include "Runner.h"

using namespace std;

static char *allFirstNames[9] = {"Chris", "Gabe", "Travis",
"Matt", "Mike", "Tom", "Joe", "Bob", "Myles"};

static char *allLastNames[9] = {"Carey", "Jones", "Jennings",
"Smith", "Kramer", "Schroeder", "Erickson", "Miller", "Downs"};

class RunnerFactory {

public:
static Runner * newRunner() {
	char * firstName = allFirstNames[rand() %9];
	char * lastName = allLastNames[rand() %9];
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

};

