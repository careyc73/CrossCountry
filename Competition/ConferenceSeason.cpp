/*
 * ConferenceSeason.cpp
 *
 *  Created on: Apr 10, 2015
 *      Author: careyc
 */

#include "ConferenceSeason.h"
#include "../Team/Conference.h"
#include "../Team/Team.h"
#include <iomanip>

ConferenceSeason::ConferenceSeason(Conference * conference) {
	this->conference = conference;

	std::vector<Team *> teams = conference->getTeams();
	for (int i = 0 ; i < teams.size() ; i++) {
		TeamScore teamScore;

		teamScore.team = teams[i];
		teamScore.score = 0.0;
		teamScore.wins = 0;
		teamScore.losses = 0;

		scores.push_back(teamScore);
	}
}

void ConferenceSeason::augmentScore(Team * team, double amount) {
	for (int i = 0 ; i < scores.size() ; i++) {
		if (scores[i].team == team) {
			scores[i].score += amount;
			return;
		}
	}
}

void ConferenceSeason::incrementWins(Team * team) {
	for (int i = 0 ; i < scores.size() ; i++) {
		if (scores[i].team == team) {
			scores[i].wins += 1;
		}
	}
}

void ConferenceSeason::incrementLosses(Team * team) {
	for (int i = 0 ; i < scores.size() ; i++) {
		if (scores[i].team == team) {
			scores[i].losses += 1;
		}
	}
}

Team * ConferenceSeason::getLeadingTeam() {
	std::sort(scores.begin(), scores.end(), compareTeams);
	return scores[0].team;
}

void ConferenceSeason::outputTeamRankings() {
	std::sort(scores.begin(), scores.end(), compareTeams);

	cout 	<< std::left << setw(8) << "Place"
			<< setw(20) << "Team"
			<< setw(5) << "W"
			<< setw(5) << "L"
			<< setw(10) << "Points" << "\n";

	for (int i = 0 ; i < scores.size() ; i++) {
		TeamScore score = scores[i];
		cout 	<< std::left << setw(8) << i + 1
				<< setw(20) << scores[i].team->getName()
				<< setw(5) << scores[i].wins
				<< setw(5) << scores[i].losses
				<< setw(10) << scores[i].score << "\n";
	}

	cout << "\n";

}



