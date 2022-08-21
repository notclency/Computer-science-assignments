#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include <fstream>
using namespace std;

#include "Rectangle.h"  // PARENT
#include "Grid.h"       // GRID
#include "globals.h"    // GLOBALS


/********************************************************************
 *
 * Name:             Clency Tabe
 * Email:            ctabe297@mtroyal.ca
 * Course:           COMP 1633, 001
 * Due Date:         April 8, 2022
 * Instructor name:  Paul Pospisil
 * File name:        Square.h
 *
 ********************************************************************/

/****************************************************
 *
 * File name:           Square.h
 * 
 * Implementation file: Square.cpp
 *
 * Class name:          Square
 *
 * Parent class:        Rectangle
 *
 * Base class:          Shape
 *
 * Purpose:             creates a square shape with
 *                      help from parent class
 *
 ****************************************************/

/****************************************************
 *
 * CLASS: Square
 *
 * PURPOSE: Creates a square shape
 *
 ****************************************************
 *
 * PUBLIC METHODS:
 *
 ****************************************************
 *
 * CLASS: Square
 *     PURPOSE: creates a square shape by using
 *              the passed variables to set it's
 *              boundries, ie upper left and lower right
 * INPUT: lft - x coordinate of the shape
 *        up - y coordinate of the shape
 *        width - the base of the shape
 *
 ***************************************************/


class Square : public Rectangle
{
public:
  Square(int lft, int up, int width);

};

#endif
