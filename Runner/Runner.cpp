/*
 * Runner.cpp
 *
 *  Created on: Mar 26, 2015
 *      Author: careyc
 */

#include "Runner.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Runner::Runner(char * firstName, char * lastName, school_year year, int baseTalent, Team * team){
	this->firstName = firstName;
	this->lastName = lastName;
	this->year = year;
	this->baseTalent = baseTalent;
	this->team = team;

	const char * teamName = team->getName();

	fullName = new char[strlen(firstName) + strlen(lastName) + 3];
	sprintf(fullName, "%s %s", firstName, lastName);
}

Runner::~Runner() {
	for (int i = 0 ; i < performances.size() ; i++) {
		delete performances[i];
	}
}

int Runner::getBaseTalent() {
	return baseTalent;
}

void Runner::appendPerformance(Performance * performance) {
	performances.push_back(performance);
}

Team * Runner::getTeam() {
	return team;
}

char * Runner::getName() {
	return fullName;
}

school_year Runner::getYear() {
	return year;
}
