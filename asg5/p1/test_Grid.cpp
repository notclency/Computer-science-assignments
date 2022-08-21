#include <iostream>
using namespace std;
#include <sstream>
#include <string>
#include "Grid.h"
#include <gtest/gtest.h>


class GridTests : public testing::Test
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

/*******************************************************************************
 *
 * Name:                Clency Tabe
 * Email:               ctabe297@mtroyal.ca
 * Course:              COMP 1633, 001
 * Assignment:          Assignment 5 part 1
 * Due Date:            April 8, 2022
 * Instructor name:     Paul Pospisil
 * File name:           test_Grid.cpp
 * Purpose:             This is a test module for the file "Grid.cpp". It tests
 *                      various elements and components of the file.
 * Assumptions:         All tests cases tests for the write function. That's how 
 *                      expected and actual output are compared
 *
 *******************************************************************************/


TEST_F(GridTests, DefaultConstructorTest)
{
  stringstream actualOutput;
  string expected = "";

  expected += "--------------------------------------------------\n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
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
  
  c.write(actualOutput);
  EXPECT_EQ(expected, actualOutput.str());
}

TEST_F(GridTests, TestOutputOperator)
{
  stringstream actualOutput;
  string expected = "";
  
  expected += "--------------------------------------------------\n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "  *                                               \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
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

  c.plot_point(2, 2);
  c.write(actualOutput);

  cout << (actualOutput, c);
  
  EXPECT_EQ(expected, actualOutput.str());
}

TEST_F(GridTests, TestPlot_PointOffGrid)
{
  stringstream actualOutput;
  string expected = "";
  
  expected += "--------------------------------------------------\n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
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
  
  c.plot_point(-100, -100);
  c.write(actualOutput);
  EXPECT_EQ(expected, actualOutput.str());
}


TEST_F(GridTests, TestPlot_PointOnGrid)
{
  stringstream actualOutput;
  string expected = "";

  // 1 point on the grid
  
  expected += "--------------------------------------------------\n";
  expected += "                                                  \n";
  expected += "  *                                               \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
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

  c.plot_point(2, 1);
  c.write(actualOutput);
  EXPECT_EQ(expected, actualOutput.str());

  // 2 or more points on the grid
  
  expected += "--------------------------------------------------\n";
  expected += "                                                  \n";
  expected += "  *                                               \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "*                                                 \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                * \n";
  expected += "                                                  \n";
  expected += "--------------------------------------------------\n";

  c.plot_point(2, 1);
  c.plot_point(48, 13);
  c.plot_point(0, 9);
  c.write(actualOutput);
  EXPECT_EQ(expected, actualOutput.str());
  
}

TEST_F(GridTests, TestTwoOrMoreOverwrittenPointsOnGrid)
{
  stringstream actualOutput;
  string expected = "";

  // 2 over written points on the grid
  
  expected += "--------------------------------------------------\n";
  expected += "                                                  \n";
  expected += "  *                                               \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
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

  c.plot_point(2, 1);
  c.plot_point(2, 1);
  c.write(actualOutput);
  EXPECT_EQ(expected, actualOutput.str());
}

TEST_F(GridTests, TestOutOfBoundsLine)
{
  stringstream actualOutput;
  string expected = "";

  expected += "--------------------------------------------------\n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
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

  c.plot_line(-20,-2, -6, -12);
  c.write(actualOutput);
  EXPECT_EQ(expected, actualOutput.str());
  
}

TEST_F(GridTests, TestPartiallyOutOfBoundsLine)
{
  stringstream actualOutput;
  string expected = "";

  expected += "--------------------------------------------------\n";
  expected += "                                                  \n";
  expected += "*******                                           \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
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

  c.plot_line(-20, 1, 6, 1);
  c.write(actualOutput);
  EXPECT_EQ(expected, actualOutput.str());
  
}

TEST_F(GridTests, TestDiagonalLine)
{
  stringstream actualOutput;
  string expected = "";

  expected += "--------------------------------------------------\n";
  expected += "                                                  \n";
  expected += "  *                                               \n";
  expected += "   *                                              \n";
  expected += "    *                                             \n";
  expected += "     *                                            \n";
  expected += "      *                                           \n";
  expected += "       *                                          \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "--------------------------------------------------\n";

  c.plot_line(7, 6, 2, 1);
  c.write(actualOutput);
  EXPECT_EQ(expected, actualOutput.str());
  
}

TEST_F(GridTests, TestInBoundStraightLine)
{
  stringstream actualOutput;
  string expected = "";

  expected += "--------------------------------------------------\n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "    *****************                             \n";
  expected += "                                                  \n";
  expected += "--------------------------------------------------\n";

  c.plot_line(4, 13, 20, 13);
  c.write(actualOutput);
  EXPECT_EQ(expected, actualOutput.str());
  
}

TEST_F(GridTests, TestOverWrittenLines)
{
  stringstream actualOutput;
  string expected = "";

  // EQUAL OVER WRITTEN LINES
  
  expected += "--------------------------------------------------\n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "    *****************                             \n";
  expected += "                                                  \n";
  expected += "--------------------------------------------------\n";

  c.plot_line(4, 13, 20, 13);
  c.plot_line(4, 13, 20, 13);
  c.write(actualOutput);
  EXPECT_EQ(expected, actualOutput.str());

  // NON EQUAL OVER WRITTEN LINES
  
  expected += "--------------------------------------------------\n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "    *******************                           \n";
  expected += "                                                  \n";
  expected += "--------------------------------------------------\n";

  c.plot_line(4, 13, 20, 13);
  c.plot_line(4, 13, 22, 13);
  c.write(actualOutput);
  EXPECT_EQ(expected, actualOutput.str());
  
}

TEST_F(GridTests, TestStraightIntersectingLines)
{
  stringstream actualOutput;
  string expected = "";

  // 2 straight lines intersecting
  
  expected += "--------------------------------------------------\n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                        *                         \n";
  expected += "                        *                         \n";
  expected += "                        *                         \n";
  expected += "                        *                         \n";
  expected += "                        *                         \n";
  expected += "           ******************************         \n";
  expected += "                        *                         \n";
  expected += "                        *                         \n";
  expected += "                        *                         \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "--------------------------------------------------\n";

  c.plot_line(11, 8, 40, 8);
  c.plot_line(24, 3, 24, 11);
  c.write(actualOutput);
  EXPECT_EQ(expected, actualOutput.str());

  // 3 straight lines intersecting

  expected += "--------------------------------------------------\n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                   *    *                         \n";
  expected += "                    *   *                         \n";
  expected += "                     *  *                         \n";
  expected += "                      * *                         \n";
  expected += "                       **                         \n";
  expected += "           ******************************         \n";
  expected += "                        **                        \n";
  expected += "                        * *                       \n";
  expected += "                        *  *                      \n";
  expected += "                            *                     \n";
  expected += "                             *                    \n";
  expected += "                                                  \n";
  expected += "--------------------------------------------------\n";

  c.plot_line(19, 3, 29, 13);
  c.write(actualOutput);
  EXPECT_EQ(expected, actualOutput.str());

}
