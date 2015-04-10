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
	teams.push_back(new Team("Baraboo"));
	teams.push_back(new Team("DeForest"));
	teams.push_back(new Team("Edgewood"));
	teams.push_back(new Team("Fort Atkinson"));
	teams.push_back(new Team("Milton"));
	teams.push_back(new Team("Monona Grove"));
	teams.push_back(new Team("Monroe"));
	teams.push_back(new Team("Mount Horeb"));
	teams.push_back(new Team("Oregon"));
	teams.push_back(new Team("Portage"));
	teams.push_back(new Team("Reedsburg"));
	teams.push_back(new Team("Sauk Prairie"));
	teams.push_back(new Team("Stoughton"));
	teams.push_back(new Team("Waunakee"));

	Conference * badger = new Conference("Badger", teams);

	std::vector<ConferenceMeet *> meets = badger->getConferenceMeets();

	char next;
	int week = 0;

	for (int i = 0 ; i < meets.size() ; i++) {
		ConferenceMeet * meet = meets[i];

		if (meet->getWeek() != week) {
			week = meet->getWeek();
			cout << "*** Week " << week << " ***\n";
		}

		meet->runMeet();

		meet->outputTeamResults();

		meet->outputRunnerResults();

		cout << "Next? Press Button\n";
		cin >> next;
	}
}

