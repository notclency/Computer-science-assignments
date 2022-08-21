#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <fstream>
using namespace std;

#include "Grid.h"
#include "globals.h"

//------------------------------------------------------------------------------

class Shape
{
public:
  Shape(int lft, int up, int rght, int low);

  virtual ~Shape();
  
  void move(int new_left, int new_upper);

  virtual void draw (Grid &grid) = 0;
  
protected:
  void get_bounding_box(int &lft, int &up, int &rght, int &low) const;

private:
  int left;
  int upper;
  int right;
  int lower;
};

#endif
