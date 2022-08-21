#ifndef HOCKEYLIST_H
#define HOCKEYLIST_H

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int MAXNAMELEN = 25;
const int MINNAMELEN = 1;

const int NUMTEAMS = 4;
const int INJURY_LIST_POSITION = NUMTEAMS-1;

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
// Player node structure
////////////////////////////////////////////////

typedef struct PlayerNode *PlayerPtr;

struct PlayerNode
{
   char name[MAXNAMELEN+1];
   char position;
   int goals;
   int assists;
   int goalsAgainst;
};



////////////////////////////////////////////////
// 
////////////////////////////////////////////////

class HockeyList
{
 public:
  HockeyList();
  ~HockeyList();

  int  load(istream &infile);
  void write(ostream &out) const;
  void display(ostream &out) const;
  bool move(int position);
  bool activate(int position, char team);
  bool update(int position, int goals, int assists, int goals_against);
  void lookup(int position, PlayerNode &player, bool &found) const;
  char getTeam(int position);

 private:
};

#endif
