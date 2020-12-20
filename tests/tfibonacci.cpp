#include "pch.h"

#include "../fibonacci/fibonacci_generator.h"

// Constructor, operator*, End()

TEST(TestFibonacciGenerator, EmptyCtor) {
  FibonacciGenerator generator;

  EXPECT_EQ(1, *generator);
  EXPECT_EQ(0, generator.End());
}

TEST(TestFibonacciGenerator, OneEntryCtor) {
  unsigned long long entry0 = 10;
  unsigned long long entry1 = 0;
  unsigned long long entry2 = 99999999999;

  FibonacciGenerator generator0(entry0);
  FibonacciGenerator generator1(entry1);
  FibonacciGenerator generator2(entry2);

  EXPECT_EQ(1, *generator0);
  EXPECT_EQ(1, *generator1);
  EXPECT_EQ(1, *generator2);
  EXPECT_EQ(entry0, generator0.End());
  EXPECT_EQ(entry1, generator1.End());
  EXPECT_EQ(entry2, generator2.End());
}

TEST(TestFibonacciGenerator, TwoEntriesCtor) {
  unsigned long long entry0 = 10;
  unsigned long long entry1 = 0;
  unsigned long long entry2 = 99999999999;
  unsigned long long entry3 = 89;
  unsigned long long entry4 = 10000000000000;
  unsigned long long entry5 = 123456789;

  unsigned long long expected0 = 13;
  unsigned long long expected1 = 139583862445;
  unsigned long long expected2 = 10610209857723;

  FibonacciGenerator generator0(entry0, entry1);
  FibonacciGenerator generator1(entry2, entry3);
  FibonacciGenerator generator2(entry4, entry5);

  EXPECT_EQ(expected0, *generator0);
  EXPECT_EQ(expected1, *generator1);
  EXPECT_EQ(expected2, *generator2);
  EXPECT_EQ(entry1, generator0.End());
  EXPECT_EQ(entry3, generator1.End());
  EXPECT_EQ(entry5, generator2.End());
}

// Next(), operator*

TEST(TestFibonacciGenerator, Next) {
  unsigned long long entry0 = 10;
  unsigned long long entry1 = 0;
  unsigned long long entry2 = 999999999;
  unsigned long long entry3 = 8767679;
  unsigned long long entry4 = 6170670767;
  unsigned long long entry5 = 6899;

  unsigned long long expected0 = 21;
  unsigned long long expected1 = 34;
  unsigned long long expected2 = 1836311903;
  unsigned long long expected3 = 2971215073;
  unsigned long long expected4 = 12586269025;
  unsigned long long expected5 = 20365011074;

  FibonacciGenerator generator0(entry0, entry1);
  FibonacciGenerator generator1(entry2, entry3);
  FibonacciGenerator generator2(entry4, entry5);

  generator0.Next();
  EXPECT_EQ(expected0, *generator0);
  generator0.Next();
  EXPECT_EQ(expected1, *generator0);
  generator1.Next();
  EXPECT_EQ(expected2, *generator1);
  generator1.Next();
  EXPECT_EQ(expected3, *generator1);
  generator2.Next();
  EXPECT_EQ(expected4, *generator2);
  generator2.Next();
  EXPECT_EQ(expected5, *generator2);
}

// operator++, operator*

TEST(TestFibonacciGenerator, PreIncrement) {
  unsigned long long entry0 = 0;
  unsigned long long entry1 = 0;
  unsigned long long entry2 = 3333333;
  unsigned long long entry3 = 9999999999999999999;
  unsigned long long entry4 = 88005553535;
  unsigned long long entry5 = 123456789;

  unsigned long long expected0 = 1;
  unsigned long long expected1 = 2;
  unsigned long long expected2 = 5702887;
  unsigned long long expected3 = 9227465;
  unsigned long long expected4 = 225851433717;
  unsigned long long expected5 = 365435296162;

  FibonacciGenerator generator0(entry0, entry1);
  FibonacciGenerator generator1(entry2, entry3);
  FibonacciGenerator generator2(entry4, entry5);

  ++generator0;
  EXPECT_EQ(expected0, *generator0);
  ++generator0;
  EXPECT_EQ(expected1, *generator0);
  ++generator1;
  EXPECT_EQ(expected2, *generator1);
  ++generator1;
  EXPECT_EQ(expected3, *generator1);
  ++generator2;
  EXPECT_EQ(expected4, *generator2);
  ++generator2;
  EXPECT_EQ(expected5, *generator2);
}
