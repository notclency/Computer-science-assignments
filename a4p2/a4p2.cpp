/**************************************************************
 *                    Olympic Hockey Teams Manager
 *
 * Author:        
 * email address: 
 * Course:        COMP 1633 - 001
 * Assignment:    4 part 2
 * Due Date:      
 * Instructor:    P. Pospisil
 *
 * Filename:     a4p2.cpp
 *
 **************************************************************
 * Purpose: 
 * This application assists a user in building and managing an
 * "Olympic Hockey Teams" list.
 * 
 * Details:
 *
 * Input:
 * Upon starting the user has two options for initializing the 
 * Olympic Team list:
 * 1. read an existing list from an ASCII file (user is prompted
 *    for the input file name)
 * 2. begin with an empty list (user presses ENTER when prompted
 *    for the input file name)
 * Note: option 2 is not really useful because an "add player"
 *    command has not been designed.
 *
 * Format of the Input File:
 * This program does not check for errors in the input file
 * data. The following format is assumed:
 * 1. each line in the input file represents one player and has
 *    the following structure:
 *          character (one of C, F, U or I)
 *          space
 *          character (one of f, d or g)
 *          space
 *          integer   (>= 0)
 *          space
 *          integer   (>= 0)
 *          space
 *          integer   (>= 0)
 *          space
 *          string    (length 1 - 25)
 *          newline
 * 2. the file contains players in order of team: 
 *         all players on team C
 *         followed by all players on team F
 *         followed by all players on team U 
 *         followed by all players on team I
 * 3. there may be zero players on a team
 * 4. an empty file is valid
 *
 * Program Operations:
 * The program is menu-driven, but has been designed to read data from a file
 * using command-line redirection. The user may select from one of the 
 * following seven options for managing the list:
 *     d - display the players under team headings (the player
 *         number, name and goals, assists and if a goaltender goals
 *         against are shown for each entry on the list)
 *     m - move a player from an active team to the injury 
 *         reserve list (the user is asked to confirm the request)
 *     a - activate an existing player from the injury reserve
 *         list to one of the existing teams (the user is asked to confirm 
 *         the request for activate and to input the team, if necessary)
 *     u - modify an existing player's points (the user is
 *         asked to confirm the request for update and, if necessary,
 *         to input the goals to add, the assists to add and, for 
 *         goaltenders, the goals against to add)
 *     s - display the top scoring non-goaltender from among all active players
 *     q - exit the program (the user is prompted for the name
 *         of a file to which the list contents will be written)
 *
 * Error Checking and Data Validation:
 * The following constraints apply:
 *    input file name      = string length 0 to 29 (arbitrary)
 *    output file name     = string length 1 to 29
 *    player team          = one of CANADA ('C' converted to 1),
 *                                  FINLAND ('F' converted to 2),
 *                                  USA ('U' converted to 3)
 *                               or INJURY ('I' converted to 4)
 *    goals to add         = integer >= 0
 *    assists to add       = integer >= 0
 *    goals against to add = integer >= 0
 *
 *    invalid menu option  = one of the seven characters previously stated
 *    player list position = > 0 and < max number of players read
 *
 *    can't move a player on the injury reserve list to the injury reserve list
 *    can't activate an player not on the injury reserve list
 *    can't update a player's statistics if they are on the injury reserve list
 *
 * Assumptions and Limitations:
 *  - player's name can contain spaces so regardless of whether read using get
 *    or getline the newline after the goals against integer must be removed
 *  - for any input the user can enter eof, CTRL-d. If entered for the 
 *    interactive mode query or the input file name query the program will 
 *    terminate; if for the output file name query the user will be forced to
 *    enter a valid name; anywhere else the user will be informed of the eof
 *    input and it will be completely ignored.
 *
 *  - the players are read and will always remain ordered by alphabetical 
 *    country name, excluding the injury reserve list which is always last.
 * 
 *  - the main program will not operate directly on the teams list, but will
 *    always use the provided list operations. 
 *
 **************************************************************/

