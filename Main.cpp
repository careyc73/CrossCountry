/*
 * Main.cpp
 *
 *  Created on: Mar 25, 2015
 *      Author: careyc
 */

#include "Team/Team.h"
#include <vector>
#include "Competition/Meet.h"
#include "Team/Conference.h"
#include <iomanip>

using namespace std;

int main() {
	srand(time(NULL));

	std::vector<Team *> teams;
	teams.push_back(new Team("A"));
	teams.push_back(new Team("B"));
	teams.push_back(new Team("C"));
	teams.push_back(new Team("D"));
	teams.push_back(new Team("E"));
	teams.push_back(new Team("F"));

	Conference * conference = new Conference(teams);

	std::vector<ConferenceMeet *> meets = conference->getConferenceMeets();

	for (int i = 0 ; i < meets.size() ; i++) {
		ConferenceMeet * meet = meets[i];

		cout << setw(5) << meet->getWeek();

		std::vector<Team *> teamsInMeet = meet->getCompetingTeams();
		for (int j = 0 ; j < teamsInMeet.size() ; j++) {
			cout << setw(20) << teamsInMeet[j]->getName();
		}

		cout << "\n";
	}

//
//	teams = conference->getTeams();
//
//	char continueRunning = 'Y';
//	while (continueRunning != 'N') {
//		for (int i = 0 ; i < teams.size() ; i++) {
//			teams[i]->age();
//		}
//
//		Meet * meet = new Meet(teams);
//
//		meet->outputTeamResults();
//		meet->outputRunnerResults();
//
//		cout << "Continue?  (Y/N)\n";
//		cin >> continueRunning;
//	}
}

