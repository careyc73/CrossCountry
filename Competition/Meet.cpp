/*
 * Meet.cpp
 *
 *  Created on: Apr 4, 2015
 *      Author: careyc
 */

#include "Meet.h"
#include "../UtilityFunctions.h"

Meet::Meet(std::vector<Team *> competingTeams) {
	for (int i = 0 ; i < competingTeams.size() ; i++) {
		competingTeams[i]->appendPerformances(runners);
	}

	std::sort(runners.begin(), runners.end(), Performance::comparePerformances);

	teams = UtilityFunctions::scoreMeet(runners);
	std::sort(teams.begin(), teams.end(), TeamPerformance::comparePerformances);
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
		cout << i + 1 << " " << runner->toString();
	}

	cout << "\n";
}

void Meet::outputTeamResults() {
	for (int i = 0 ; i < teams.size() ; i++) {
		Team * team = teams[i]->getTeam();
		cout << i + 1 << " " << team->getName() << " " << teams[i]->getScore() << "\n";
	}

	cout << "\n";
}
