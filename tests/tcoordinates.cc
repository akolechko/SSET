#include "pch.h"

#include "../checkerboard/coordinates.h"

TEST(TCoordinates, AreValid) {
  CheckerBoard board = {8, 8};
  Coordinates coordinates = {7, 12};

  EXPECT_FALSE(coordinates.AreValid(board));
}