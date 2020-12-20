#include "pch.h"

#include "../numerical_sequence/generator.h"

// Constructor, operator*, End()

TEST(TestGenerator, EmptyCtor) {
  Generator generator;

  EXPECT_EQ(0, *generator);
  EXPECT_EQ(0, generator.End());
}

TEST(TestGenerator, OneEntryCtor) {
  unsigned long long entry0 = 10;
  unsigned long long entry1 = 0;
  unsigned long long entry2 = 99999999999;

  Generator generator0(entry0);
  Generator generator1(entry1);
  Generator generator2(entry2);

  EXPECT_EQ(0, *generator0);
  EXPECT_EQ(0, *generator1);
  EXPECT_EQ(0, *generator2);
  EXPECT_EQ(entry0, generator0.End());
  EXPECT_EQ(entry1, generator1.End());
  EXPECT_EQ(entry2, generator2.End());
}

TEST(TestGenerator, TwoEntriesCtor) {
  unsigned long long entry0 = 10;
  unsigned long long entry1 = 0;
  unsigned long long entry2 = 99999999999;
  unsigned long long entry3 = 89;
  unsigned long long entry4 = 10000000000000;
  unsigned long long entry5 = 123456789;

  Generator generator0(entry0, entry1);
  Generator generator1(entry2, entry3);
  Generator generator2(entry4, entry5);

  EXPECT_EQ(entry0, *generator0);
  EXPECT_EQ(entry2, *generator1);
  EXPECT_EQ(entry4, *generator2);
  EXPECT_EQ(entry1, generator0.End());
  EXPECT_EQ(entry3, generator1.End());
  EXPECT_EQ(entry5, generator2.End());
}

// Next(), operator*

TEST(TestGenerator, Next) {
  unsigned long long entry0 = 10;
  unsigned long long entry1 = 0;
  unsigned long long entry2 = 999999999;
  unsigned long long entry3 = 8767679;
  unsigned long long entry4 = 6170670767;
  unsigned long long entry5 = 6899;

  Generator generator0(entry0, entry1);
  Generator generator1(entry2, entry3);
  Generator generator2(entry4, entry5);

  generator0.Next();
  EXPECT_EQ(++entry0, *generator0);
  generator0.Next();
  EXPECT_EQ(++entry0, *generator0);
  generator1.Next();
  EXPECT_EQ(++entry2, *generator1);
  generator1.Next();
  EXPECT_EQ(++entry2, *generator1);
  generator2.Next();
  EXPECT_EQ(++entry4, *generator2);
  generator2.Next();
  EXPECT_EQ(++entry4, *generator2);
}

// operator++, operator*

TEST(TestGenerator, PreIncrement) {
  unsigned long long entry0 = 0;
  unsigned long long entry1 = 0;
  unsigned long long entry2 = 3333333;
  unsigned long long entry3 = 9999999999999999999;
  unsigned long long entry4 = 88005553535;
  unsigned long long entry5 = 123456789;

  Generator generator0(entry0, entry1);
  Generator generator1(entry2, entry3);
  Generator generator2(entry4, entry5);

  ++generator0;
  EXPECT_EQ(++entry0, *generator0);
  ++generator0;
  EXPECT_EQ(++entry0, *generator0);
  ++generator1;
  EXPECT_EQ(++entry2, *generator1);
  ++generator1;
  EXPECT_EQ(++entry2, *generator1);
  ++generator2;
  EXPECT_EQ(++entry4, *generator2);
  ++generator2;
  EXPECT_EQ(++entry4, *generator2);
}
