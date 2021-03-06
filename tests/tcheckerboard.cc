#include "pch.h"

#include "../checkerboard/checkerboard.h"

TEST(TCheckerBoard, GetStrRepr) {
  CheckerBoard board = {2, 4};
  const std::string result = board.GetStrRepr();
  const std::string expected =
      "* \n"
      " *\n"
      "* \n"
      " *\n";

  ASSERT_TRUE(expected == result);
}