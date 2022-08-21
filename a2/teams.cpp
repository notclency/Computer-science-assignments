#include "teamList.h"
#include "ioutil.h"
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

/*
 Name:                  Clency Tangie Tabe
 Email:                 ctabe297@mtroyal.ca
 course:                COMP 1633, 001
 Assisgnment:           Assignment 2
 Due date:              February 22, 2022
 Instracutor name:      Paul Pospisil
 File name:             teams.cpp, teamList.cpp
 

 Purpose:               Read data from a file and create linked lists.
                        Also able to modify specific data in the linked
                        list. finally writes the data from the the
			linked list into a created file.

 Details:               Read data from a file and create linked lists.
                        Also able to modify specific data in the linked
                        list. finally writes the data from the the
			linked list into a created file. if the file is empty,
			no modifying choices/options will be able to be done,
			as there is no data to modify. This file(teams.cpp)
			uses functions from another file(teamList.cpp) to be 
			able to modify data. TeamList.cpp has a header file
			(TeamList.h) where all its function declarations are
			stored. All inputs are error handled by a
			file(ioutil.cpp) which has a header file(ioutil.h).
			Thus teams.cpp calls both "ioutil.h" and "TeamList.h".

 Assumptions and
 Limitations:           None.

 Knwon bugs:            None.

*/
void menu();

int load(ifstream &infile, PlayerPtr &head);

void write(ofstream &outfile, PlayerPtr head);

void toInjury(PlayerPtr &head, int playercount, bool interactive);

void updatePlayer(PlayerPtr &head, int playercount, bool interactive);

void showTopScorer(PlayerPtr &head);

void activatePlayer(PlayerPtr &head, int playercount, bool interactive);


int main(){

  PlayerPtr head = NULL;
  PlayerPtr player = NULL;
  
  ifstream src;
  ofstream dst;
  
  bool ai, eof;

  int playercount;
  
  char choice[MINNAMELEN],
    filename[MAXNAMELEN], outfile[MAXNAMELEN];

  bool interactive;               //constant interactive boolean

  bool emptyfile = false;
  bool opened;
  
  ai = readBool("Do you want to run interactively (y/n)? ",eof);

  if(ai){
    interactive = true;
  }else{
    interactive = false;
  }
  
  
  if(eof){
    cout << "** EOF entered - program terminating ****" << endl;
  }else{
    if(interactive){
      readString("Enter name of input file: ",
		 filename,MAXNAMELEN,0,eof);
    }else{
      readString("",
		 filename,MAXNAMELEN,0,eof);
    }
    
    if(eof){
      cout << "** EOF entered - program terminating ****" << endl;
    }else{
      if(filename[0] == '\0'){
	emptyfile = true;
      }else{
	src.open(filename);
	opened = true;
	if(src.fail()){
	  cout << "*** ERROR opening input file  - "
	       << "program terminating ***" << endl;
	}
      }
      if(opened || filename[0] == '\0'){
	//LOAD
	if(!emptyfile){
	  playercount = load(src, head);
	}
	
	if(interactive){
	  menu();
	  readString("Your choice: ",
		     choice,MINNAMELEN,MINNAMELEN,eof);
	}else{
	  readString("",
		     choice,MINNAMELEN,MINNAMELEN,eof);
	}
	
	while(choice[0] != 'q' && choice[0] != 'Q'){
	  if(choice[0] == 'd' || choice[0] == 'D'){
	    //display teams
	    if(playercount >= 1 || !emptyfile){
	      displayTeams(head, cout);
	    }else{
	      cout << endl;
	      cout << "************************************************************";
	      cout << endl;
	      cout << endl;
	      cout << "Empty  -- no players on the List" << endl;
	      cout << endl;
	      cout << "************************************************************";
	      cout << endl;
	    }
	  }else if(choice[0] == 'm' || choice[0] == 'M'){
	    //moveplayer to injury list
	
	    if(playercount >= 1 || !emptyfile){
	      toInjury(head, playercount, interactive);
	    }else{
	      cout << endl;
	      cout << "************************************************************";
	      cout << endl;
	      cout << endl;
	      cout << "Empty List so no one to move" << endl;
	      cout << endl;
	      cout << "************************************************************";
	      cout << endl;
	    }
	  }else if(choice[0] == 'a' || choice[0] == 'A'){
	    //activate player
	
	    if(playercount >= 1 || !emptyfile){
	      activatePlayer(head, playercount, interactive);
	    }else{
	      cout << endl;
	      cout << "************************************************************";
	      cout << endl;
	      cout << endl;
	      cout << "Empty List so no one to activate" << endl;
	      cout << endl;
	      cout << "************************************************************";
	      cout << endl;
	    }
	  }else if(choice[0] == 'u' || choice[0] == 'U'){
	    //update player
	    if(playercount >= 1 || !emptyfile){
	      updatePlayer(head, playercount, interactive);
	    }else{
	      cout << endl;
	      cout << "************************************************************";
	      cout << endl;
	      cout << endl;
	      cout << "Empty List so no one to update" << endl;
	      cout << endl;
	      cout << "************************************************************";
	      cout << endl;
	    }
	  }else if(choice[0] == 's' || choice[0] == 'S'){
	    //show top scorer
	    
	    if(playercount >= 1  || !emptyfile){
	      showTopScorer(head);
	    }else{
	      cout << endl;
	      cout << "************************************************************";
	      
	      cout << endl;
	      cout << endl;
	      cout << "There is no top scorer as there are no active players" << endl;
	      cout << endl;
	      cout << "************************************************************";
	      cout << endl;
	    }
	  }else{
	    cout << "**** ERROR - Invalid menu choice - try again ****" << endl;
	  }
	  
	  if(interactive){
	    menu();
	    readString("Your choice: ",
		       choice,MINNAMELEN,MINNAMELEN,eof);
	  }else{
	    readString("",
		       choice,MINNAMELEN,MINNAMELEN,eof);
	  }
	}
	//exit
	if(!interactive){
	  readString("",outfile,MAXNAMELEN,MINNAMELEN,eof);
	  while(eof){
	    cout << endl;
	    readString("",outfile,MAXNAMELEN,MINNAMELEN,eof);
	  }
	}else{
	  readString("Enter name of output file: ",outfile,MAXNAMELEN,MINNAMELEN,eof);
	  while(eof){
	    cout << endl;
	    readString("Enter name of output file: ",outfile,MAXNAMELEN,MINNAMELEN,eof);
	  }
	}
	dst.open(outfile);
	if(dst.fail()){
	  cout << "**** Couldn't open file - terminamting program ****" << endl;
	}else{
	  write(dst, head);
	  dst.close();
	  src.close();
	  destroyList(head);
	  cout << endl;
	  cout << "Player list saved to ";
	  cout << "file and program exiting." << endl;
	}
      }
    }
  }
  
  
  return 0;
}


