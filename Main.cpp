/*
 * Main.cpp
 *
 *  Created on: Mar 25, 2015
 *      Author: careyc
 */

#include "Team/Team.h"
#include "Runner/RunnerUtilities.cpp"
#include <stdlib.h>
#include "Competition/Performance.h"

using namespace std;

int main() {
	srand(time(NULL));

	Team * team = new Team();
	Performance *performance[teamSize];

	for (int i = 0 ; i < teamSize ; i++) {
		srand(time(NULL));
		cout << team->getRunner(i)->toString();
		performance[i] = new Performance(team->getRunner(i));
		cout << RunnerUtilities::translateTime(performance[i]->getTime()) << "\n";
	}

	delete team;
}

