#include "pch.h"

#include "../numbers/convertor.h"

// Constructor, Convert()

TEST(TestConvertor, EmptyCtor) {
  Convertor convertor;

  EXPECT_STREQ("zero", convertor.Convert().c_str());
}

// Convert()

TEST(TestConvertor, Convert) {
  std::vector<long long> entries;
  entries.push_back(0);
  entries.push_back(1);
  entries.push_back(12);
  entries.push_back(123);
  entries.push_back(1'234);
  entries.push_back(1'234'567);
  entries.push_back(1'000'567);
  entries.push_back(12);
  entries.push_back(123);
  entries.push_back(1'000);
  entries.push_back(987);
  entries.push_back(987'654'321);
  entries.push_back(87'054'021);
  entries.push_back(7);
  entries.push_back(10);
  entries.push_back(19);
  entries.push_back(40'001'500'011'806);
  entries.push_back(5'794'200'061'416);
  entries.push_back(9'000'000'000'000);

  std::vector<char*> expected;
  expected.push_back("zero");
  expected.push_back("one ");
  expected.push_back("twelve ");
  expected.push_back("one hundred twenty three ");
  expected.push_back("one thousand two hundred thirty four ");
  expected.push_back(
      "one million two hundred thirty four thousand five hundred sixty seven ");
  expected.push_back("one million five hundred sixty seven ");
  expected.push_back("twelve ");
  expected.push_back("one hundred twenty three ");
  expected.push_back("one thousand ");
  expected.push_back("nine hundred eighty seven ");
  expected.push_back(
      "nine hundred eighty seven million six hundred fifty four thousand three "
      "hundred twenty one ");
  expected.push_back("eighty seven million fifty four thousand twenty one ");
  expected.push_back("seven ");
  expected.push_back("ten ");
  expected.push_back("nineteen ");
  expected.push_back(
      "forty trillion one billion five hundred million eleven thousand eight "
      "hundred six ");
  expected.push_back(
      "five trillion seven hundred ninety four billion two hundred million "
      "sixty one thousand four hundred sixteen ");
  expected.push_back("nine trillion ");

   for (int i = 0; i < 19; ++i) {
    Convertor* convertor = new Convertor(entries[i]);
    EXPECT_STREQ(expected[i], convertor->Convert().c_str());
    delete convertor;
  }
}
