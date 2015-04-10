/*
 * Conference.cpp
 *
 *  Created on: Apr 5, 2015
 *      Author: careyc
 */

#include "Conference.h"
#include <iomanip>

Conference::Conference(std::vector<Team *> teamsInConference) {
	this->teams = teamsInConference;
}

std::vector<Team *> Conference::getTeams() {
	return teams;
}

std::vector<ConferenceMeet *> Conference::getConferenceMeets() {
	std::vector<ConferenceMeet *> meets;
	std::map<Team *, set<Team *>> teamsScheduled;

	int numWeeks = ((teams.size() % 2) == 0) ? teams.size() -1 : teams.size();
	int meetsPerWeek = teams.size() / 2;

	for (int i = 0 ; i < numWeeks ; i++) {
		cout << "New Week\n";

		std::set<Team *> teamsRunningThisWeek;

		Team * teamSeekingMatch = teams[i];
		for (int j = 0 ; j < meetsPerWeek ; j++) {
			std::vector<Team *> teamsInMeet;
			teamsInMeet.push_back(teamSeekingMatch);

			teamsRunningThisWeek.insert(teamSeekingMatch);
			set<Team *> scheduledForMatchTeam = teamsScheduled[teamSeekingMatch];
			Team * match = getMatchTeam(teamSeekingMatch, teamsScheduled, teamsRunningThisWeek, i);
			teamsRunningThisWeek.insert(match);
			scheduledForMatchTeam.insert(match);
			teamsScheduled[teamSeekingMatch] = scheduledForMatchTeam;
			teamsInMeet.push_back(match);

			meets.push_back(new ConferenceMeet(teamsInMeet, i + 1));

			if ((j + 1) < meetsPerWeek) {
				teamSeekingMatch = teams[nextTeamToMatch((i + 1) % teams.size() , teamsRunningThisWeek)];
			}
		}

		for (int k = 0 ; k < meets.size() ; k++) {
			ConferenceMeet * meet = meets[k];

			cout << setw(5) << meet->getWeek();

			std::vector<Team *> teamsInMeet = meet->getCompetingTeams();
			for (int j = 0 ; j < teamsInMeet.size() ; j++) {
				cout << setw(20) << teamsInMeet[j]->getName();
			}

			cout << "\n";
		}
	}

	return meets;
}

int Conference::nextTeamToMatch(int candidate, set<Team *> teamsRunningThisWeek) {
	while(true) {
		if (!teamsRunningThisWeek.count(teams[candidate])) {
			return candidate;
		}

		candidate = (candidate + 1) % teams.size();
	}
}

Team * Conference::getMatchTeam(Team * team, std::map<Team *, set<Team *>> teamsScheduledForThisTeam,
								std::set<Team *> teamsRunningThisWeek, int teamIndex) {
	cout << "Seeking match for " << team->getName() << "\n";
	int confSize = teams.size();
	int nextCandidate = (teamIndex + 1) % confSize;
	set<Team *> teamsAlreadyScheduled = teamsScheduledForThisTeam[team];
	while (true) {
		Team * candidateTeam = teams[nextCandidate];
		if (!teamsAlreadyScheduled.count(candidateTeam) && !teamsRunningThisWeek.count(candidateTeam)) {
			cout << "Found Match " << teams[nextCandidate]->getName() << "\n";
			return teams[nextCandidate];
		}

		nextCandidate = (nextCandidate + 1) % confSize;
	}
}
