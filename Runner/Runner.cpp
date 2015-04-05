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
#include <stdexcept>

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

void Runner::age() {
	if (year == school_year::Senior) {
		throw std::invalid_argument("Runner is already a senior, they're graduating");
	} else if (year == school_year::Junior) {
		year = school_year::Senior;
	} else if (year == school_year::Sophmore) {
		year = school_year::Junior;
	} else if (year == school_year::Freshman) {
		year = school_year::Sophmore;
	}

	int adjustBucket = rand() % 100;
	double adjust;

	if (adjustBucket < 20) {
		adjust = 1 + (((double) (rand() % 1500) - 1200.0) / 10000.0);
	}
	else if (adjustBucket > 96) {
		adjust = 1 + (((double) (rand() % 1000) - 200.0) / 10000.0);
	}
	else {
		adjust = 1 + (((double) (rand() % 1000) - 700.0) / 10000.0);
	}

	baseTalent = baseTalent * adjust;
}
