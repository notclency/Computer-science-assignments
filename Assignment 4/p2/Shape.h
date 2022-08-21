#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <fstream>
using namespace std;

#include "Grid.h"
#include "globals.h"

/******************************************************************************
 * 
 * Name:             Clency Tabe 
 * Email:            ctabe297@mtroyal.ca
 * Course:           COMP 1633, 001
 * Assignment:       Assignemnt 5 part 2
 * Due Date:         April 8, 2022
 * Instructor name:  Paul Pospisil
 * File name:        Shape.h
 * Purpose:          This is a .h file for the file "Shape.cpp"
 *                   It contains the definition of a class called shape.
 *                   This class is able to create a shape, move it and draw it on
 *                   a grid.
 *
 ****************************************************************************/


/******************************************************************************
 *
 * CLASS: Shape
 *
 * PURPOSE: Creates a square shape
 *
 ******************************************************************************
 *
 * PUBLIC METHODS:
 *
 ******************************************************************************
 *
 * Shape
 *     PURPOSE: creates a shape using passed in arguments
 *     
 *     INPUT: lft - coordinate of the left corner of the box
 *            up - coordinate of the upper corner of the box
 *            width - lenght of the width of the box
 *            
 ******************************************************************************
 *
 * move
 *     PURPOSE: moves a shape using passed in arguments
 *
 *     INPUT: new_left - coordinate of the new left corner of the box
 *            new_upper - coordinate of the new upper corner of the box
 *
 ******************************************************************************
 *
 * draw
 *     PURPOSE: draws a shape on a grid (shape can be out of bounds
 *
 *     INPUT: grid - a grid
 *
 ******************************************************************************
 *
 * PROTECTED FUNCTIONS:
 *
 ******************************************************************************
 *
 * get_bounding_box
 *     PURPOSE: gets the bounding box of a shape and returns them by reference
 *             using the passed in arguments
 *
 *     INPUT: lft - coordinate of the left corner of the box
 *            up - coordinate of the upper corner of the box
 *            rght - coordinate of the right corner of the box
 *            low - coordinate of the lower corner of the box
 *
 ******************************************************************************/


class Shape
{
public:
  Shape(int lft, int up, int width);

  void move(int new_left, int new_upper);

  void draw(Grid &grid);

protected:
  void get_bounding_box(int &lft, int &up, int &rght, int &low) const;

private:
  int left;
  int upper;
  int right;
  int lower;
};

#endif
