#include <iostream>
using namespace std;
#include <sstream>
#include <string>
#include "Grid.h"
#include "Shape.h"
#include "Shape_Collection.h"
#include <gtest/gtest.h>


class Shape_Collection_Tests : public testing::Test
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
 * File name:        test_Shape_Collection.cpp
 * Purpose:          test the interaction between functions from the
 *                   files "Grid.h", "Shape.h" and "Shape_Collecton".
 * Assumptions:      SHAPE_COLLECTION ALL TETS CASES TESTS THE DRAW_SHAPES
 *                   FUNCTION. THATS HOW EXPECTED AND ACTUAL OUPUT ARE
 *                   COMPARED
 * Limitations:      100% COVERAGE IS IMPOSSIBLE BECUASE OF THE TWO
 *                   PRIVATE FUNCTIONS THAT ARE STUBS AND NO PUBLIC
 *                   FUNCTION USES THEM
 * 
 **********************************************************************/


TEST_F(Shape_Collection_Tests, TestShapeCollectionConstructor)
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

  Shape_Collection myShapes;
  
  myShapes.draw_shapes(actualOutput);
  
  EXPECT_EQ(expected, actualOutput.str());
}

TEST_F(Shape_Collection_Tests, TestShapeCollectionAddShape)
{
  stringstream actualOutput;
  string expected = "";
  
  expected += "--------------------------------------------------\n";
  expected += "                                                  \n";
  expected += " *****                                            \n";
  expected += " *   *                                            \n";
  expected += " *   *                                            \n";
  expected += " *   *                                            \n";
  expected += " *****              *****                         \n";
  expected += "                    *   *                         \n";
  expected += "                    *   *                         \n";
  expected += "                    *   *                         \n";
  expected += " *****              *****                         \n";
  expected += " *   *                                            \n";
  expected += " *   *                                            \n";
  expected += " *   *                                            \n";
  expected += " *****                                            \n";
  expected += "                                                  \n";
  expected += "--------------------------------------------------\n";
  
  Shape_Collection myShapes;
  Shape *aShape;

  aShape = new Shape(1,1,5);
  myShapes.add(aShape, "S1");

  aShape = new Shape(1,9,5);
  myShapes.add(aShape, "S2");

  aShape = new Shape(20,5,5);
  myShapes.add(aShape, "S3");
  
  myShapes.draw_shapes(actualOutput);
  
  EXPECT_EQ(expected, actualOutput.str());
}

TEST_F(Shape_Collection_Tests, TestShapeCollectionAddNonExistingShape)
{

  // 1 SHAPE
  
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
  
  Shape_Collection myShapes;
  Shape *aShape;

  aShape = new Shape(1,1,5);
  myShapes.add(aShape, "S1");

  myShapes.draw_shapes(actualOutput);
  
  EXPECT_EQ(expected, actualOutput.str());

  // 2 OR MORE SHAPES

  expected += "--------------------------------------------------\n";
  expected += "                                                  \n";
  expected += " *****                                            \n";
  expected += " *   *                                            \n";
  expected += " *   *                                            \n";
  expected += " *   *                                            \n";
  expected += " *****              *****                         \n";
  expected += "                    *   *                         \n";
  expected += "                    *   *                         \n";
  expected += "                    *   *                         \n";
  expected += " *****              *****                         \n";
  expected += " *   *                                            \n";
  expected += " *   *                                            \n";
  expected += " *   *                                            \n";
  expected += " *****                                            \n";
  expected += "                                                  \n";
  expected += "--------------------------------------------------\n";

  aShape = new Shape(1,9,5);
  myShapes.add(aShape, "S2");

  aShape = new Shape(20,5,5);
  myShapes.add(aShape, "S3");
  
  myShapes.draw_shapes(actualOutput);
  
  EXPECT_EQ(expected, actualOutput.str());
}

TEST_F(Shape_Collection_Tests, TestShapeCollectionRemoveExistingShape)
{
  stringstream actualOutput;
  string expected = "";
  
  expected += "--------------------------------------------------\n";
  expected += "                                                  \n";
  expected += " *****                                            \n";
  expected += " *   *                                            \n";
  expected += " *   *                                            \n";
  expected += " *   *                                            \n";
  expected += " *****              *****                         \n";
  expected += "                    *   *                         \n";
  expected += "                    *   *                         \n";
  expected += "                    *   *                         \n";
  expected += "                    *****                         \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "--------------------------------------------------\n";
  
  Shape_Collection myShapes;
  Shape *aShape;

  aShape = new Shape(1,1,5);
  myShapes.add(aShape, "S1");

  aShape = new Shape(1,9,5);
  myShapes.add(aShape, "S2");

  aShape = new Shape(20,5,5);
  myShapes.add(aShape, "S3");

  myShapes.remove("S2");
  
  myShapes.draw_shapes(actualOutput);
  
  EXPECT_EQ(expected, actualOutput.str());
}

