#include <iostream>
using namespace std;
#include <sstream>
#include <string>
#include "Grid.h"
#include "Shape.h"
#include <gtest/gtest.h>


class Shape_Tests : public testing::Test
{
protected:
  virtual void SetUp()
  {
  }

  virtual void TearDown()
  {
  }

  Grid c;
};


/**********************************************************************
 *
 * Name:             Clency Tabe
 * Email:            ctabe297@mtroyal.ca
 * Course:           COMP 1633, 001
 * Assignment:       Assignment 5, part 2
 * Due Date:         April 8, 2022
 * Instructor name:  Paul Pospisil
 * File name:        test_Shape.cpp
 * Purpose:          test the interaction between functions from the
 *                   files "Grid.h" and "Shape.h"
 *
 **********************************************************************/


// ALL TESTS CASES TESTS THE DRAW FUNCTION. THAT'S HOW EXPECTED
// AND ACTUAL OUPUT ARE COMPARED

TEST_F(Shape_Tests, TestShapeConstructor_ShapesOnGrid)
{
  stringstream actualOutput;
  string expected = "";

  // 1 SHAPE

  expected += "--------------------------------------------------\n";
  expected += "                                                  \n";
  expected += " *****                                            \n";
  expected += " *   *                                            \n";
  expected += " *   *                                            \n";
  expected += " *   *                                            \n";
  expected += " *****                                            \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "--------------------------------------------------\n";

  Grid aGrid;

  Shape shape1 (1, 1, 5);
  shape1.draw(aGrid);

  aGrid.write(actualOutput);
  EXPECT_EQ(expected, actualOutput.str());
}

TEST_F(Shape_Tests, TestShapesOverWrittenOnShape)
{
  stringstream actualOutput;
  string expected = "";

  // 2 OR MORE SHAPES

  expected += "--------------------------------------------------\n";
  expected += "                                                  \n";
  expected += " *****                                            \n";
  expected += " *   *                                            \n";
  expected += " * ********                                       \n";
  expected += " * * *    *                                       \n";
  expected += " *****    *                                       \n";
  expected += "   *      *                                       \n";
  expected += "   *      *                                       \n";
  expected += "   *      *                                       \n";
  expected += "   *      *                                       \n";
  expected += "   ********                                       \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "--------------------------------------------------\n";

  Grid aGrid;

  Shape shape1 (1, 1, 5);
  Shape shape2 (3, 3, 8);

  shape1.draw(aGrid);
  shape2.draw(aGrid);

  aGrid.write(actualOutput);
  EXPECT_EQ(expected, actualOutput.str());


  // 3 OR MORE SHAPES

  expected += "--------------------------------------------------\n";
  expected += "                                                  \n";
  expected += " *****                                            \n";
  expected += "***  *                                            \n";
  expected += "***********                                       \n";
  expected += "**** *    *                                       \n";
  expected += " *****    *                                       \n";
  expected += "   *      *                                       \n";
  expected += "   *      *                                       \n";
  expected += "   *      *                                       \n";
  expected += "   *      *                                       \n";
  expected += "   ********                                       \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "--------------------------------------------------\n";

  Shape shape3 (0, 2, 3);

  shape3.draw(aGrid);

  aGrid.write(actualOutput);
  EXPECT_EQ(expected, actualOutput.str());
}

TEST_F(Shape_Tests, PartialOutOfBoundsShape)
{
  stringstream actualOutput;
  string expected = "";

  expected += "--------------------------------------------------\n";
  expected += "                                                  \n";
  expected += "******                                            \n";
  expected += "     *                                            \n";
  expected += "     *                                            \n";
  expected += "     *                                            \n";
  expected += "     *                                            \n";
  expected += "     *                                            \n";
  expected += "     *                                            \n";
  expected += "     *                                            \n";
  expected += "     *                                            \n";
  expected += "******                                            \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "--------------------------------------------------\n";

  Grid aGrid;

  Shape shape (-4, 1, 10);
  shape.draw(aGrid);

  aGrid.write(actualOutput);
  EXPECT_EQ(expected, actualOutput.str());
}

