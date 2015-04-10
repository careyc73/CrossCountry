/*
 * Conference.h
 *
 *  Created on: Apr 4, 2015
 *      Author: careyc
 */

#ifndef CONFERENCE_H_
#define CONFERENCE_H_

#include <vector>
#include <map>
#include <set>
#include "../Competition/ConferenceMeet.h"

class Conference {
private:
	std::vector<Team *> teams;
	char * name;

public:
	Conference(char * name, std::vector<Team *> teams);

	std::vector<Team *> getTeams();
	std::vector<ConferenceMeet *> getConferenceMeets();

	char * getName();

private :
	Team * getMatchTeam(Team * team,
						std::map<Team *, set<Team *>> teamsScheduledForThisTeam,
						std::set<Team *> teamsRunningThisWeek,
						int teamIndex);
	int nextTeamToMatch(int start, set<Team *> teamsRunningThisWeek);
	long factorial(long x);
};


#endif /* CONFERENCE_H_ */
