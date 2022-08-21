#include "teamList.h"
#include "ioutil.h"
#include "iomanip"



/*
  Function:   createPlayer

  Purpose:    creates a player and set it's data to the passed input

  Input:      player's name(c string), team(char), position(char),
              goals(int), assists(int), goalsAgainst(int)
  
  Output:     updated player pointer, which contains player's data.

  Return:     a player pointer node, which contains the players data.

  Details:    this function creates a player pointer node and sets it's data to
              the passed inputs, and then returns a the player pointer node.

 */
PlayerPtr createPlayer(const char name[], char team, char position,
		       int goals, int assists, int goalsAgainst){

  PlayerPtr player = NULL;

  

  player = new PlayerNode;

  for(int i = 0; name[i] != '\0'; i++){
    player->name[i] = name[i];
  }
  
  player->team = team;
  player->position = position;
  player->goals = goals;
  player->assists = assists;
  player->goalsAgainst = goalsAgainst;
  
  player->next= NULL;
  
  return player;
}


/*
  Function:   displayTeams

  Purpose:    this funciton displays all the teams in a linked list
              containing players, with each player in their respective
	      teams.
  
  Input:      a pointer to head of the linked list, and an output stream.

  Ouput:      a visual representation of the of linked list, displaying each
              team, and it's players, with their name, goals, assists and
	      goals against( if they are a goal tender);

  Return:     doesn't return anything.

  Details:    this funcitons goes through the linked list uisng the head
              of the linked, displaying each team's players, their full name,
	      goals, assists and goal against using the passed ostream.
 */
void displayTeams(PlayerPtr head, ostream &out){

  int num = 0; // player numbering
  PlayerPtr curr = head; //current pointer
  int j = 0; //team numbering


  cout << endl;
  cout << endl;
  cout << "************************************************************";
  if(curr->team == TEAMCHARS[j]){
    cout << endl;
    cout << endl;
    cout << TEAMS[j] << endl;
    cout << endl;
  }
  while(curr != NULL){

    if(curr->team == TEAMCHARS[j]){
      num++;
      cout << num << ":  ";
      
      //name
      cout << right << setw(10);
      for(int i = 0; curr->name[i] != '\0'; i++){
	cout << curr->name[i];
      }

      //goals
      cout << setw(8)<< curr->goals << " goals";
      cout << setw(8) << curr->assists << " assists";

      //ga
      if(curr->position == GOAL){
	cout << setw(8) << curr->goalsAgainst;
	cout << " goals against"<< endl;
      }else{
	cout << endl;
      }

      curr = curr->next;
    }else{
      j++;
      if(curr->team == TEAMCHARS[j]){
	cout << endl;
	cout << endl;
	cout << TEAMS[j] << endl;
	cout << endl;
      }
    }
  }

  cout << endl;
  cout << endl;
  cout << "************************************************************";
  cout << endl;
  cout << endl;
  
  return;
}

/*
  Function:   search

  Purpsoe:    this function searches for a targeted node in a linked list.

  Input:      head of linked list, targetNumber, playerpointer, bool found
  
  Output:     a bool indicating if target was found, a playerpointer to the
              target.

  Return:     void

  Details:    this functions recieves the target number of the node in the linked
              list, searches and searches for it. if found, the found bool will
	      be set to true and playerpointer will be pointing to target, else
	      found will be set to false and player pointer will be set to NULL.
*/
void search(PlayerPtr head, int itemNumber, PlayerPtr &player, bool &found){

  PlayerPtr curr = head;
  found = true;
  int count = 1;
  
  if(itemNumber > 0){
    while(count < itemNumber){
      if(curr->next != NULL){
	count++;
	curr = curr->next;
      }else{
	player = NULL;
	found = false;
      }
    }

    player = curr;
  }
  
  return;
}


/*
Function:   removePlayer

Purpose:    removes a node from the linked list.

Input:      head of the linked list, pointer to target to be removed.

Output:     updated linked list with target removed.

Return:     void.

Details:    this function recieves the head of a linked list, a pointer 
            pointitng to a target.then it searches for the target in the linked
	    list, and removes it but the pointer to target will keep pointing
	    the to removed node. if the target is the first node, the second node
	    will be set to head and if the target is the last node, the second to
	    last target will be set to NULL
 */

void removePlayer(PlayerPtr &head, PlayerPtr player){

  PlayerPtr curr = head;
  PlayerPtr pred = NULL;
  int i = 0;
  bool match = false;

  if(head != NULL){
    while(player->name[i] != '\0'){
      if(player->name[i] == curr->name[i]){
	i++;
      }else{
	pred = curr;
	curr = curr->next;
	i = 0;
      }
    }

    if(pred == NULL){
      pred = head;
      head = head->next;
      player = pred;
    }else{
      if(curr->next == NULL){
	player = curr;
	pred->next = NULL;
      }else{
	player = curr;
	pred->next = curr->next;
      }
    }
  }
  
     
  
  
  return;
  
}