#include <fstream>
#include <iostream>
#include <cstring>
// 1
//#include "teamList.h"
#include "HockeyList.h"
#include "ioutil.h"
using namespace std;

void showMenu();
//*****************************************************************************
// For doDisplay and doTopScorer it may seem strange or wrong that the
// HockeyList argument is being passed by const reference, but at this time 
// it is required. (it will be explained later in lectures)
//
// For those of you that don't believe this once you have a working version of
// doDisplay copy your directory and in the copy remove the const and & in both
// the prototype and header and try your program!!
//*****************************************************************************
// 2
// void doDisplay (PlayerPtr head);
void doDisplay (const HockeyList &theList);
// 3
// void doMove (PlayerPtr &head, int listSize, bool interactive);
void doMove (HockeyList &theList, int listSize, bool interactive);
// 4
// void doActivate (PlayerPtr &head, int listSize, bool interactive);
void doActivate (HockeyList &theList, int listSize, bool interactive);
// 5
// void doUpdate (PlayerPtr &head, int listSize, bool interactive);
void doUpdate (HockeyList &theList, int listSize, bool interactive);
// 6
// void doTopScorer (PlayerPtr head);
void doTopScorer (const HockeyList &theList);
// 7
// void doQuit (PlayerPtr &head, bool interactive);
void doQuit (HockeyList &theList, bool interactive);

// 8
// int load (istream &infile, PlayerPtr &head);
// void write (ostream& outfile, PlayerPtr head);

int readPlayerNumber (int max, bool interactive);
char readTeam (bool interactive);
int readPoints (const char []);

const char DISPLAY = 'd';
const char MOVE = 'm';
const char ACTIVATE = 'a';
const char UPDATE = 'u';
const char TOPSCORER = 's';
const char QUIT = 'q';

const int FILENAME_LENGTH = 30;

int main ()
{
   char inputFileName[FILENAME_LENGTH];
   ifstream inFile;
   char fakeStr[2], choice;
// 9
//   PlayerPtr OlympicTeamList = NULL;
   HockeyList theList;
   bool eof;
   bool goodToGo = false;
   bool interactive;
   int playersOnList = 0;

   interactive = readBool ("Do you want to run interactively (y/n)?  ", eof);
   if (eof)
   {
     cout<< "**** EOF entered - program terminating ****" << endl;
   }
   else
   {
     if (interactive)
     {
       readString ("Enter name of input file: ", inputFileName,
                   FILENAME_LENGTH, 0, eof);
     }
     else
     {
       cout << endl;
       readString ("", inputFileName, FILENAME_LENGTH, 0, eof);
     }
     if (eof)
     {
       cout<< "**** EOF entered - program terminating ****" << endl;
     }
     else
     {
       if (static_cast<int>(strlen(inputFileName)) == 0)
       {
         goodToGo = true;
       }
       else
       {
         inFile.open(inputFileName);
         if (inFile.fail())
         {
           cout << "**** ERROR opening input file  - program terminating ****"
                << endl;
           goodToGo = false;
         }
         else
         {
// 10
//           playersOnList = load (inFile, OlympicTeamList);
           playersOnList = theList.load(inFile);
           inFile.close();
           goodToGo = true;
         }
       }
       if (goodToGo)
       {
         do
         {
           if (interactive)
           {
             showMenu();
             readString("\nYour Choice:  ",fakeStr, 1, 1, eof);
           }
           else
             readString("",fakeStr, 1, 1, eof);             

           if (eof)
           {
             cout << endl
                  << "**** EOF ignored - to abort the program type Ctrl-c ****"
                  << endl;
           }
           else
           {
             choice = fakeStr[0];
             choice = static_cast <char> (tolower(choice));
             switch (choice)
             {
             case DISPLAY    :
// 11
//               doDisplay (OlympicTeamList);
               doDisplay(theList);
               break;
             case MOVE       :
// 12
//               doMove (OlympicTeamList, playersOnList, interactive);
               doMove (theList, playersOnList, interactive);
               break;
             case ACTIVATE   :
// 13
//               doActivate (OlympicTeamList, playersOnList, interactive);
               doActivate (theList, playersOnList, interactive);
               break;
             case UPDATE     :
// 14
//               doUpdate (OlympicTeamList, playersOnList, interactive);

               doUpdate (theList, playersOnList, interactive);
               break;
             case TOPSCORER  :
// 15
//               doTopScorer (OlympicTeamList);
               doTopScorer (theList);
               break;
             case QUIT       :
// 16
//               doQuit (OlympicTeamList, interactive);
               doQuit (theList, interactive);
               break;
             default         :
               cout << "**** ERROR - Invalid menu choice - try again ****"
                    << endl;
               break;
             }
           }
         } while (choice != QUIT);
       }
     }
   }
   return 0;
}

