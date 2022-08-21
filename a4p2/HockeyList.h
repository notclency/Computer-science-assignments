#ifndef HOCKEYLIST_H
#define HOCKEYLIST_H

/********************************************************************************************************

              Olympic Hockey Teams Class Functions


  Author:            Clency Tabe
  Email address:     ctabe297@mtroyal.ca
  Course:            COMP 1633 - 001
  Assignment:        Assignment 4 part 2
  Due Date:          March 21, 2022
  Instructor:        Paul Pospisil
 
  Filename:          HockeyList.h

  ***********************************************************

  Purpose:
  
  This application uses declared variables and a declared class
  from an .h file named "HockeyList.h". The code present in this file
  is the implementation of the functions of the declared class in the
  .h file, both private and public functions.

  
  The private data members functions are:
  
  findTeamNumber:   Which finds the numbers of a given team.
  search:           which searches for a given player.
  createNode:       which creates a player node to be linked to the team list.
  link:             which links a newly created player node or unlinked player
                    node to the end of a specific teams list.
  unlink:           which unlinks a node from the team roster.
  displayTeam:      which displays all members of a specific team;

  head[NUMTEAMS]:   each element in this array is a ListNode which acts as a head for each team 
                    present on the team roster.

  tail[NUMTEAMS]:   each element in this array is a ListNode which acts as a tail for each team 
                    present on the team roster.



  Function descriptions:

  findTeamNumber:   this function receives a letter that corresponds to
                    a teamas a passed argument. It then converts that letter
                    into an interger corresponding to it's team and returns it

  search:           this functions receives a position of a given player,
                    an undefiend ListNode pointer, an undefined integer team and
                    found bool variable, then searches for the player. If the player
                    is found, the varibale found will be se to true and the function
                    will return the item node pointing to the player and the team variable
                    containing the players team else, the found boolean will be set to false
                    and ListNode pointer, and item will be left undefined.
                   
  createNode:       this functions recieves a players info, creates and returns a playerNode
                    containing the player's info.
  
  link:             this function receives a node pointer and team number and unlinks the
                    item pointer to the team of a specific teams list. It does this by seting
                    the previous node from  the tail to point to this item, the item's previous
                    pointer to point to the previous node from the tail, the item's next pointer
                    to point to the address of the tail and fianlly the tail to point to the item.
                    IN THAT SPECIFIC ORDER!. 
  
 unlink:            this function unlinks a node from the teams list. It does this by seting the next pointer
                    of the previous item to next to the next node to item, and the previous pointer of the next
                    node to item to the previous node to the item.

 displayTeam:       this function receives an integer corresponding to team, a position variable
                    to keep track of the members of the team roster, and an ostream, then displays
                    all the members a of that team together with each of their info using the ostream.



******************************************************************************************************/


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
  bool update(int position, int goals, int assists, int goalsAgainst);
  void lookup(int position, PlayerNode &player, bool &found) const;
  char getTeam(int position) const;

 private:
  struct ListNode
  {
    ListNode *next;
    ListNode *prev;
    PlayerPtr thePlayer;
  };

  typedef ListNode *ListPtr;

  int findTeamNumber(char teamLetter);
  void search(int pos, ListPtr &item, int &team, bool &found) const;
  ListPtr createNode(const char name[], char position, int goals, int assists, 
                        int goalsAgainst) const;
  void link(ListPtr item, int team);
  void unlink(ListPtr item);
  void displayTeam(int team, int &position, ostream &out) const;

  ListNode head[NUMTEAMS];
  ListNode tail[NUMTEAMS];
};

#endif
