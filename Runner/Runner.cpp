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
	sprintf(presentationString, "%%s, %%-%ds %%2d\n", padding);
	presentation = new char [60];

	sprintf(presentation, presentationString, lastName, firstName, year);
}

int Runner::run() {
	return baseFinishTime - baseTalent + ((rand() % 60) - 30);
}

char * Runner::toString() {
	return presentation;
}