void showMenu()
{
   cout << endl;
   cout << "Olympic Teams List Manager:" << endl << endl;
   cout << "d) display list" << endl;
   cout << "m) move a player to injury reserve" << endl;
   cout << "a) activate a player from injury reserve" << endl;
   cout << "u) update player points" << endl;
   cout << "s) show top scorer" << endl << endl;
   cout << "q) quit" << endl << endl;
 
   return;
}

// 17
//void doDisplay (PlayerPtr head)
void doDisplay (const HockeyList &theList)
{
// 18
//  displayTeams(head, cout);
  theList.display(cout);
  return;
}

// 19
//void doMove (PlayerPtr &head, int listSize, bool interactive)
void doMove (HockeyList &theList, int listSize, bool interactive)
{
// 20
//   PlayerPtr player;
   PlayerNode player;
   int  playerListNumber;
   bool playerExists;
   char prompt[MAXNAMELEN+32];
   bool confirm,
        eof;

   cout << "************************************************************"
        << endl << endl;
   
   if (listSize == 0)
   {
     cout << "Empty list so no one to move" << endl << endl;
   }
   else
   {
     playerListNumber = readPlayerNumber(listSize, interactive);
// 21
//     search (head, playerListNumber, player, playerExists);
     theList.lookup (playerListNumber, player, playerExists);

     if (!playerExists)
     {
       cout << "**** Player " << playerListNumber
            << " is not on the Olympic Teams list ****"
            << endl << endl;
     }
     else
     {

// 22
//       if (player->team != TEAMCHARS[INJURY_LIST_POSITION])
       if (theList.getTeam(playerListNumber) != TEAMCHARS[INJURY_LIST_POSITION])
       {
         strncpy (prompt, "Move ", strlen("Move ")+1);
// 23
//          strncat (prompt, player->name, MAXNAMELEN+1);
          strncat (prompt, player.name, MAXNAMELEN+1);
         strncat (prompt, " to Injury Reserve (y/n)? ", 
                  strlen(" to Injury Reserve (y/n)? ")+1);
         do
         {
           if (interactive)
             confirm = readBool(prompt, eof);
           else
             confirm = readBool("", eof);
           if (eof)
           {
             cout << endl
                  << "**** EOF ignored - to abort the program type Ctrl-c ****"
                  << endl;
           }
         } while (eof);
      
         if (confirm)
         {
// 24
/*
           removePlayer(head, player);
           player->team = TEAMCHARS[INJURY_LIST_POSITION];
           insertPlayer(head,player);

           cout << "Moved " << player->name << " to injury list" << endl << endl;
*/
           theList.move(playerListNumber);
           cout << "Moved " << player.name << " to injury list" << endl << endl;
         }
         else
         {
           cout << "Move operation cancelled" << endl << endl;
         }
       }
       else
       {
// 25
//         cout << "**** " << player->name << " is already on the injury list ****"
         cout << "**** " << player.name << " is already on the injury list ****"
              << endl << endl;
       }
     }
   }
   cout << "************************************************************"
        << endl << endl;
   
   return;
}