TEST_F(Shape_Tests, MovingAShapeWithinGrid)
{
  stringstream actualOutput;
  string expected = "";
  
  expected += "--------------------------------------------------\n";
  expected += "                                                  \n";
  expected += " *****                                            \n";
  expected += " *   *                                            \n";
  expected += " *   *                                            \n";
  expected += " *   *                                            \n";
  expected += " *****                                            \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "          *****                                   \n";
  expected += "          *   *                                   \n";
  expected += "          *   *                                   \n";
  expected += "          *   *                                   \n";
  expected += "          *****                                   \n";
  expected += "--------------------------------------------------\n";
  
  Grid aGrid;
  
  Shape shape (1, 1, 5);
  shape.draw(aGrid);
  
  shape.move(10, 10);
  shape.draw(aGrid);

  aGrid.write(actualOutput);
  EXPECT_EQ(expected, actualOutput.str());
}

TEST_F(Shape_Tests, MoveCompletelyOutOfBounds)
{
  stringstream actualOutput;
  string expected = "";
  
  expected += "--------------------------------------------------\n";
  expected += "                                                  \n";
  expected += " *****                                            \n";
  expected += " *   *                                            \n";
  expected += " *   *                                            \n";
  expected += " *   *                                            \n";
  expected += " *****                                            \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "--------------------------------------------------\n";
  
  Grid aGrid;
  
  Shape shape (1, 1, 5);
  shape.draw(aGrid);
  
  shape.move(-100, -100);
  shape.draw(aGrid);
  
  aGrid.write(actualOutput);
  EXPECT_EQ(expected, actualOutput.str());
}

TEST_F(Shape_Tests, MovingShapeWithingItsSelf)
{
  stringstream actualOutput;
  string expected = "";

  expected += "--------------------------------------------------\n";
  expected += "                                                  \n";
  expected += " *****                                            \n";
  expected += " ******                                           \n";
  expected += " **  **                                           \n";
  expected += " **  **                                           \n";
  expected += " ******                                           \n";
  expected += "  *****                                           \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "--------------------------------------------------\n";

  Grid aGrid;

  Shape shape (1, 1, 5);
  shape.draw(aGrid);

  shape.move(2, 2);
  shape.draw(aGrid);


  aGrid.write(actualOutput);
  EXPECT_EQ(expected, actualOutput.str());
}

TEST_F(Shape_Tests, MoveOnAnotherShape)
{
  stringstream actualOutput;
  string expected = "";

  expected += "--------------------------------------------------\n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "     *****                                        \n";
  expected += "     *   *                                        \n";
  expected += "     *   *                                        \n";
  expected += "     *   *             *****                      \n";
  expected += "     *****             *   *                      \n";
  expected += "                       *  *******                 \n";
  expected += "                       *  **    *                 \n";
  expected += "                       *****    *                 \n";
  expected += "                          *     *                 \n";
  expected += "                          *     *                 \n";
  expected += "                          *     *                 \n";
  expected += "                          *******                 \n";
  expected += "--------------------------------------------------\n";

  Grid aGrid;

  Shape shape1 (5, 3, 5);
  shape1.draw(aGrid);

  Shape shape2 (26, 8, 7);
  shape2.draw(aGrid);

  shape1.draw(aGrid);
  shape2.draw(aGrid);

  shape1.move(23, 6);
  shape1.draw(aGrid);

  aGrid.write(actualOutput);
  EXPECT_EQ(expected, actualOutput.str());
}

TEST_F(Shape_Tests, MovePartiallyOutOfBounds)
{
  stringstream actualOutput;
  string expected = "";

  expected += "--------------------------------------------------\n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "     *****                                        \n";
  expected += "     *   *                                        \n";
  expected += "     *   *                                        \n";
  expected += "     *   *                                        \n";
  expected += "     *****                                        \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "     *****                                        \n";
  expected += "     *   *                                        \n";
  expected += "--------------------------------------------------\n";

  Grid aGrid;

  Shape shape (5, 3, 5);
  shape.draw(aGrid);

  shape.move(5, 13);
  shape.draw(aGrid);

  aGrid.write(actualOutput);
  EXPECT_EQ(expected, actualOutput.str());
}

TEST_F(Shape_Tests, MoveOutofBoundsShapeInBound)
{
  stringstream actualOutput;
  string expected = "";

  expected += "--------------------------------------------------\n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "     *****                                        \n";
  expected += "     *   *                                        \n";
  expected += "     *   *                                        \n";
  expected += "     *   *                                        \n";
  expected += "     *****                                        \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "--------------------------------------------------\n";

  Grid aGrid;

  Shape shape (-50, -30, 5);
  shape.draw(aGrid);

  shape.move(5, 3);
  shape.draw(aGrid);

  aGrid.write(actualOutput);
  EXPECT_EQ(expected, actualOutput.str());
}
