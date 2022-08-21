#include "Grid.h"
#include "Shape.h"
#include "IsoTriangle.h"

//------------------------------------------------------------------------------

// RECTANGLE CLASS


/********************************************************************
 *
 * Name:             Clency Tabe
 * Email:            ctabe297@mtroyal.ca
 * Course:           COMP 1633, 001
 * Due Date:         April 8, 2022
 * Instructor name:  Paul Pospisil
 * File name:        IsoTriangle.cpp
 *
 ********************************************************************/

IsoTriangle :: IsoTriangle (int lft, int up, int base, int height) 
  : Shape (lft, up, lft + base - 1, up + height - 1) 
{
}

void IsoTriangle :: draw (Grid &grid)
{
  int left;
  int upper;
  int right;
  int lower;
  
  Shape :: get_bounding_box(left, upper, right, lower);

  int base = right - left + 1;

  grid.plot_line(left + (base/2), upper, left, lower);
  grid.plot_line(left + (base/2), upper, right, lower);
  grid.plot_line(left, lower, right, lower);

}