/*
Function:   menu

Purpose:    display menu option, when a menu choice is
            required

Input:      none

Output:     none

Return:     none

Details:    this function displays the menu option when a menu choice is
            required.
*/
void menu(){
  cout << endl;
  cout << "Olympic Teams List Manager:" << endl;
  cout << endl;
  cout << "d) display" << endl;
  cout << "m) move a player to the injury reserve" << endl;
  cout << "a) activeate a player from the the injury reserve" << endl;
  cout << "u) update player points" << endl;
  cout << "s) show top scorer" << endl;
  cout << endl;
  cout << "q) quit "<< endl;
  cout << endl;
  cout << endl;
  
  
  return;
}

/*
Function:   load

Purpose:    creates a linked list from data from a file.

Input:      ifstream and head of the linked list.

Ouput:      the created linked list

Return:     returns the numbers of nodes in the linked list

Details:    this functions receives an open file and the head of linked
            list, reads data from the open file ,creates nodes for the linked
	    list, and sets the files data as data for the nodes of linked list.

*/
int load(ifstream &infile, PlayerPtr &head){

  
  PlayerPtr newcurr = NULL;
  int count = 0;

  
  //player information
  char name[MAXNAMELEN+1];
  char team;
  char position;
  int goals;
  int assists;
  int goalsAgainst;
  
  //checks for country
  infile >> team;
	
  if(team == TEAMCHARS[0] || team == TEAMCHARS[1]
     || team == TEAMCHARS[2] || team == TEAMCHARS[3] ){

    count++;
    //checks position
    infile >> position;
      
    //goals
    infile >> goals;
    infile >> assists;
    infile >> goalsAgainst;
      
    //player name :(
    infile.getline(name, MAXNAMELEN, '\n');

    head = createPlayer(name, team, position,goals,
			assists, goalsAgainst);
    head->next = NULL;
    newcurr = head;
    

    //team
    infile >> team;
    while(!infile.eof()){
      
      //checks position
      infile >> position;
      
      //goals
      infile >> goals;
      infile >> assists;
      infile >> goalsAgainst;
      
      //player name :(
      infile.getline(name, MAXNAMELEN, '\n');

      newcurr->next = createPlayer(name, team, position,goals,
				   assists, goalsAgainst);
      newcurr = newcurr->next;

      
      //team
      infile >> team;
      count++;
    }

    newcurr = NULL;
  }
  
  return count;
}

