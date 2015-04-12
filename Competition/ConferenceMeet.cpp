/*
 * ConferenceMeet.cpp
 *
 *  Created on: Apr 5, 2015
 *      Author: careyc
 */

#include "ConferenceMeet.h"
#include "../Team/Conference.h"

ConferenceMeet::ConferenceMeet(Conference * conference, std::vector<Team *> teams, int week) : Meet(teams) {
	this->teamsInMeet = teams;
	this->week = week;

	this->season = conference->getSeason();
}

ConferenceMeet::~ConferenceMeet() {}

int ConferenceMeet::getWeek() {
	return this->week;
}
