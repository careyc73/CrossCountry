/*
 * ConferenceSeason.h
 *
 *  Created on: Apr 5, 2015
 *      Author: careyc
 */

#ifndef CONFERENCESEASON_H_
#define CONFERENCESEASON_H_

#include <vector>
#include <map>

class Conference;
class Team;

class ConferenceSeason {
private:
	typedef struct TeamScore {
		Team * team;
		double score;
		int wins;
		int losses;
	};

	Conference * conference;
	std::vector<TeamScore> scores;

public:
	ConferenceSeason(Conference * conference);

	void outputTeamRankings();
	void augmentScore(Team * team, double amount);
	Team * getLeadingTeam();
	void incrementWins(Team * team);
	void incrementLosses(Team * team);

private:

	static bool compareTeams(TeamScore teamOne, TeamScore teamTwo) {
		return teamOne.score > teamTwo.score;
	}
};


#endif /* CONFERENCESEASON_H_ */