/*
Function:   write

Purpose:    writes data from the linked list to an open file.

Input:      ofstream, head of the linked list.

Output:     a file containing the written data from the linked list.

Return:     doesn't return any thing.

Details:    this funciton reads data from the linked list node by node,
            starting from the first node and writes the data into an open
	    file in that order.
*/
void write(ofstream &outfile, PlayerPtr head){

  int noGoal = 0;
  PlayerPtr curr = head;
  int i = 1;
  
  while(curr != NULL){
    outfile << (curr->team);
    outfile << (" ");
    outfile << (curr->position);
    outfile << (" ");
    outfile << (curr->goals);
    outfile << (" ");
    outfile << (curr->assists);
    outfile << (" ");
    if(curr->position == GOAL){
      outfile << (curr->goalsAgainst);
      outfile << (" ");
    }else{
      outfile << (noGoal);
      outfile << (" ");
    }
    outfile << curr->name[i];
    while(curr->name[i] != '\0'){
      i++;
      if(curr->name[i] != '\0'){
	outfile << curr->name[i];
      }
    }
    outfile << '\n';
    curr = curr->next;
    i = 1;
  }
  
  
  
  return;
}


/*
Function:   toInjury

Purpose:    moves a player's node to the injury section(injury team)

Input:      a NULL player pointer, the head of the linked list,
            playercount, interactive.

Output:     an updated linked list with, with targeted player moved to the
            injury list.

Return:     Void.

Details:    this function moves a targeted player to the injury list section
            of the linked list. if targeted player is already on the injury
            list, a message indicating will be outputed, else the player
            will be transfered to the injury list.
 */
void toInjury(PlayerPtr &head, int playercount,
	      bool interactive){

  PlayerPtr player = NULL;
  int numchoice;
  bool found, move,  eof;
  char prompt[50] = "";
  
  cout << endl;
  cout << "************************************************************" << endl;
  cout << endl;

  if(!interactive){
    numchoice = readInt("", eof);
    while(eof){	      
      cout << endl;
      cout << "";
      cout << "**** EOF ignore - to abort the program type Ctrl-c ****" << endl;;
      numchoice = readInt("", eof);
    }
  }else{
    numchoice = readInt("Enter Player Number: ", eof);
    while(eof){	      
      cout << endl;
      cout << "**** EOF ignored - to abort the program";
      cout << " type Ctrl-c ****" << endl;;
      numchoice = readInt("Enter Player Number: ", eof);
    }
  }
  while((numchoice > playercount) || (numchoice < 1)){	      
    cout << "**** Player number must be between 1 and ";
    cout << playercount <<  " ****" << endl;
    if(!interactive){
      numchoice = readInt("", eof);
    }else{
      numchoice = readInt("Enter Player Number: ", eof);
    }
  }
  search(head, numchoice, player, found);
  if(found){
    if(player->team != TEAMCHARS[3]){
      if(!interactive){
	move = readBool("",eof);
      }else{
	strcat(prompt,"Move");
	strcat(prompt, player->name);
	strcat(prompt, " to injury reserve (y/n)? ");
	move = readBool(prompt, eof);
      }
      while(eof){
	cout << endl;
	cout << "**** EOF ignored - to abort the pogram";
	cout << " type Ctrl-c ****" << endl;
	if(!interactive){
	  move = readBool("",eof);
	}else{
	  move = readBool(prompt, eof);
	}
      }
      if(move){
	removePlayer(head, player);
	player->team = TEAMCHARS[3];
	insertPlayer(head, player);
	cout << "Moved";
	cout << player->name;
	cout << " to injury list" << endl;
      }else{
	cout << "Move operation canceled" << endl;
      }
    }else{
      cout << "****";
      cout << player->name;
      cout << " is already on the injury list ****" << endl;;
    }  
  }


  cout << endl;
  cout << "************************************************************" << endl;

  return;
}

/*
Function:   UpdatePlayer

Purpose:    Updates player points for a targeted player.

Input:      head of linked list, playercount, interactive.

Ouput:      updateted linked list, with updated player points.

Return:     void.

Details:    this functions updates the player points of an active player that is 
            on the list. updating goals against will only be asked if
	    the player's position is goal tender(g). Updating goals and assists
	    will always be asked.
 */
