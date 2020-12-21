#include "pch.h"

#include "../numbers/convertor.h"

// Constructor, Convert()

TEST(TestConvertor, EmptyCtor) {
  Convertor convertor;

  EXPECT_STREQ("zero", convertor.Convert().c_str());
}

// Convert()

TEST(TestConvertor, Convert) {
  // 0 == zero
  long long entry0 = 0;
  // "Thousand", "million", "billion" etc.
  long long entry1 = 1;  // Must not add anything
  long long entry2 = 12;
  long long entry3 = 123;
  long long entry4 = 1'234;      // Thousand
  long long entry5 = 1'234'567;  // Thousand, million
  long long entry6 = 1'000'567;  // Only million
  // "Hundred" - every third digit but zero
  long long entry7 = 12;    // No
  long long entry8 = 123;   // Yes
  long long entry9 = 1000;  // No
  // Print every third number but zero
  long long entry10 = 987;
  long long entry11 = 987'654'321;
  long long entry12 = 87'054'021;
  // Correct converting doubles before 20
  long long entry13 = 7;
  long long entry14 = 10;
  long long entry15 = 19;
  long long entry16 = 40'001'500'011'806;
  // Random
  long long entry17 = 5'794'200'061'416;
  long long entry18 = 9'000'000'000'000;

  const char expected0[] = "zero";
  const char expected1[] = "one ";
  const char expected2[] = "twelve ";
  const char expected3[] = "one hundred twenty three ";
  const char expected4[] = "one thousand two hundred thirty four ";
  const char expected5[] =
      "one million two hundred thirty four thousand five hundred sixty seven ";
  const char expected6[] = "one million five hundred sixty seven ";
  const char expected7[] = "twelve ";
  const char expected8[] = "one hundred twenty three ";
  const char expected9[] = "one thousand ";
  const char expected10[] = "nine hundred eighty seven ";
  const char expected11[] =
      "nine hundred eighty seven million six hundred fifty four thousand three "
      "hundred twenty one ";
  const char expected12[] =
      "eighty seven million fifty four thousand twenty one ";
  const char expected13[] = "seven ";
  const char expected14[] = "ten ";
  const char expected15[] = "nineteen ";
  const char expected16[] =
      "forty trillion one billion five hundred million eleven thousand eight "
      "hundred six ";
  const char expected17[] =
      "five trillion seven hundred ninety four billion two hundred million "
      "sixty one thousand four hundred sixteen ";
  const char expected18[] = "nine trillion ";

  Convertor convertor0(entry0);
  Convertor convertor1(entry1);
  Convertor convertor2(entry2);
  Convertor convertor3(entry3);
  Convertor convertor4(entry4);
  Convertor convertor5(entry5);
  Convertor convertor6(entry6);
  Convertor convertor7(entry7);
  Convertor convertor8(entry8);
  Convertor convertor9(entry9);
  Convertor convertor10(entry10);
  Convertor convertor11(entry11);
  Convertor convertor12(entry12);
  Convertor convertor13(entry13);
  Convertor convertor14(entry14);
  Convertor convertor15(entry15);
  Convertor convertor16(entry16);
  Convertor convertor17(entry17);
  Convertor convertor18(entry18);

  EXPECT_STREQ(expected0, convertor0.Convert().c_str());
  EXPECT_STREQ(expected1, convertor1.Convert().c_str());
  EXPECT_STREQ(expected2, convertor2.Convert().c_str());
  EXPECT_STREQ(expected3, convertor3.Convert().c_str());
  EXPECT_STREQ(expected4, convertor4.Convert().c_str());
  EXPECT_STREQ(expected5, convertor5.Convert().c_str());
  EXPECT_STREQ(expected6, convertor6.Convert().c_str());
  EXPECT_STREQ(expected7, convertor7.Convert().c_str());
  EXPECT_STREQ(expected8, convertor8.Convert().c_str());
  EXPECT_STREQ(expected9, convertor9.Convert().c_str());
  EXPECT_STREQ(expected10, convertor10.Convert().c_str());
  EXPECT_STREQ(expected11, convertor11.Convert().c_str());
  EXPECT_STREQ(expected12, convertor12.Convert().c_str());
  EXPECT_STREQ(expected13, convertor13.Convert().c_str());
  EXPECT_STREQ(expected14, convertor14.Convert().c_str());
  EXPECT_STREQ(expected15, convertor15.Convert().c_str());
  EXPECT_STREQ(expected16, convertor16.Convert().c_str());
  EXPECT_STREQ(expected17, convertor17.Convert().c_str());
  EXPECT_STREQ(expected18, convertor18.Convert().c_str());
}