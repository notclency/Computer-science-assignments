#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Grid.h"
#include "Shape.h"
#include "Rectangle.h"
#include "Square.h"
#include "IsoTriangle.h"
#include "EquTriangle.h"
#include "Shape_Collection.h"
#include "ioutil.h"

#define QUIT 'q'
#define ADD 'a'
#define DELETE 'd'
#define MOVE 'm'

void show_menu();

string getShapeName();
void getUpperLeft (int& xtop, int& ytop);
int getWidth();
int getHeight();
char getShapeType();

void doAdd (Shape_Collection& shapes);
void doDelete (Shape_Collection& shapes);
void doMove (Shape_Collection& shapes);
bool doQuit ();
void eof_message();

int main()
{

  /********************************************************************
   *
   * Name:             Clency Tabe
   * Email:            ctabe297@mtroyal.ca
   * Course:           COMP 1633, 001
   * Due Date:         April 8, 2022
   * Instructor name:  Paul Pospisil
   * File name:        main.cpp
   * 
   * Purpose:          Display menu options to user and uses files in
   *                   current directory to accomplish certain tasks.
   * Details:          Uses all files in current directory to draw certain
   *                   shapes on a grid.
   *
   ********************************************************************/
  
  Shape_Collection myShapes;
  char choice;
  char choiceStr[2];
  bool done = false;
  bool eof = false;

  do
  {
    myShapes.write_names (cout);
    cout << endl;
    myShapes.draw_shapes(cout);
    show_menu();
    readString("Please enter choice: ", choiceStr, 1, 1, eof);
    if (eof)
    {
      eof_message();
    }
    else
    {
      choice = choiceStr[0];
    }
    switch (choice)
    {
    case ADD:    doAdd (myShapes);
      break;
    case DELETE: doDelete (myShapes);
      break;
    case MOVE:   doMove (myShapes);
      break;
    case QUIT:   done = doQuit ();
      break;
    default:     cout << choice << " is unknown command" << endl;
      break;
    }
  }
  while (!done);

  return 0;
}


void show_menu()
{
  cout << "Options:  a(dd shape)" << endl;
  cout << "          d(elete) shape" << endl;
  cout << "          m(ove) shape" << endl;
  cout << "          q(uit) paint program" << endl;
  return;
}

void getUpperLeft (int& xtop, int& ytop)
{
  bool eof;

  do
  {
    xtop = readInt ("Enter x coordinate for upper left corner of bounding box: ", eof);
    if (eof)
    {
      eof_message();
    }
  } while (eof);

  do
  {
    ytop = readInt ("Enter y coordinate for upper left corner of bounding box: ", eof);
    if (eof)
    {
      eof_message();
    }
  } while (eof);
    
  return;
}

/******************************************************************
 *
 * Function: getWidth
 *
 * Purpose: reads and returns a width (interger)
 *
 * INPUT: NONE
 *
 * OUTPUT: returns the width (interger)
 *
 ******************************************************************/

int getWidth ()
{
  int width;
  bool invalid = true;
  bool eof;

  do{
    width = readInt("Enter width: ", eof);
    if(eof)
      {
	eof_message();
      }
    if(width >= 1)
      {
	invalid = false;
      }else
      {
	cout << "ERROR - Width most be greater than 0" << endl;
      }
  } while (eof || invalid);
  
  return width;
}

/******************************************************************
 *
 * Function: getHeight
 *
 * Purpose: reads and returns a Height (interger)
 *
 * INPUT: NONE
 *
 * OUTPUT: returns the Height (interger)
 *
 ******************************************************************/

int getHeight ()
{
  int height;
  int invalid = true;
  bool eof;
  

  do{
    height = readInt("Enter height: ", eof);
    if(eof)
      {
	eof_message();
      }
    if(height >= 1)
      {
	invalid = false;
      }else
      {
	cout << "ERROR - Height most be greater than 0" << endl;
      }
  } while (eof || invalid);
  
  return height;
}

/******************************************************************
 *
 * Function: getShapeType
 *
 * Purpose: reads and returns a ShapeType (char)
 *
 * INPUT: NONE
 *
 * OUTPUT: returns the ShapeType (char)
 *
 ******************************************************************/

char getShapeType ()
{

  bool eof;
  char shapeTypeStr[2];
  char shapeType;
  
  do{
    cout << "Options:  r(ectanle) shape" << endl;
    cout << "          s(square) shape" << endl;
    cout << "          i(soceles traingle) shape" << endl;
    cout << "          e(quilateral triangle) shape" << endl << endl;

    readString("Choice: ",  shapeTypeStr, 1, 1, eof);
    if(eof){
      eof_message();
    }else{
      shapeType = shapeTypeStr[0];
    }
    
  } while (eof);
  
  return shapeType;
}