void updatePlayer(PlayerPtr &head,
		  int playercount, bool interactive){

  PlayerPtr player = NULL;
  int numchoice, addGoals, addAssists, addAgainst;
  bool found, eof, activate; 

  char prompt[50] = "";
  
  //Update player points
  cout << endl;
  cout << "************************************************************" << endl;
  cout << endl;
  if(interactive){
    numchoice = readInt("Enter Player Number: ", eof);
    while((numchoice > playercount) || (numchoice < 1)){
      cout << "**** Player number must be between 1 and ";
      cout << playercount <<  " ****" << endl;
      numchoice = readInt("Enter Player Number: ", eof);
    }
  }else{
    numchoice = readInt("", eof);
    while((numchoice > playercount) || (numchoice < 1)){
      cout << "**** Player number must be between 1 and ";
      cout << playercount <<  " ****" << endl;
      numchoice = readInt("", eof);
    } 
  }
  while(eof){
    cout << endl << "**** EOF ignored - to abort the";
    cout << " program type Ctrl-c ****" << endl;
    if(!interactive){
      numchoice = readInt("Enter Player Number: ", eof);
    }else{
      numchoice = readInt("", eof);
    }
  }
  search(head, numchoice, player, found);
  if(found){
    if(player->team != TEAMCHARS[3]){

      if(interactive){
	cout << "Update player points for";
        cout << player->name;
	activate = readBool(" (y/n)? ",eof);
      }else{
	activate = readBool("",eof);
      }
      if(activate){
	if(interactive){
	  addGoals = readInt("goals to add: ", eof);
	  while(addGoals < 0){
	    cout << "**** All player points must be greater";
	    cout << " than or equal to 0 ****" << endl;
	    addGoals = readInt("goals to add: ", eof);
	  }

	  addAssists = readInt("assists to add: ", eof);
	  while(addAssists < 0){
	    cout << "**** All player points must be greater";
	    cout << " than or equal to 0 ****" << endl;
	    addAssists = readInt("assists to add: ", eof);
	  }
	  if(player->position == GOAL){
	    addAgainst = readInt("goals against to add: ", eof);
	    while(addAgainst < 0){
	      cout << "**** All player points must be greater";
	      cout << " than or equal to 0 ****" << endl;
	      addAgainst = readInt("goal against to add: ", eof);
	    }
	  }
	}else{
	  addGoals = readInt("", eof);
	  while(addGoals < 0){
	    cout << "**** All player points must be greater";
	    cout << " than or equal to 0 ****" << endl;
	    addGoals = readInt("", eof);
	  }

	  addAssists = readInt("", eof);
	  while(addAssists < 0){
	    cout << "**** All player points must be greater";
	    cout << " than or equal to 0 ****" << endl;
	    addAssists = readInt("", eof);
	  }
	  if(player->position == GOAL){
	    addAgainst = readInt("", eof);
	    while(addAgainst < 0){
	      cout << "**** All player points must be greater";
	      cout << " than or equal to 0 ****" << endl;
	      addAgainst = readInt("", eof);
	    }
	  }
	}
		  
	player->goals = player->goals + addGoals;
	player->assists = player->assists + addAssists;
	player->goalsAgainst = player->goalsAgainst + addAgainst; 
	for(int i = 1; player->name[i] != '\0'; i++){
	  cout << player->name[i];
	}
	cout << " updated" << endl;
      }else{
	cout << "Update operation cancelled" << endl;
      }
    }else{
      cout << "**** ";
      cout << player->name;
      cout << " is on injury reserve so can't be updated ****" << endl;
    }
  }
  cout << endl;
  cout << "************************************************************" << endl;

  return;
}

/*
  Function:   showTopScorer
  
  Purpose:    displays non goal tender topscorer.

  Input:      head of the linked list,PlayerPtr Player ,variable maxpoints,
              that will be se to the player with the max points and a bool

  Output:     maxpoints, ptr to player with maxpoints
 
  Return:     void.

  Details:    The function searches the linked list for a player who's
              not a goal tender and has the number of goals and assists
              combined, set the combined points to the varaible maxpoints
              and outputs the players node.
*/
void showTopScorer(PlayerPtr &head){

  cout << endl;
  cout << "************************************************************" << endl;
  cout << endl;
  bool oneactive;
  oneactive = containsActivePlayers(head);
  if(oneactive){
    
    PlayerPtr curr = head;
    PlayerPtr player = NULL;
    int maxpoints;
    
    while(curr != NULL){
      if(curr->position != GOAL && curr->team != TEAMCHARS[3]){
	if((curr->goals + curr->assists) > maxpoints){
	  maxpoints = curr->goals + curr->assists;
	  player = curr;
	  curr = curr->next;
	}else{
	  curr = curr->next;
	}
      }else{
	curr = curr->next;
      }
    }

    if(player == NULL){
      cout << "There are no active players who are non goal tenders" << endl;
    }else{
      
      cout << "Top Scorer is:" << endl;
      cout << endl;
      for(int i = 1; player->name[i] != '\0'; i++){
	cout << player->name[i];
      }
      cout << " with " << maxpoints << " total points" << endl; 
    }
  }else{
    cout << "There is no top scorer as there are no active players" << endl;
  }
  cout << endl;
  cout << "************************************************************" << endl;

  return;
}

