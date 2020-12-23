#pragma once

class FibonacciGenerator {
 public:
  FibonacciGenerator();
  FibonacciGenerator(unsigned long long end);
  FibonacciGenerator(unsigned long long begin, unsigned long long end);

  [[nodiscard]] unsigned long long End() const;

  void Next();

  unsigned long long operator*();
  FibonacciGenerator& operator++();

 private:
  unsigned long long previous_ = 0;
  unsigned long long current_ = 1;
  unsigned long long end_;
};
