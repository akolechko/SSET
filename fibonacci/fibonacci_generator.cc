#include "pch.h"

#include "fibonacci_generator.h"

FibonacciGenerator::FibonacciGenerator() : end_(0) {}

FibonacciGenerator::FibonacciGenerator(unsigned long long end) : end_(end) {}

FibonacciGenerator::FibonacciGenerator(unsigned long long begin,
                                       unsigned long long end)
    : end_(end) {
  while (current_ < begin) Next();
}

unsigned long long FibonacciGenerator::End() { return end_; }

void FibonacciGenerator::Next() {
  previous_ = previous_ + current_;
  current_ = previous_ - current_;
  previous_ = previous_ - current_;
  current_ = previous_ + current_;
}

unsigned long long FibonacciGenerator::operator*() { return current_; }

FibonacciGenerator& FibonacciGenerator::operator++() {
  Next();

  return *this;
}