/*
Function:   activatePlayer

Purpose:    activates a player who's injury reserve, to a selected team

Input:      head of linked list, playercount, interactive

Output:     updated linked list, with recently activated player in
            selected team

Return:     void.

Details:    this functions activates a player who's on the list and is in
            in the injury team to a selected team. if targeted player is
            already on the injury list, an indicating message will be outputed.
 */
void activatePlayer(PlayerPtr &head, int playercount, bool interactive){


  PlayerPtr player = NULL;
  int numchoice;
  bool found, activate, eof;
  char newteam[MINNAMELEN], prompt[50] = "";
  
  cout << endl;
  cout << "************************************************************" << endl;
  cout << endl;
  if(interactive){
    numchoice = readInt("Enter Player Number: ", eof);
    while(eof){	      
      cout << endl;
      cout << "**** EOF ignored - to abort the";
      cout << " program type Ctrl-c ****" << endl;;
      numchoice = readInt("Enter Player Number: ", eof);
    }
  }else{
    numchoice = readInt("", eof);
    while(eof){	      
      cout << endl;
      cout << "**** EOF ignored - to abort the";
      cout << " program type Ctrl-c ****" << endl;;
      numchoice = readInt("", eof);
    }
  }
  while((numchoice > playercount) || (numchoice < 1)){
	      
    cout << "**** Player number must be between 1 and ";
    cout << playercount <<  " ****" << endl;
    if(interactive){
      numchoice = readInt("Enter Player Number: ", eof);
    }else{
      numchoice = readInt("", eof);
    }
  }
  search(head, numchoice, player, found);
  if(found){
    if(player->team == TEAMCHARS[3]){
      if(interactive){
	strcat(prompt, "Activate");
	strcat(prompt, player->name);
	strcat(prompt, " (y/n)? ");
	activate = readBool(prompt, eof);
	if(activate){
	  readString("Enter team (C/F/U): ",
		     newteam, MINNAMELEN,MINNAMELEN, eof);
	  while((newteam[0] != TEAMCHARS[0]) &&
		(newteam[0] != TEAMCHARS[1])
		&& (newteam[0] != TEAMCHARS[2])){
	  
	    cout << "**** Team must be one of C(anada),";
	    cout << "F(inland) or U(SA) ****" << endl;
	    readString("Enter team (C/F/U): ", newteam,
		       MINNAMELEN,MINNAMELEN, eof);
	  }
	  removePlayer(head, player);
	  player->team = newteam[0];
	  insertPlayer(head, player);
	  cout << "Activated";
	  cout << player->name;
	  cout << " to team " << newteam[0] << endl;
	}else{
	  cout << "Activate operation canceled" << endl;
	}
      }else{
	activate = readBool("",eof);
	if(activate){
	  readString("",
		     newteam, MINNAMELEN,MINNAMELEN, eof);
	  while((newteam[0] != TEAMCHARS[0]) &&
		(newteam[0] != TEAMCHARS[1])
		&& (newteam[0] != TEAMCHARS[2])){
	  
	    cout << "**** Team must be one of C(anada),";
	    cout << "F(inland) or U(SA) ****" << endl;
	    readString("", newteam,
		       MINNAMELEN,MINNAMELEN, eof);
	  }
	  removePlayer(head, player);
	  player->team = newteam[0];
	  insertPlayer(head, player);
	  cout << "Activated";
	  cout << player->name;
	  cout << " to team " << newteam[0] << endl;
	}
	else{
	  cout << "Activate operation canceled" << endl;
	}
      }
    }else{
      cout << "****";
      cout << player->name;
      cout << " is an active player ****" << endl;
    }
  }
  cout << endl;
  cout << "************************************************************";

  return;
}
