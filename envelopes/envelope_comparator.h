#pragma once

#include "envelope.h"

class EnvelopeComparator {
 public:
  EnvelopeComparator(Envelope& first, Envelope& second);

  bool Fit() const;

 private:
  enum SideSize { kSmallSide, kBigSide };

  Envelope& first_;
  Envelope& second_;
};