// 26
//void doActivate (PlayerPtr &head, int listSize, bool interactive)
void doActivate (HockeyList &theList, int listSize, bool interactive)
{
// 27
//  PlayerPtr player;
    PlayerNode player;
  int playerListNumber;
  bool playerExists;
  char prompt[MAXNAMELEN+32];
  bool confirm,
    eof;
  char newTeam;
  
  cout << "************************************************************"
       << endl << endl;
  
  if (listSize == 0)
  {
    cout << "Empty list so no one to activate" << endl << endl;
  }
  else
  {
    playerListNumber = readPlayerNumber(listSize, interactive);
// 28
//     search (head, playerListNumber, player, playerExists);
     theList.lookup(playerListNumber, player, playerExists);
    if (!playerExists)
    {
      cout << "**** Player " << playerListNumber 
           << " is not on the Olympic Teams list ****" << endl << endl;
    }
// 29
//    else if (player->team == TEAMCHARS[INJURY_LIST_POSITION])
    else if (theList.getTeam(playerListNumber) == TEAMCHARS[INJURY_LIST_POSITION])
    {
      strncpy (prompt, "Activate ", strlen("Activate ")+1);
// 30
//      strncat (prompt, player->name, MAXNAMELEN+1);
      strncat (prompt, player.name, MAXNAMELEN+1);
      strncat (prompt, " (y/n)? ", strlen(" (y/n)? ")+1);

      do
      {
        if (interactive)
          confirm = readBool (prompt, eof);
        else
          confirm = readBool ("", eof);
        if (eof)
        {
          cout << endl
               << "**** EOF ignored - to abort the program type Ctrl-c ****"
               << endl;
        }
      } while (eof);
      
      if (confirm)
      {
        newTeam = readTeam(interactive);
// 31
/*        removePlayer (head, player);
        player->team = newTeam;
        insertPlayer (head, player);

        cout << "Activated " << player->name << " to team "
*/
        theList.activate(playerListNumber, newTeam);
        cout << "Activated " << player.name << " to team "
             << newTeam << endl << endl;
      }
      else
      {
        cout << "Activate operation cancelled" << endl << endl;
      }
    }
    else
    {
// 32
//      cout << "**** " << player->name << " is already on an active roster ****"
      cout << "**** " << player.name << " is already on an active roster ****"
           << endl << endl;
    }
    
  }
  cout << "************************************************************"
       << endl << endl;
  
  return;
}

// 33
//void doUpdate (PlayerPtr &head, int listSize, bool interactive)
void doUpdate (HockeyList &theList, int listSize, bool interactive)
{
// 34
//  PlayerPtr player;
  PlayerNode player;
  int playerListNumber;
  bool playerExists;
  char prompt[MAXNAMELEN+32];
  bool confirm,
    eof;
  int newgoals;
  int newassists;
  int newgoalsagainst;
  
  cout << "************************************************************"
       << endl << endl;

  if (listSize == 0)
  {
    cout << "Empty list so no one to update" << endl << endl;
  }
  else
  {
    playerListNumber = readPlayerNumber(listSize, interactive);
// 35
//    search (head, playerListNumber, player, playerExists);
     theList.lookup(playerListNumber, player, playerExists);
    if (!playerExists)   // this should NEVER occur
     {
       cout << "**** Player " << playerListNumber 
            << " is not on the Olympic Teams list ****" << endl << endl;
     }
    else
    {
// 36
//       if (player->team != TEAMCHARS[INJURY_LIST_POSITION])
      if (theList.getTeam(playerListNumber) != TEAMCHARS[INJURY_LIST_POSITION])
      {
        strncpy (prompt, "Update points for ", strlen("Update points for ")+1);
// 37
//        strncat (prompt, player->name, MAXNAMELEN+1);
        strncat (prompt, player.name, MAXNAMELEN+1);
        strncat (prompt, " (y/n)? ", strlen(" (y/n)? ")+1);
        do {
          if (interactive)
            confirm = readBool (prompt, eof);
          else
            confirm = readBool ("", eof);
        } while (eof);
        if (confirm)
        {
           if (interactive)
           {
             newgoals = readPoints ("Enter goals to add: ");
             newassists = readPoints ("Enter assists to add: ");
           }
           else
           {
             newgoals = readPoints ("");
             newassists = readPoints ("");
           }
// 38
//           if (player->position == GOAL)
           if (player.position == GOAL)
             if (interactive)
               newgoalsagainst = readPoints ("Enter goals against to add: ");
             else
               newgoalsagainst = readPoints ("");
           else
             newgoalsagainst = 0;
// 39
/*
           player->goals += newgoals;
           player->assists += newassists;
           player->goalsAgainst += newgoalsagainst;
           
           removePlayer(head, player);
           insertPlayer(head, player);

           cout << player->name << " updated" << endl << endl;
*/
           theList.update(playerListNumber, newgoals, newassists,newgoalsagainst);
           cout << player.name << " updated" << endl << endl;

         }
         else
         {
           cout << "Update operation cancelled" << endl << endl;
         }
       }
       else
       {
// 40
//         cout << "**** " << player->name
         cout << "**** " << player.name
              << " is on injury reserve so can't be updated ****"
              << endl << endl;
       }
     }
  }
  
   cout << "************************************************************"
        << endl << endl;

   return;
}

