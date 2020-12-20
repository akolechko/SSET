#include "pch.h"

#include "../envelopes/envelope_comparator.h"

// Fit()

TEST(TestEnvelopeComparator, FitTrue) {
  Envelope envelope0;
  Envelope envelope1;
  Envelope envelope2(99999999.9999999, 99999999.9999999);
  Envelope envelope3(99999999.99999999, 99999999.99999999);
  Envelope envelope4(1, 1000000000);
  Envelope envelope5(1000000000, 0.9);

  EnvelopeComparator comparator0(envelope0, envelope1);
  EnvelopeComparator comparator1(envelope2, envelope3);
  EnvelopeComparator comparator2(envelope4, envelope5);

  EXPECT_TRUE(comparator0.Fit());
  EXPECT_TRUE(comparator1.Fit());
  EXPECT_TRUE(comparator2.Fit());
}

TEST(TestEnvelopeComparator, FitFalse) {
  Envelope envelope0(5, 2);
  Envelope envelope1(3, 4);
  Envelope envelope2(100000000, 99999999.99999);
  Envelope envelope3(99999999.9999999, 99999999.99999999);
  Envelope envelope4(1, 1000000000);
  Envelope envelope5(100000000, 1.1);

  EnvelopeComparator comparator0(envelope0, envelope1);
  EnvelopeComparator comparator1(envelope2, envelope3);
  EnvelopeComparator comparator2(envelope4, envelope5);

  EXPECT_FALSE(comparator0.Fit());
  EXPECT_FALSE(comparator1.Fit());
  EXPECT_FALSE(comparator2.Fit());
}