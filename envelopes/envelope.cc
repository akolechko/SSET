#include "pch.h"

#include "envelope.h"

Envelope::Envelope(double a, double b) { SetSize(a, b); }

std::array<double, 2> Envelope::GetSize() const { return sides_; }

void Envelope::SetSize(double a, double b) {
  sides_ = {a, b};
  std::sort(sides_.begin(), sides_.end());
}
