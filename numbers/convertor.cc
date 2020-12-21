#include "pch.h"

#include "convertor.h"

constexpr int kMinus = 0;
constexpr int kNumberOfTriples = 7;
constexpr int kTripleName = 29;
constexpr int kTwentyLimit = 20;
constexpr int kHundred = 29;

Convertor::Convertor(const long long& number) : number_(number) {}

std::string Convertor::Convert() {
  bool is_positive = true;
  std::stack<std::string> numbers;
  std::string result = "";

  if (number_ == 0) return verbal_repr_[1];

  if (number_ < 0) {
    is_positive = false;
    number_ *= -1;
  }

  // 123456789   - number
  // 123|456|789 - triples
  for (int triple = 0; triple < kNumberOfTriples; ++triple) {
    // 123  - triple
    // 1|23 - single/double
    // 123456789 => 1|23|4|56|7|89
    for (int single_double = kDouble; single_double < 2; ++single_double) {
      // Adds triple name (thousand, million, etc.)  after every triple
      if (triple > 0 && single_double == kDouble && number_ % 1000 != 0)
        numbers.push(verbal_repr_[kTripleName + triple]);

      int remainder = number_ % static_cast<int>(pow(10, 2 - single_double));

      if (remainder != 0) {
        SingleDoubleProcessor(single_double, remainder, numbers);
      }

      number_ /= static_cast<int>(pow(10, 2 - single_double));
    }
  }

  if (!is_positive) numbers.push(verbal_repr_[kMinus]);

  while (!numbers.empty()) {
    result += numbers.top();
    numbers.pop();
  }

  return result;
}

void Convertor::SingleDoubleProcessor(int type, int remainder,
                                      std::stack<std::string>& numbers) {
  if (type == kSingle) {
    numbers.push(verbal_repr_[kHundred]);
    numbers.push(verbal_repr_[remainder + 1]);
  }

  if (type == kDouble) {
    if (remainder <= kTwentyLimit) {
      numbers.push(verbal_repr_[remainder + 1]);
    } else {
      if (remainder % 10 != 0) numbers.push(verbal_repr_[remainder % 10 + 1]);
      if (remainder % 100 - remainder % 10 != 0)
        numbers.push(verbal_repr_[remainder % 100 / 10 + kTwentyLimit - 1]);
    }
  }
}
