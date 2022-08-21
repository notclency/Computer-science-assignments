#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <fstream>
using namespace std;
#include "globals.h"


/*******************************************************
 *
 * Name:         Clency Tabe
 * email:        ctabe297@mtroyal.ca
 * coures:       COMP 1633, 001
 * Assignment:   Assigngment 5 part 1
 * Due Date:     April 8, 2022
 * Instructor:   Paul Posipisil
 * File Name:    Grid.h
 * Purpose:      This is an h file for the file "Grid.cpp"
 *               This class is a able to plot points,
 *               lines and draw on a given grid.
 *
 *******************************************************/

class Grid
{
public:
   Grid ();
   void plot_point (int x, int y);
   void plot_line (int x1, int y1, int x2, int y2);
   void write (ostream&) const;

private:
   char raster[YMAX][XMAX+2];
   bool is_in_bounds (int x, int y) const;
};


ostream& operator << (ostream&, const Grid&);


#endif
