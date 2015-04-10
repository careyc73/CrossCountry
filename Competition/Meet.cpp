/*
 * Meet.cpp
 *
 *  Created on: Apr 4, 2015
 *      Author: careyc
 */

#include "Meet.h"
#include <iomanip>
#include "../UtilityFunctions.h"

Meet::Meet(std::vector<Team *> competingTeams) {
	teamsInMeet = competingTeams;
}

void Meet::runMeet() {
	for (int i = 0 ; i < teamsInMeet.size() ; i++) {
		teamsInMeet[i]->appendPerformances(runners);
	}

	std::sort(runners.begin(), runners.end(), Performance::comparePerformances);

	teams = UtilityFunctions::scoreMeet(runners);
	std::sort(teams.begin(), teams.end(), TeamPerformance::comparePerformances);
}

std::vector<Team *> Meet::getCompetingTeams() {
	return teamsInMeet;
}

std::vector<TeamPerformance *> Meet::getTeams() {
	return teams;
}

std::vector<Performance *> Meet::getRunners() {
	return runners;
}

void Meet::outputRunnerResults() {
	for (int i = 0 ; i < runners.size() ; i++) {
		Runner * runner = runners[i]->getRunner();
		cout 	<< std::left << setw(4) << i + 1
				<< setw(8) << UtilityFunctions::translateTime(runners[i]->getTime())
				<< setw(32) << runner->getName()
				<< setw(5) << runner->getYear()
				<< setw(20) << runner->getTeam()->getName() << "\n";
	}

	cout << "\n";
}

void Meet::outputTeamResults() {
	for (int i = 0 ; i < teams.size() ; i++) {
		Team * team = teams[i]->getTeam();
		cout 	<< std::left << setw(3) << i + 1
				<< setw(20) << team->getName()
				<< setw(5) << teams[i]->getScore() << "\n";
	}

	cout << "\n";
}
