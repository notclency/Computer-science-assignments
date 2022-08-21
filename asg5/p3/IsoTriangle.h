#ifndef ISOTRIANGLE_H
#define ISOTRIANGLE_H

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
 * File name:        IsoTriangle.h
 *
 ********************************************************************/

/****************************************************
 *
 * Class name:          IsoTriangle.h
 *
 * Implementation file: IsoTriangle.cpp
 *
 * Class name:          IsoTriangle
 * 
 * Parent class:        IsoTriangle.h
 *
 * Base class:          Shape.cpp
 *
 * Purpose:             creates an Isoceles Triangle
 *                      shape with help from parent
 *                      class
 *
 ****************************************************/

/*****************************************************
 *
 * CLASS: IsoTriangle
 *
 * PURPOSE: Creates an Isosceles triangle shape
 *
 *****************************************************
 *
 * PUBLIC METHODS:
 *
 *****************************************************
 *
 * IsoTriangle
 *     PURPOSE: creates an Isotraingle shape by using
 *              the passed variable to set it's
 *              boundries, ie upper left and lower right
 *  
 * INPUT: lft - x coordiantes for the shape
 *        up - y coordinates for the shape
 *        base - base of the shape
 *        height - height of the shape
 *
 ******************************************************
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
 ****************************************************/


class IsoTriangle : public Shape
{
public:
  IsoTriangle(int lft, int up, int base, int height);

  //  void move (int new_left, int new_upper);
  
  void draw(Grid &grid);
};

#endif
