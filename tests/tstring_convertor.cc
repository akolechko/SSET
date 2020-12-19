#include "pch.h"

#include "../checkerboard/string_convertor.h"

TEST(TStringConvertor, NondigitCharacters) {
  int result = 0;

  validation::StringConvertor convertor("123k");
  validation::ErrorCode error = convertor.StringToInt(result);

  EXPECT_EQ(validation::ErrorCode::kInvalidArgument, error);
  EXPECT_EQ(0, result);
}