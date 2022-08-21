#ifndef EQUTRIANGLE_H
#define EQUTRIANGLE_H

#include <iostream>
#include <fstream>
using namespace std;

#include "IsoTriangle.h"       // PARENT
#include "Grid.h"              // GRID
#include "globals.h"           // GLOBALS

/********************************************************************
 *
 * Name:             Clency Tabe
 * Email:            ctabe297@mtroyal.ca
 * Course:           COMP 1633, 001
 * Due Date:         April 8, 2022
 * Instructor name:  Paul Pospisil
 * File name:        EquiTriangle.h
 *
 ********************************************************************/

/***************************************************
 *
 * File name:           EquTriangle.h
 *
 * Implementation file: EquTriangle.cpp
 *
 * Class Name:          EquTriangle
 *
 * Parent class:        IsoTraingle
 *
 * Base class:          Shape
 *
 * Purpose:             creates an equilateral triangle 
 *                      shape with help from parent
 *                      class
 *
 **************************************************/

/****************************************************
 * 
 * CLASS: EquTriangle
 *
 * PURPOSE: Creates an Equitriangle shape
 * 
 ****************************************************
 *
 * PUBLIC METHODS:
 *
 ****************************************************
 *
 * CLASS: EquTriangle
 *     PURPOSE: creates an Equitrinagle shape by using
 *              the passed variables to set it's 
 *              boundries, ie upper left and lower right
 * INPUT: lft - x coordinate of the shape
 *        up - y coordinate of the shape
 *        base - the base of the shape
 *
 ***************************************************/


class EquTriangle : public IsoTriangle
{
public:
  EquTriangle(int lft, int up, int base);

};

#endif
