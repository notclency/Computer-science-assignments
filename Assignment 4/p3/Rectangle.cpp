#include "Grid.h"
#include "Shape.h"
#include "Rectangle.h"

//------------------------------------------------------------------------------

// RECTANGLE CLASS

/********************************************************************
 *
 * Name:             Clency Tabe
 * Email:            ctabe297@mtroyal.ca
 * Course:           COMP 1633, 001
 * Due Date:         April 8, 2022
 * Instructor name:  Paul Pospisil
 * File name:        Rectangle.cpp
 *
 ********************************************************************/

/**************************************************************
 *
 * FUNCTION: Rectangle
 *
 * PURPOSE: Creates a rectangle using passed in arguments
 * 
 * INPUT: 
 *      lft - coordinate of the left corner of the rectangle
 *      up - coordinate of the upper corner of the rectangle
 *      width - lenght of the width of the rectangle
 *      height - lenght of the height of the rectangle
 * 
 ***************************************************************/

Rectangle :: Rectangle (int lft, int up, int width, int height) :
  Shape (lft, up , lft + width - 1, up + height - 1)
{
}


/**************************************************************
 *
 * FUNCTION: Rectangle
 *
 * PURPOSE: draws the rectangle on a grid (passed in argument)
 *          using a function from the class grid.
 * 
 * INPUT: 
 *       grid - a grid
 * 
 ***************************************************************/

void Rectangle :: draw (Grid &grid)
{
  int left;
  int upper;
  int right;
  int lower;
  
  Shape :: get_bounding_box(left, upper, right, lower);
  
  grid.plot_line(left, upper, right, upper);
  grid.plot_line(left, upper, left, lower);
  grid.plot_line(left, lower, right, lower);
  grid.plot_line(right, upper, right, lower);
}
