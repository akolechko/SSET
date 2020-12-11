#include "stdafx.h"
#include "convertor.h"

constexpr int kNumberOfTriples = 7;

Convertor::Convertor(const long long &number) : number_(number) {}

std::string Convertor::Convert() {
  bool is_positive = true;
  std::stack<std::string> numbers;
  std::string result = "";

  if (number_ == 0) return verbal_repr_[1];

  if (number_ < 0) {
    is_positive = false;
    number_ *= -1;
  }

  for (int i = 0; i < kNumberOfTriples; ++i) {
    for (int j = 0; j < 2; ++j) {
      if (i > 0 && j == 0 && number_ % 1000 != 0)
        numbers.push(verbal_repr_[29 + i]);

      int remainder = number_ % static_cast<int>(pow(10, 2 - j));

      if (remainder != 0) {
        if (j == 0) {
          if (remainder <= 20) {
            numbers.push(verbal_repr_[remainder + 1]);
          } else {
            if (remainder % 10 != 0)
              numbers.push(verbal_repr_[remainder % 10 + 1]);
            if (remainder % 100 - remainder % 10 != 0)
              numbers.push(verbal_repr_[remainder % 100 / 10 + 19]);
          }
        }

        if (j == 1) {
          numbers.push(verbal_repr_[29]);
          numbers.push(verbal_repr_[remainder + 1]);
        }
      }

      number_ /= static_cast<int>(pow(10, 2 - j));
    }
  }

  if (!is_positive) numbers.push(verbal_repr_[0]);

  while (!numbers.empty()) {
    result += numbers.top();
    numbers.pop();
  }

  return result;
}