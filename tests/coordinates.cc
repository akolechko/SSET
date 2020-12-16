#include "pch.h"
#include "../checkerboard/coordinates.cc"

TEST(TestCoordinates, AreValid) {
  CheckerBoard board = {8, 8};
  Coordinates coordinates = {7, 12};

  EXPECT_FALSE(coordinates.AreValid(board));
}                                      