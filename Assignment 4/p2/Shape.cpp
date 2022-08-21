#include "Shape.h"
#include "Grid.h"
#include "globals.h"

// IMPLEMTATONS OF THE "SHAPE.H" FILE.

/**************************************************************************
 *
 * Name:                 Clency Tabe
 * Email:                ctabe297@mtroyal.ca
 * Course:               COMP 16333, 001
 * Due Date:             April 8, 2022
 * Instructor Name:      Paul Pospisil
 * File name:            Shape.cpp
 *
 **************************************************************************/

/**************************************************************************
 *
 * Function:    Shape
 * Purpose:     Set the coordinates of the bounding box of a shape using
 *              provided passed in arguments
 * Input:       x and ycoordiantes for upper left corner of bounding box, and
 *              width of the shape box.
 * Output:      None
 * Return:      None
 *
 **************************************************************************/
Shape :: Shape(int lft, int up, int width)
{
  left = lft;
  upper = up;
  right = left + width - 1;
  lower = upper + width - 1;
}


/**************************************************************************
 * 
 * Function:   move
 * Purpose:    Moves a shape by setting the new coordinates of the bounding
 *             box using the passed-in new x and y coordiantes for upper left
 *             corner of bounding box of an existing shape
 * Input:      new x and y coordiantes for upper left corner of bounding box
 * Output:     None
 * Return:     None
 *
 **************************************************************************/
void Shape :: move(int new_left, int new_upper)
{
  int new_right;
  int new_lower;
  
  get_bounding_box(new_left, new_upper, new_right, new_lower);

  left = new_left;
  upper = new_upper;
  right = new_right;
  lower = new_lower;
}


/**************************************************************************
 * 
 * Function:   draw
 * Purpose:    Draws an exsiting shape on a Grid using a function from the
 *             grid class
 * Input:      grid
 * Output:     None
 * Return:     None
 *
 **************************************************************************/
void Shape :: draw (Grid &grid)
{
  grid.plot_line(left, upper, right, upper);
  grid.plot_line(left, upper, left, lower);
  grid.plot_line(right, upper, right, lower);
  grid.plot_line(left, lower, right, lower);
}

/**************************************************************************
 * 
 * Function:   get_bounding_box
 * Purpose:    Gets the coordinates of the bounding box i.e the x and 
 *             y coordiantes for upper left corner, the x and y coordiantes
 *             for lower right corner of the bounding box
 * Input:      4 interger values to be set to the required coordiantes
 * Output:     all interger values to be returned as the required coordinates
 * Return:     None
 *
 **************************************************************************/
void Shape :: get_bounding_box(int &lft, int &up, int &rght, int &low) const
{
  int width = right - left;

  rght = lft + width;
  low = up + width;
}
