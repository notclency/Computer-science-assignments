#ifndef TEAMLIST_H
#define TEAMLIST_H

#include <iostream>
#include <fstream>
using namespace std;

const int MAXNAMELEN = 25;
const int MINNAMELEN = 1;

const int NUMTEAMS = 4;

typedef char teamname[MAXNAMELEN+1];		// one team name is a c-string

const teamname TEAMS[NUMTEAMS] = {"Team Canada:",		
                                  "Team Finland:", 
                                  "Team USA:",
                                  "Injury Reserve:" };

const char TEAMCHARS[NUMTEAMS] = {'C', 'F', 'U', 'I'};

const char FORWARD = 'f';
const char DEFENCE = 'd';
const char GOAL = 'g';

const int NAMEWIDTH = 26;
const int TEAMWIDTH = 6;
const int GOALWIDTH = 2;
const int ASSISTWIDTH = 7;

////////////////////////////////////////////////
// Required list node structure and pointer type
////////////////////////////////////////////////

typedef struct PlayerNode *PlayerPtr;

struct PlayerNode
{
  char name[MAXNAMELEN+1];
  char team;
  char position;
  int goals;
  int assists;
  int goalsAgainst;
  PlayerPtr next;
};

////////////////////////////////////////////////
// 
////////////////////////////////////////////////

PlayerPtr createPlayer (const char name[], char team, char position,
                         int goals, int assists, int goalsAgainst);

void search (PlayerPtr head, int itemNumber, PlayerPtr &node, bool &found);

void insertPlayer (PlayerPtr &head, PlayerPtr player);

void removePlayer (PlayerPtr &head, PlayerPtr player);

void displayTeams (PlayerPtr head, ostream &out);

bool containsActivePlayers (PlayerPtr head);

void destroyList (PlayerPtr &head);

#endif

