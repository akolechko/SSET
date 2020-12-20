#include "pch.h"

#include "generator.h"

Generator::Generator() : end_(0) {}

Generator::Generator(unsigned long long end) : end_(end) {}

Generator::Generator(unsigned long long begin, unsigned long long end)
    : current_(begin), end_(end) {}

unsigned long long Generator::End() { return end_; }

void Generator::Next() { ++current_; }

unsigned long long Generator::operator*() { return current_; }

Generator& Generator::operator++() {
  Next();

  return *this;
}