/*
  Function:   containsActivePlayers
  
  Purpsoe:    searches for at least one active player in linked list.

  Input:      head of linked list.

  Output:     nothing

  Return:     returns a boolean, true if found at least one active player
              false if found no active players.

  Details:    this function searches for the linked list for if there are any
              active players and return a boolean true or false
	      indicating if found or not.
*/
bool containsActivePlayers(PlayerPtr head){

  bool value = false;
  
  PlayerPtr curr = head;

  while(curr != NULL && value == false){
    if(curr->team != TEAMCHARS[3]){
      value = true;
    }else{
      curr = curr->next;
    }
  }
  
  return value;
}


/*
  Purpose:    This function destroys the allocated list in memory.
  
  Input:      Head of linked list.

  Ouput:      Empty linked list.

  Return:     doesn't return anything.

  Details:    This function walks through the list, deleting eveery node.
              Then finally deletes head.

*/
void destroyList(PlayerPtr &head){

  PlayerPtr curr = head;
  PlayerPtr next = NULL;

  if(head != NULL){
    while(curr != NULL){
      next = curr->next;
      delete curr;
      curr = next;
    }
  }
  
  
  return;
}

/*
  Function:    InsertPlayer

  Purpose:     This function insert a given node(player), to the allocated
               team.

  Input:       The head ptr of the linked list, the ptr that points to
               the player to be moved.

  Ouput:       Updated linked list, with the player in desired team  location.

  Return:      doesn't return anything.

  Details:     This function inserts playrs to thier various teams.
               It is used by the activate player funcition in teams.cpp.
	       it recieves the head of the node and the player to be moved.
	       before this function is called, the player's team has already been
	       changed and this function just inserts the player's node in the
	       right position of the linked list
*/
void insertPlayer(PlayerPtr &head, PlayerPtr player){


  PlayerPtr curr = head;
  PlayerPtr pred = NULL;
  
  char toTeam = player->team;

  
  if(head != NULL){
    if(toTeam == TEAMCHARS[0]){ //case of inserting the player to team CANADA
      if(curr->team != TEAMCHARS[1]
	 && curr->team != TEAMCHARS[2]
	 && curr->team != TEAMCHARS[3]){ //if team has a player
	while(curr->team == toTeam){
	  pred = curr;
	  curr = curr->next;
	}
	pred->next = player;
	if(curr != NULL){
	  player->next = curr;
        }else{
	  player = NULL;
	}
      }else{                             //if team doesn't have a player
	pred = head;
	head = player;
	player->next = pred;
      }
    }else if(toTeam == TEAMCHARS[1]){ //case of inseting the player to tean FINLAND
      if(curr->team != TEAMCHARS[3]){ //if all the teams are not empty
	while(curr->team != TEAMCHARS[1] && curr->team != TEAMCHARS[3]){
	  pred = curr;
	  curr = curr->next;
	}
	if(curr->team == TEAMCHARS[1]){ //if the team moveing to has a player
	  while(curr->team == toTeam){
	    pred = curr;
	    curr = curr->next;
	  }
	  pred->next = player;
	  if(curr != NULL){
	    player->next = curr;
	  }else{
	    player = NULL;
	  }
	}else{                          //if the team moving to doesn't have a player
	  pred->next = player;
	  if(curr != NULL){
	    player->next = curr;
	  }else{
	    player = NULL;
	  }
	}
      }else{                    //if all the teams are empty
	pred = head;
	head = player;
	player->next = pred;
      }
    }else if(toTeam == TEAMCHARS[2]){
      //case of insertin the player to team USA
      if(curr->team != TEAMCHARS[3]){  //if all the teams are not empty
	while(curr->team == TEAMCHARS[0]){ 
	  pred = curr;
	  curr = curr->next;
	}
	while(curr->team != TEAMCHARS[1]){ 
	  pred = curr;
	  curr = curr->next;
	}
	while(curr->team != TEAMCHARS[2] && curr->team != TEAMCHARS[3]){ 
	  pred = curr;
	  curr = curr->next;
	}
	pred->next = player;
	if(curr != NULL){
	  player->next = curr;
        }else{
	  player = NULL;
	}
      }else{                              //if all the teams are empty
	pred = head;
	head = player;
	player->next = pred;
      }
    }else{              //moving to injury list
      while(curr != NULL){
	pred = curr;
	curr = curr->next;
      }
      pred->next = player;
      player->next = NULL;
    }
  }
    
  
  return;
}

