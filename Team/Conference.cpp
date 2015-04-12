/*
 * Conference.cpp
 *
 *  Created on: Apr 5, 2015
 *      Author: careyc
 */

#include "Conference.h"
#include "../Competition/ConferenceSeason.h"
#include "../Competition/DualMeet.h"
#include "../Competition/ConferenceFinal.h"
#include <iomanip>

Conference::Conference(char * name, std::vector<Team *> teamsInConference) {
	this->teams = teamsInConference;
	this->name = name;
	this->conferenceSeason = new ConferenceSeason(this);
}

char * Conference::getName() {
	return name;
}

std::vector<Team *> Conference::getTeams() {
	return teams;
}

ConferenceSeason * Conference::getSeason() {
	return this->conferenceSeason;
}

std::vector<ConferenceMeet *> Conference::getConferenceMeets() {
	std::vector<ConferenceMeet *> meets;
	std::map<Team *, set<Team *>> teamsScheduled;

	long numMeets = factorial(teams.size()) / (factorial(2) * factorial(teams.size() - 2));

	int week = 1;

	while (meets.size() < numMeets) {
		int numMeetsThisWeek = 0;
		int nextToScan = (week - 1) % teams.size();
		std::set<Team *> teamsRunningThisWeek;

		for (int i = 0 ; i < teams.size() && numMeetsThisWeek < teams.size() / 2; i++) {
			int teamOneIndex = nextTeamToMatch(nextToScan, teamsRunningThisWeek);

			Team * teamOne = teams[teamOneIndex];

			Team * teamTwo = getMatchTeam(teamOne, teamsScheduled, teamsRunningThisWeek, teamOneIndex);

			if (teamTwo == NULL) {
				nextToScan = (nextToScan + 1) % teams.size();
				continue;
			}

			std::vector<Team *> teamsInMeet;
			teamsInMeet.push_back(teamOne);
			teamsInMeet.push_back(teamTwo);
			teamsRunningThisWeek.insert(teamOne);
			teamsRunningThisWeek.insert(teamTwo);

			set<Team *> scheduledForMatchTeam = teamsScheduled[teamOne];
			scheduledForMatchTeam.insert(teamTwo);
			teamsScheduled[teamOne] = scheduledForMatchTeam;

			scheduledForMatchTeam = teamsScheduled[teamTwo];
			scheduledForMatchTeam.insert(teamOne);
			teamsScheduled[teamTwo] = scheduledForMatchTeam;

			meets.push_back(new DualMeet(this, teamsInMeet, week));

			numMeetsThisWeek++;
			nextToScan = (nextToScan + 1) % teams.size();
		}

		week++;
	}

	meets.push_back(new ConferenceFinal(this, teams, week + 1));

	return meets;
}

int Conference::nextTeamToMatch(int start, set<Team *> teamsRunningThisWeek) {
	while(true) {
		if (!teamsRunningThisWeek.count(teams[start])) {
			return start;
		}

		start = (start + 1) % teams.size();
	}
}

Team * Conference::getMatchTeam(Team * team, std::map<Team *, set<Team *>> teamsScheduledForThisTeam,
								std::set<Team *> teamsRunningThisWeek, int teamIndex) {
	int confSize = teams.size();
	int nextCandidate = (teamIndex + 1) % confSize;
	set<Team *> teamsAlreadyScheduled = teamsScheduledForThisTeam[team];
	while (true) {
		Team * candidateTeam = teams[nextCandidate];
		if (!teamsAlreadyScheduled.count(candidateTeam) && !teamsRunningThisWeek.count(candidateTeam)) {
			return teams[nextCandidate];
		}

		nextCandidate = (nextCandidate + 1) % confSize;

		if (nextCandidate == teamIndex)
			return NULL;
	}
}

long Conference::factorial(long x) {
	long result = x;
	while (--x > 1) {
		result *= x;
	}
	return result;
}
