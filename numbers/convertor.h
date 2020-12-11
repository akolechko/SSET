#pragma once

class Convertor {
 public:
  Convertor(const long long &number = 0);

  std::string Convert();

 private:
  long long number_;
  const std::string verbal_repr_[36] = {
      "minus ",      "zero",     "one ",     "two ",       "three ",
      "four ",       "five ",    "six ",     "seven ",     "eight ",
      "nine ",       "ten ",     "eleven ",  "twelve ",    "thirteen ",
      "fourteen ",   "fifteen ", "sixteen ", "seventeen ", "eighteen ",
      "nineteen ",   "twenty ",  "thirty ",  "forty ",     "fifty ",
      "sixty ",      "seventy ", "eighty ",  "ninety ",    "hundred ",
      "thousand ",   "million ", "billion ", "trillion ",  "quadrillion ",
      "quintillion "};
};
