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

Runner::Runner(char * firstName, char * lastName, school_year year, int baseTalent, const Team * team){
	this->firstName = firstName;
	this->lastName = lastName;
	this->year = year;
	this->baseTalent = baseTalent;
	this->team = team;

	int padding = 55 - (strlen(firstName) + strlen(lastName));
	char * presentationString = new char[22];
	sprintf(presentationString, "%%s %%-%ds %%2d\t%%s\n", padding);
	presentation = new char [80];

	const char * teamName = team->getName();

	sprintf(presentation, presentationString, firstName, lastName, year, teamName);
}

Runner::~Runner() {
	for (int i = 0 ; i < performances.size() ; i++) {
		delete performances[i];
	}
}

int Runner::getBaseTalent() {
	return baseTalent;
}

char * Runner::toString() const {
	return presentation;
}

void Runner::appendPerformance(Performance * performance) {
	performances.push_back(performance);
}
