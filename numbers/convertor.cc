#include "pch.h"

#include "convertor.h"

constexpr int kMinus = 0;
constexpr int kNumberOfTriples = 7;
constexpr int kTwentyLimit = 20;
constexpr int kTripleName = 30;
constexpr int kHundred = 29;

Convertor::Convertor(long long number) : number_(number) {}

void Convertor::SetNumber(long long number) { number_ = number; }

std::vector<std::string> Convertor::Convert() {
  bool is_positive = true;
  int remainder = 0;
  std::stack<std::string> subnumbers;
  std::vector<std::string> result;

  if (!number_) {
    result.push_back(verbal_repr_[1]);

    return result;
  }

  if (number_ < 0) {
    is_positive = false;
    number_ *= -1;
  }

  for (int triple_count = 0; triple_count < kNumberOfTriples; ++triple_count) {
    for (int subnumber = kTwoDigits; subnumber < 2; ++subnumber) {
      if (triple_count && subnumber == kTwoDigits && number_ % 1000)
        subnumbers.push(verbal_repr_[kTripleName + triple_count - 1]);

      subnumber == kTwoDigits ? remainder = number_ % 100
                              : remainder = number_ % 10;

      if (remainder) ConvertSubnumber(subnumber, remainder, subnumbers);

      subnumber == kTwoDigits ? number_ /= 100 : number_ /= 10;
    }
  }

  if (!is_positive) subnumbers.push(verbal_repr_[kMinus]);

  while (!subnumbers.empty()) {
    result.push_back(subnumbers.top());
    subnumbers.pop();
  }

  return result;
}

void Convertor::ConvertSubnumber(int type, int remainder,
                                 std::stack<std::string>& numbers) {
  if (type == kOneDigit) {
    numbers.push(verbal_repr_[kHundred]);
    numbers.push(verbal_repr_[remainder + 1]);
  }

  if (type == kTwoDigits) {
    if (remainder <= kTwentyLimit) {
      numbers.push(verbal_repr_[remainder + 1]);
    } else {
      if (remainder % 10) numbers.push(verbal_repr_[remainder % 10 + 1]);
      if (remainder % 100 - remainder % 10)
        numbers.push(verbal_repr_[remainder % 100 / 10 + kTwentyLimit - 1]);
    }
  }
}
