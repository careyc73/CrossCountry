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

Runner::Runner(char * firstName, char * lastName, school_year year, int baseTalent){
	this->firstName = firstName;
	this->lastName = lastName;
	this->year = year;
	this->baseTalent = baseTalent;

	int padding = 55 - (strlen(firstName) + strlen(lastName));
	char * presentationString = new char[15];
	sprintf(presentationString, "%%s %%-%ds %%2d\n", padding);
	presentation = new char [60];

	sprintf(presentation, presentationString, firstName, lastName, year);
}

Runner::~Runner() {
	for (int i = 0 ; i < performances.size() ; i++) {
		delete performances[i];
	}
}

int Runner::getBaseTalent() {
	return baseTalent;
}

char * Runner::toString() {
	return presentation;
}

void Runner::appendPerformance(Performance * performance) {
	performances.push_back(performance);
}
