#include "pch.h"

#include "../envelopes/envelope.h"

// Constructor, GetSize()

TEST(TestEnvelope, EmptyCtor) {
  Envelope envelope;

  EXPECT_DOUBLE_EQ(0, envelope.GetSize()[0]);
  EXPECT_DOUBLE_EQ(0, envelope.GetSize()[1]);
}

TEST(TestEnvelope, OneEntryCtor) {
  double entry = 20;

  Envelope envelope(entry);

  EXPECT_DOUBLE_EQ(0, envelope.GetSize()[0]);
  EXPECT_DOUBLE_EQ(entry, envelope.GetSize()[1]);
}

TEST(TestEnvelope, TwoEntriesCtor) {
  double entry0 = 20;
  double entry1 = 10;

  Envelope envelope(entry0, entry1);

  EXPECT_DOUBLE_EQ(entry1, envelope.GetSize()[0]);
  EXPECT_DOUBLE_EQ(entry0, envelope.GetSize()[1]);
}

// SetSize(), GetSize()

TEST(TestEnvelope, SetSizeLessGreater) {
  double entry0 = 99.99999999;
  double entry1 = 100;
  double entry2 = 0;
  double entry3 = 0;
  double entry4 = 0;
  double entry5 = 1;

  Envelope envelope0;
  Envelope envelope1;
  Envelope envelope2;

  envelope0.SetSize(entry0, entry1);
  envelope1.SetSize(entry2, entry3);
  envelope2.SetSize(entry4, entry5);

  EXPECT_DOUBLE_EQ(entry0, envelope0.GetSize()[0]);
  EXPECT_DOUBLE_EQ(entry1, envelope0.GetSize()[1]);
  EXPECT_DOUBLE_EQ(entry2, envelope1.GetSize()[0]);
  EXPECT_DOUBLE_EQ(entry3, envelope1.GetSize()[1]);
  EXPECT_DOUBLE_EQ(entry4, envelope2.GetSize()[0]);
  EXPECT_DOUBLE_EQ(entry5, envelope2.GetSize()[1]);
}

TEST(TestEnvelope, SetSizeGreaterLess) {
  double entry0 = 9999999.99999999999999;
  double entry1 = 9999999.99999999999998;
  double entry2 = 0.0000000000002;
  double entry3 = 0.0000000000001;
  double entry4 = 1;
  double entry5 = 0;

  Envelope envelope0;
  Envelope envelope1;
  Envelope envelope2;

  envelope0.SetSize(entry0, entry1);
  envelope1.SetSize(entry2, entry3);
  envelope2.SetSize(entry4, entry5);

  EXPECT_DOUBLE_EQ(entry0, envelope0.GetSize()[1]);
  EXPECT_DOUBLE_EQ(entry1, envelope0.GetSize()[0]);
  EXPECT_DOUBLE_EQ(entry2, envelope1.GetSize()[1]);
  EXPECT_DOUBLE_EQ(entry3, envelope1.GetSize()[0]);
  EXPECT_DOUBLE_EQ(entry4, envelope2.GetSize()[1]);
  EXPECT_DOUBLE_EQ(entry5, envelope2.GetSize()[0]);
}
