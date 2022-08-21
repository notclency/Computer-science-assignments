#include "Grid.h"       // grid
#include "Rectangle.h"  // PARENT CLASS
#include "Square.h"     // .h file

//------------------------------------------------------------------------------

// SQUARE CLASS

/********************************************************************
 *
 * Name:             Clency Tabe
 * Email:            ctabe297@mtroyal.ca
 * Course:           COMP 1633, 001
 * Due Date:         April 8, 2022
 * Instructor name:  Paul Pospisil
 * File name:        Square.cpp
 *
 ********************************************************************/

/**************************************************************
 *
 * Function: Square
 * 
 * PURPOSE: creates a square shape using passed in arguments
 *
 * INPUT: 
 *      lft - coordinate of the left corner of the square
 *      up - coordinate of the up corner of the square 
 *      width - lenght of the width of the square
 *
 *
 *************************************************************/

Square :: Square (int lft, int up, int width)
  : Rectangle (lft, up, width, width)
{
}
