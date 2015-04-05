/*
 * Main.cpp
 *
 *  Created on: Mar 25, 2015
 *      Author: careyc
 */

#include "Team/Team.h"
#include <vector>
#include "Competition/Meet.h"

using namespace std;

int main() {
	srand(time(NULL));

	std::vector<Team *> teams;
	teams.push_back(new Team("Waunakee"));
	teams.push_back(new Team("DeForest"));
	teams.push_back(new Team("McFarland"));
	teams.push_back(new Team("Verona"));
	teams.push_back(new Team("Sun Prairie"));
	teams.push_back(new Team("Sauk Prairie"));
	teams.push_back(new Team("Lodi"));

	Meet * meet = new Meet(teams);

	meet->outputTeamResults();
	meet->outputRunnerResults();
}

