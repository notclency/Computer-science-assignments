#include "Grid.h"
#include "Shape.h"

//------------------------------------------------------------------------------

// SHAPE CLASS


Shape :: Shape(int lft, int up, int rght, int low)
{
  left = lft;
  upper = up;
  right = rght;
  lower = low;
}

Shape :: ~Shape()
{
}

void Shape :: move(int new_left, int new_upper)
{
  int height = lower - upper;
  int width = right - left;
  
  right = new_left + width;
  lower = new_upper + height;
  left = new_left;
  upper = new_upper;
  
}

void Shape :: get_bounding_box(int &lft, int &up, int &rght, int &low) const
{
  int base = right - left;
  int height = lower - upper;

  lft = left;
  up = upper; 
  rght = left + base;
  low = upper + height;
}
