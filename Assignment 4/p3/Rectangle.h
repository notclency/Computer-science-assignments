#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <fstream>
using namespace std;

#include "Shape.h"       // PARENT
#include "Grid.h"        // GRID
#include "globals.h"     // GLOBALS

/********************************************************************
 *
 * Name:             Clency Tabe
 * Email:            ctabe297@mtroyal.ca
 * Course:           COMP 1633, 001
 * Due Date:         April 8, 2022
 * Instructor name:  Paul Pospisil
 * File name:        Rectangle.h
 *
 ********************************************************************/

/**************************************************
 *
 * File name:          Rectangle.h
 *
 * Implmentation file: Rectangle.cpp
 * 
 * Class name:         Rectangle
 *
 * Parent class:       Shape
 *
 * Base class;         Shape
 *
 * Purpose:            creates a rectangle shape
 *
 ***************************************************/

/****************************************************
 *
 * CLASS: Rectangle
 *
 * PURPOSE: Creates a Rectangle Shape
 *
 ****************************************************
 *
 * PUBLIC METHODS:
 *
 ****************************************************
 *
 * Rectanlge
 *     PURPOSE: creates a Rectangle shape by using
 *              the passed variables to set it's
 *              boundries, ie upper left and lower right
 *
 * INPUT: lft - x coordinate of the shape
 *        up - y coordinate of the shape
 *        base - the base of the shape
 *        height - height of the shape
 *
 *****************************************************
 *
 * move
 *     PURPOSE: set new coordinates for an already
 *              existing shape using passed coordinates.
 *              ie moves the shape.
 *
 * INPUT: new_left - the new x coordinate of the shape
 *        new_upper - the new y coordinate of the shape
 *
 * RETURN: NONE
 *
 *****************************************************
 *
 * draw
 *     PURPOSE: draw's a shape on a passed by reference
 *              grid
 *
 * INPUT: grid - a grid
 *
 * RETURN: NONE
 *
 ***************************************************/

class Rectangle : public Shape
{
public:
  Rectangle(int lft, int up, int width, int height);

  //  void move (int new_left, int new_upper);
  
  void draw(Grid &grid);
};

#endif