TEST_F(Shape_Collection_Tests, TestShapeCollectionRemoveNonExistingShape)
{
  stringstream actualOutput;
  string expected = "";
  
  expected += "--------------------------------------------------\n";
  expected += "                                                  \n";
  expected += " *****                                            \n";
  expected += " *   *                                            \n";
  expected += " *   *                                            \n";
  expected += " *   *                                            \n";
  expected += " *****              *****                         \n";
  expected += "                    *   *                         \n";
  expected += "                    *   *                         \n";
  expected += "                    *   *                         \n";
  expected += " *****              *****                         \n";
  expected += " *   *                                            \n";
  expected += " *   *                                            \n";
  expected += " *   *                                            \n";
  expected += " *****                                            \n";
  expected += "                                                  \n";
  expected += "--------------------------------------------------\n";
  
  Shape_Collection myShapes;
  Shape *aShape;

  aShape = new Shape(1,1,5);
  myShapes.add(aShape, "S1");

  aShape = new Shape(1,9,5);
  myShapes.add(aShape, "S2");

  aShape = new Shape(20,5,5);
  myShapes.add(aShape, "S3");

  myShapes.remove("S4");
  
  myShapes.draw_shapes(actualOutput);
  
  EXPECT_EQ(expected, actualOutput.str());
}

TEST_F(Shape_Collection_Tests, TestShapeCollectionLookupExistingShape)
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
  expected += " *****                                            \n";
  expected += " *   *                                            \n";
  expected += " *   *                                            \n";
  expected += " *   *                                            \n";
  expected += " *****                                            \n";
  expected += "                                                  \n";
  expected += "--------------------------------------------------\n";
  
  Shape_Collection myShapes;
  Shape *aShape;

  Shape *found = NULL;
  
  aShape = new Shape(1,9,5);
  myShapes.add(aShape, "S1");

  found = myShapes.lookup("S1");
  
  myShapes.draw_shapes(actualOutput);
  EXPECT_EQ(found, aShape);
}

TEST_F(Shape_Collection_Tests, TestShapeCollectionLookupNonExistingShape)
{
  stringstream actualOutput;
  string expected = "";
  
  expected += "--------------------------------------------------\n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                                                  \n";
  expected += "                    *****                         \n";
  expected += "                    *   *                         \n";
  expected += "                    *   *                         \n";
  expected += "                    *   *                         \n";
  expected += " *****              *****                         \n";
  expected += " *   *                                            \n";
  expected += " *   *                                            \n";
  expected += " *   *                                            \n";
  expected += " *****                                            \n";
  expected += "                                                  \n";
  expected += "--------------------------------------------------\n";
  
  Shape_Collection myShapes;
  Shape *aShape;

  Shape *found = NULL;
  
  aShape = new Shape(1,9,5);
  myShapes.add(aShape, "S1");

  aShape = new Shape(20,5,5);
  myShapes.add(aShape, "S2");

  aShape = myShapes.lookup("S3");
  
  myShapes.draw_shapes(actualOutput);
  
  EXPECT_EQ(found, aShape);
}

TEST_F(Shape_Collection_Tests, TestShapeCollectionLookupEmptyShapeCollection)
{
  Shape_Collection myShapes;
  Shape *aShape;

  Shape *found = NULL;
  
  aShape = myShapes.lookup("S1");
  
  EXPECT_EQ(found, aShape);
}

TEST_F(Shape_Collection_Tests, TestShapeCollectionWriteNamesOnNonEmptyShapeCollection)
{  
  Shape_Collection myShapes;
  Shape *aShape;

  stringstream actualOutput;
  string expected = "[S3,S2,S1]";
  
  aShape = new Shape(1,1,5);
  myShapes.add(aShape, "S1");

  aShape = new Shape(1,9,5);
  myShapes.add(aShape, "S2");

  aShape = new Shape(20,5,5);
  myShapes.add(aShape, "S3");
  
  myShapes.write_names(actualOutput);
  
  EXPECT_EQ(expected, actualOutput.str());
}

TEST_F(Shape_Collection_Tests, TestShapeCollectionWriteNamesOnEmptyShapeCollection)
{
  stringstream actualOutput;
  string expected = "[]";
   
  Shape_Collection myShapes;

  myShapes.write_names(actualOutput);
  
  EXPECT_EQ(expected, actualOutput.str());
}

TEST_F(Shape_Collection_Tests, TestDrawShapesOnEmptyShapeCollection)
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
  
  Shape_Collection myShapes;
  
  myShapes.draw_shapes(actualOutput);
  
  EXPECT_EQ(expected, actualOutput.str());
}

TEST_F(Shape_Collection_Tests, TestDrawShapesOnNonEmptyShapeCollection_)
{
  stringstream actualOutput;
  string expected = "";
  
  expected += "--------------------------------------------------\n";
  expected += "                                                  \n";
  expected += " *****                                            \n";
  expected += " *   *                                            \n";
  expected += " *   *                                            \n";
  expected += " *   *                                            \n";
  expected += " *****              *****                         \n";
  expected += "                    *   *                         \n";
  expected += "                    *   *                         \n";
  expected += "                    *   *                         \n";
  expected += " *****              *****                         \n";
  expected += " *   *                                            \n";
  expected += " *   *                                            \n";
  expected += " *   *                                            \n";
  expected += " *****                                            \n";
  expected += "                                                  \n";
  expected += "--------------------------------------------------\n";
  
  Shape_Collection myShapes;
  Shape *aShape;

  aShape = new Shape(1,1,5);
  myShapes.add(aShape, "S1");

  aShape = new Shape(1,9,5);
  myShapes.add(aShape, "S2");

  aShape = new Shape(20,5,5);
  myShapes.add(aShape, "S3");
  
  myShapes.draw_shapes(actualOutput);
  
  EXPECT_EQ(expected, actualOutput.str());
}
