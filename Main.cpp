/*
 * Main.cpp
 *
 *  Created on: Mar 25, 2015
 *      Author: careyc
 */

#include "Team/Team.h"
#include "UtilityFunctions.h"
#include <stdlib.h>
#include "Competition/Performance.h"
#include <vector>

using namespace std;

int main() {
	srand(time(NULL));

	Team * waunakee = new Team("Waunakee");
	Team * deForest = new Team("DeForest");
	Team * mcFarland = new Team("McFarland");
	Team * verona = new Team("Verona");
	std::vector<Performance*> performance;

	for (int i = 0 ; i < teamSize ; i++) {
		srand(time(NULL));
		performance.push_back(new Performance(waunakee->getRunner(i)));
		performance.push_back(new Performance(deForest->getRunner(i)));
		performance.push_back(new Performance(mcFarland->getRunner(i)));
		performance.push_back(new Performance(verona->getRunner(i)));
	}

	std::sort(performance.begin(), performance.end(), Performance::comparePerformances);

	for (int i = 0 ; i < teamSize * 4 ; i++) {
		cout << i + 1 << "\t" << UtilityFunctions::translateTime(performance[i]->getTime()) << "\t"
			<< performance[i]->getRunner()->toString();
	}

	UtilityFunctions::scoreMeet(performance);

	delete waunakee;
	delete deForest;
}

