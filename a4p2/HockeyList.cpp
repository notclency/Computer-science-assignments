#include "HockeyList.h"

/********************************************************************************************************

              Olympic Hockey Teams Class Functions


  Author:            Clency Tabe
  Email address:     ctabe297@mtroyal.ca
  Course:            COMP 1633 - 001
  Assignment:        Assignment 4 part 2
  Due Date:          March 21, 2022
  Instructor:        Paul Pospisil
 
  Filename:          HockeyList.cpp

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

HockeyList :: HockeyList (){

  for(int i = 0; i < NUMTEAMS; i++){
    head[i].next = &tail[i];
    tail[i].prev = &head[i];
  }  
}



HockeyList :: ~HockeyList (){

  ListPtr curr;
  
  for(int i = 0; i < NUMTEAMS; i++){
    if(head[i].next != &tail[i]){
      curr = head[i].next;
      while(curr != &tail[i]){
     	delete curr->thePlayer;
	curr = curr->next;
	delete curr->prev;
      }
    }
  }
}

int HockeyList :: load (istream &infile){

  char name[MAXNAMELEN+1];
  char team;
  char position;
  int goals;
  int assists;
  int goalsAgainst;
  char junk;
  int count = 0;
  int toTeam;
  
  ListPtr newPlayer;

  infile >> team;
  while(!infile.eof()){
    count ++;

    infile >> position >> goals >> assists >> goalsAgainst;
    infile.get(junk);
    infile.getline(name, MAXNAMELEN+1, '\n');
    newPlayer = createNode(name, position, goals, assists, goalsAgainst);
    toTeam = findTeamNumber(team);
    link(newPlayer, toTeam);
    
    infile >> team;
  }
  
  return count;
}

void HockeyList :: write (ostream &out) const{

  ListPtr curr;
  
  for(int i = 0; i < NUMTEAMS; i++){
    if(head[i].next != &tail[i]){
      curr = head[i].next;
      while(curr != &tail[i]){

	out << TEAMCHARS[i] << " "
	    << curr->thePlayer->position << " "
	    << curr->thePlayer->goals <<  " "
	    << curr->thePlayer->assists << " "
	    << curr->thePlayer->goalsAgainst << " "
	    << curr->thePlayer->name << '\n';
	
	curr = curr->next;
      }
    }
  }
}

void HockeyList :: display (ostream &out) const{

  ListPtr item;
  int position = 0;
  bool found;
  int team;
  
  search(1, item, team, found); 
  if(!found){    
    out << "*******************************************************" << endl
	<< endl
	<< "Empty  -- no players on the List" << endl
	<< endl
	<< "*******************************************************" << endl;
  }else{
    for(int teamCounter = 0; teamCounter < NUMTEAMS; teamCounter++){
      displayTeam(teamCounter, position, out);
    }
  }
}


bool HockeyList :: move (int position){

  ListPtr item;
  int playersTeam;
  bool found;
  bool moved = false;
  
  search(1, item, playersTeam, found);
  if(found){
    search(position, item, playersTeam, found);
    if(found){
      if(playersTeam != INJURY_LIST_POSITION){
	unlink(item);
	link(item, INJURY_LIST_POSITION);
	moved = true;
      }
    }
  }

  return moved;
}

bool HockeyList :: activate (int position, char team){

  ListPtr item;
  int newTeam;
  int playersTeam;
  bool found;
  bool activated = false;
  
  search(1, item, playersTeam, found);
  if(found){
    search(position, item, playersTeam, found);
    if(found){
      if(playersTeam == INJURY_LIST_POSITION){ 
	newTeam = findTeamNumber(team);
	unlink(item);
	link(item, newTeam);
	activated = true;
      }
    }
  }

  return activated;
}

bool HockeyList :: update (int position, int goals, int assists, int goalsAgainst){

  ListPtr player;
  int playersTeam;
  bool found;
  bool updated = false;

 
  search(1, player, playersTeam, found);
  if(found){
    search(position, player, playersTeam, found);
    if(found){
      if(playersTeam != INJURY_LIST_POSITION){
	player->thePlayer->goals += goals;
	player->thePlayer->assists += assists;
	if(player->thePlayer->position == GOAL){
	  player->thePlayer->goalsAgainst += goalsAgainst;
	}
	unlink(player);
	link(player, playersTeam); 
	updated = true;
      }
    }
  }
  

  return updated;
}

void HockeyList :: lookup (int position, PlayerNode &player, bool &found) const{

  ListPtr item;
  int team;
  
  search(position, item, team, found);
  if(found){
    player = *(item->thePlayer);
  }
}

char HockeyList :: getTeam (int position) const{

  ListPtr item;
  int playersTeam;
  char team;
  bool found;
  
  search(position, item, playersTeam, found);
  if(found){
    if(playersTeam == 0){
      team = TEAMCHARS[0];
    }else if(playersTeam == 1){
      team = TEAMCHARS[1];
    }else if(playersTeam == 2){
      team = TEAMCHARS[2];
    }else if(playersTeam == 3){
      team = TEAMCHARS[3];
    }
  }

  return team;
}



// PRIVATE FUNCTIONS


int HockeyList :: findTeamNumber (char teamLetter){

  int team;
  
  if(teamLetter == TEAMCHARS[0]){
    team = 0;
  }else if(teamLetter == TEAMCHARS[1]){
    team = 1;
  }else if(teamLetter == TEAMCHARS[2]){
    team = 2;
  }else if(teamLetter== TEAMCHARS[3]){
    team = 3;
  }
  
  return team;
}

void HockeyList :: search (int pos, ListPtr &item, int &team, bool &found) const{

  ListPtr node;
  int searchIndex = 1;
  found = false;

  if(pos >= 1){
    for(int i = 0; i < NUMTEAMS; i++){
      node = head[i].next;
      while(node != &tail[i] && !found){
	if(searchIndex == pos){
	  found = true;
	  item = node;
	  team = i;
	}else{
	  node = node->next;
	  searchIndex ++;
	}
      }
    }
  }
}

HockeyList :: ListPtr HockeyList :: createNode (const char name[], char position, int goals, int assists, int goalsAgainst) const{
  
  ListPtr newNode = new ListNode;
  newNode->thePlayer = new PlayerNode;

  for(int i=0; i<MAXNAMELEN; i++){
    newNode->thePlayer->name[i] = name[i];
  }
  newNode->thePlayer->position = position;
  newNode->thePlayer->goals = goals;
  newNode->thePlayer->assists = assists;
  newNode->thePlayer->goalsAgainst = goalsAgainst;

  return newNode;
}

void HockeyList :: link(ListPtr item, int team){

  tail[team].prev->next = item;
  item->prev = tail[team].prev;
  item->next = &tail[team];
  tail[team].prev = item;
  
}

void HockeyList :: unlink (ListPtr item){

  item->prev->next = item->next;
  item->next->prev = item->prev;
  item->next = NULL;
  item->prev = NULL;
}

void HockeyList :: displayTeam (int team, int &position, ostream &out) const{

  ListPtr curr;
  
  if(head[team].next != &tail[team]){
    
    curr = head[team].next; 

    out << endl
	<< endl
	<< TEAMS[team]
	<< endl
	<< endl;

    while(curr != &tail[team]){

      position ++;

      out << position << left << setw(5)  << ":"
	  << setw(NAMEWIDTH) << curr->thePlayer->name
	  << right << setw(GOALWIDTH)
	  << curr->thePlayer->goals << " goals"
	  << setw(ASSISTWIDTH) << curr->thePlayer->assists << " assists";
      
      if(curr->thePlayer->position == GOAL){
	out << setw(ASSISTWIDTH) << curr->thePlayer->goalsAgainst
	    << " goals against"
	    << endl;
      }else{
	out << endl;
      }
    
      curr = curr->next;
    }
  }
}
