/*
 * ConferenceMeet.cpp
 *
 *  Created on: Apr 5, 2015
 *      Author: careyc
 */

#include "ConferenceMeet.h"

ConferenceMeet::ConferenceMeet(std::vector<Team *> teams, int week) : Meet(teams) {
	this->teamsInMeet = teams;
	this->week = week;
}

int ConferenceMeet::getWeek() {
	return this->week;
}
