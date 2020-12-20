#include "pch.h"

#include "envelope_comparator.h"

EnvelopeComparator::EnvelopeComparator(Envelope& first, Envelope& second)
    : first_(first), second_(second) {}

bool EnvelopeComparator::Fit() const {
  return first_.GetSize()[kSmallSide] <= second_.GetSize()[kSmallSide] &&
             first_.GetSize()[kBigSide] <= second_.GetSize()[kBigSide] ||
         first_.GetSize()[kSmallSide] >= second_.GetSize()[kSmallSide] &&
             first_.GetSize()[kBigSide] >= second_.GetSize()[kBigSide];
}