// 41
//void doTopScorer (PlayerPtr head)
void doTopScorer (const HockeyList &theList)
{
// 42
//  PlayerPtr first, next;
  PlayerNode first, next;
  bool playerExists, possible, nonGoalie;
  int index;
  
  cout << "************************************************************"
       << endl << endl;
  
// 43
//  if (!containsActivePlayers(head))
  theList.lookup(1, first, playerExists);
  if (!playerExists || theList.getTeam(1) == TEAMCHARS[INJURY_LIST_POSITION])
    cout << "There is no top scorer as there are no active players"
         << endl << endl;
  else
  {
    index = 1;
    possible = true;
    nonGoalie = false;
    do
    {
// 44
//      search(head, index, first, playerExists);
      theList.lookup(index, first, playerExists);
      if (playerExists)
      {
// 45
//        if (first->team == TEAMCHARS[INJURY_LIST_POSITION])
        if (theList.getTeam(index) == TEAMCHARS[INJURY_LIST_POSITION])
        {
          possible = false;
        }
// 46
//        else if (first->position != GOAL)
        else if (first.position != GOAL)
        {
          nonGoalie = true;
        }
        else
          index++;
      }
    } while (playerExists && !nonGoalie && possible);

    if (nonGoalie)
    {
      index++;
// 47
//      search(head, index, next, playerExists);
//      while (playerExists && next->team != TEAMCHARS[INJURY_LIST_POSITION])
          theList.lookup(index, next, playerExists);
      while (playerExists &&
             theList.getTeam(index) != TEAMCHARS[INJURY_LIST_POSITION])
      {
// 48
//        if (next->position != GOAL)
        if (next.position != GOAL)
        {
// 49
//          if (next->goals + next->assists > first->goals + first->assists)
          if (next.goals + next.assists > first.goals + first.assists)
          {
            first = next;
          }
        }
        index++;
// 50
//        search(head, index, next, playerExists);
        theList.lookup(index, next, playerExists);
      }
      cout << "Top Scorer is:" << endl << endl;
//51
//      cout << first->name << " with " << first->goals + first->assists
      cout << first.name << " with " << first.goals + first.assists
           << " total points" << endl << endl;
    }
    else
    {
      cout << "No top scorer - all active players are goaltenders" 
           << endl << endl;
    }
  }

  cout << "************************************************************"
       << endl << endl;
  
  return;
}