/******************************************************************
 *
 * Function: getShapeName
 *
 * Purpose: reads and returns a ShapeName (string)
 *
 * INPUT: NONE
 *
 * OUTPUT: returns the shapeName (string)
 *
 ******************************************************************/

string getShapeName()
{
  string result;
  char ch;
  bool eof;

  do
    {
      eof = false;
      cout << "Please enter shape name (no blanks): ";
      cin >> result;
      if (cin.eof())
	{
	  eof = true;
	  cin.clear();
	  cin.putback(' ');
	  cin.get(ch);
	  eof_message();
	}
    } while (eof);

  do
    {
      cin.get(ch);
    } while (ch != '\n');
  
  return result;
}


/******************************************************************
 *
 * Function: doMove
 *
 * Purpose: moves a shape (if it exist).
 *
 * INPUT: Shape_Collection  - passed by refernce
 *
 * OUTPUT: Updated Shape_Collection
 *
 ******************************************************************/
 
void doMove (Shape_Collection& myShapes)
{

  string shapeName;
  Shape *yourShape;
  int new_left;
  int new_upper;
  
  shapeName = getShapeName();
  yourShape = myShapes.lookup(shapeName);

  if(yourShape == NULL){
    cout << endl << "ERROR - Shape name doesn't exist in shape collection" << endl;
  }else{
    getUpperLeft(new_left, new_upper);
    yourShape->move(new_left, new_upper);
  }
  
  return;
}


/******************************************************************
 *
 * Function: doDelete
 *
 * Purpose: deletes a shape (if it exist).
 *
 * INPUT: Shape_Collection  - passed by refernce
 *
 * OUTPUT: Updated Shape_Collection
 *
 ******************************************************************/
 
void doDelete (Shape_Collection& myShapes)
{

  string shapeName;
  Shape *yourShape;
  
  shapeName = getShapeName();
  yourShape  = myShapes.lookup(shapeName);

  if(yourShape != NULL){
    myShapes.remove(shapeName);
  }else{
    cout << endl << "ERROR - Shape name doesn't exist in shape collection" << endl;
  }
  
  return;
}


/******************************************************************
 *
 * Function: doAdd
 *
 * Purpose: adds a new shape (if it's name doesnt't exist
 *         in shape collection).
 *
 * INPUT: Shape_Collection  - passed by refernce
 *
 * OUTPUT: Updated Shape_Collection
 *
 ******************************************************************/
 
void doAdd (Shape_Collection& myShapes)
{
  char rectangleType  = 'r';
  char squareType  = 's';
  char isoTriangleType  = 'i';
  char equTriangleType  = 'e';

  int left;
  int upper;
  int width;
  int height;

  string shapeName;
  
  Square *aSquare;
  Rectangle *aRectangle;
  IsoTriangle *isoTriangle;
  EquTriangle *equTriangle;

  Shape *yourShape;
  
  char shapeType;
    
  shapeName = getShapeName();
  yourShape = myShapes.lookup(shapeName);
  
  if(yourShape != NULL){
    cout << endl << "ERROR - Shape name already exist in shape collection" << endl << endl;
  }else{
    
    shapeType = getShapeType();
    if(shapeType != rectangleType &&
       shapeType != squareType &&
       shapeType != isoTriangleType &&
       shapeType != equTriangleType){
      
      cout << endl << "ERROR - Invalid shape type - (r,s,i,e)" << endl << endl;
    }else{
      getUpperLeft(left, upper);

      width = getWidth();

      if(shapeType == rectangleType || shapeType == isoTriangleType){

	height = getHeight();

	if(shapeType == rectangleType){

	  aRectangle = new Rectangle(left, upper, width, height);
	  myShapes.add(aRectangle, shapeName);
	}else{

	  isoTriangle = new IsoTriangle(left, upper, width, height);
	  myShapes.add(isoTriangle, shapeName);
	}
      }else{
      
	if(shapeType == squareType){

	  aSquare = new Square(left, upper, width);
	  myShapes.add(aSquare, shapeName);
	}else{

	  equTriangle = new EquTriangle(left, upper, width);
	  myShapes.add(equTriangle, shapeName);
	}
      }
    }
  }

  return;
}

bool doQuit ()
{
  bool done;
  bool eof;

  done = readBool ("Are you sure you are done painting? (y/n) ", eof);
  if (done || eof)
    cout << "I've had fun painting with you! Bye..." << endl;
  else
    cout << "Back we go..." << endl;

  return done;
}

void eof_message()
{
  cout << endl << "typing CTRL-d is not acceptable here"
       << " - to terminate the program type CTRL-c" << endl;

  return;
}
