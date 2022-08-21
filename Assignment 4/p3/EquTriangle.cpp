#include "Grid.h"
#include "IsoTriangle.h"
#include "EquTriangle.h"

//------------------------------------------------------------------------------

/********************************************************************
 *
 * Name:             Clency Tabe
 * Email:            ctabe297@mtroyal.ca
 * Course:           COMP 1633, 001
 * Due Date:         April 8, 2022
 * Instructor name:  Paul Pospisil
 * File name:        EquiTriangle.cpp
 *
 ********************************************************************/

// RECTANGLE CLASS

EquTriangle :: EquTriangle (int lft, int up, int base)
  : IsoTriangle (lft, up, base, base)
{
}