// 52
//void doQuit (PlayerPtr &head, bool interactive)
void doQuit (HockeyList &theList, bool interactive)
{
   char outFileName[FILENAME_LENGTH];
   ofstream outFile;
   bool eof;

   do {
     if (interactive)
       readString ("Enter name of output file: ", outFileName, FILENAME_LENGTH, 1, eof);
     else
       readString ("", outFileName, FILENAME_LENGTH, 1, eof);
     if (eof)
       cout << endl;
   } while (eof);
   outFile.open(outFileName);
   if (outFile.fail())
   {
      cout << "**** Unable to open output file - exiting ****" << endl;
   }
   else
   {
// 53
//     write(outFile, head);
     theList.write(outFile);
     cout << endl << "Player list saved to file and program exiting." << endl;
     outFile.close();
// 54 
//     destroyList(head);
   }      

   return;
}


int readPlayerNumber (int max, bool interactive)
{
   int p;
   bool pOK,
        eof;

   do {
     if (interactive)
       p = readInt("Enter Player number: ", eof);
     else
       p = readInt("", eof);
     !eof ? pOK = (p > 0 && p <= max): pOK = false;

     if (eof)
       cout << endl
            << "**** EOF ignored - to abort the program type Ctrl-c ****"
            << endl;
     else if (!pOK)
       cout << "**** Player number must be between 1 and " << max << " ****"
            << endl;
   } while (!pOK || eof);
   return p;
}

int readPoints (const char prompt[])
{
   int p;
   bool pOK = false,
        eof;

   do
   {
     p = readInt(prompt, eof);
     if (eof)
     {
       cout << endl
            << "**** EOF ignored - to abort the program type Ctrl-c ****"
            << endl;
     }
     else if (p < 0)
       cout << "**** All player points must be greater than or equal to 0 ****"
            << endl;
     else
       pOK = (p >= 0);
   } while (eof || !pOK);

   return p;
}

char readTeam (bool interactive)
{
  char fakeStr[2], c;
  bool cOK, eof;
  
  do
  {
    if(interactive)
      readString("Enter team (C/F/U): ",fakeStr, 1, 1, eof);
    else
      readString("",fakeStr, 1, 1, eof);

    if (eof)
     {
       cout << endl
            << "**** EOF ignored - to abort the program type Ctrl-c ****"
            << endl;
     }
  } while (eof);      
  c = fakeStr[0];
  cOK = ((c == 'C') || (c == 'F') || (c == 'U'));
  while (!cOK)
  {
    cout << "**** Team must be one of C(anada), F(inland) or U(SA) ****" << endl;
    if (interactive)
      readString("Enter team (C/F/U): ",fakeStr, 1, 1, eof);
    else
      readString("",fakeStr, 1, 1, eof);

    c = fakeStr[0];
    cOK = ((c == 'C') || (c == 'F') || (c == 'U'));
  }
  return c;
}

// 55
/*
int load (istream& infile, PlayerPtr& head)
{
   char pName[MAXNAMELEN+1];
   char pTeam;
   char pPos;
   int pGoals;
   int pAssists;
   int pGoalsAgainst;
   char junk;
   PlayerPtr curr;
   int count = 0;

   infile >> pTeam;
   while (!infile.eof())
   {
     count++;
     infile >> pPos >> pGoals >> pAssists >> pGoalsAgainst;
     infile.get (junk);
     infile.getline(pName, MAXNAMELEN+1, '\n');
     curr = createPlayer (pName, pTeam, pPos, pGoals, pAssists, pGoalsAgainst);
     insertPlayer (head, curr);
     infile >> pTeam;
   }
   return count;
}

void write (ostream& outfile, PlayerPtr head)
{
   PlayerPtr temp = head;

   while (temp != NULL)
   {
      outfile << temp->team << " ";
      outfile << temp->position << " ";
      outfile << temp->goals << " ";
      outfile << temp->assists << " ";
      outfile << temp->goalsAgainst << " ";
      outfile << temp->name << endl;

      temp = temp->next;
   }
   return;
}
*/
