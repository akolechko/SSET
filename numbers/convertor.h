#pragma once

class Convertor {
 public:
  Convertor() = default;
  explicit Convertor(long long number);

  void SetNumber(long long number);

  std::string Convert();

 private:
  enum SubnumberType { kTwoDigits, kOneDigit };

  void ConvertSubnumber(int type, int remainder,
                        std::stack<std::string>& numbers);

  long long number_ = 0;
  const std::string verbal_repr_[36] = {
      "minus",      "zero",    "one",     "two",       "three",
      "four",       "five",    "six",     "seven",     "eight",
      "nine",       "ten",     "eleven",  "twelve",    "thirteen",
      "fourteen",   "fifteen", "sixteen", "seventeen", "eighteen",
      "nineteen",   "twenty",  "thirty",  "forty",     "fifty",
      "sixty",      "seventy", "eighty",  "ninety",    "hundred",
      "thousand",   "million", "billion", "trillion",  "quadrillion",
      "quintillion"};
};
