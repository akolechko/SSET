#include <iostream>
#include <stack>
#include <string>

#include "input_validation.h"

std::string Translate(long number) {
  const std::string templates[] = {
      "minus ",    "zero",     "one ",     "two ",       "three ",
      "four ",     "five ",    "six ",     "seven ",     "eight ",
      "nine ",     "ten ",     "eleven ",  "twelve ",    "thirteen ",
      "fourteen ", "fifteen ", "sixteen ", "seventeen ", "eighteen ",
      "nineteen ", "twenty ",  "thirty ",  "forty ",     "fifty ",
      "sixty ",    "seventy ", "eighty ",  "ninety ",    "hundred ",
      "thousand ", "million ", "billion "};

  bool is_positive = true;
  std::stack<std::string> numbers;
  std::string result = "";

  if (number == 0) {
    numbers.push(templates[1]);
  } else {
    if (number < 0) {
      is_positive = false;
      number *= -1;
    }

    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 2; ++j) {
        if (i > 0 && j == 0 && number % 1000 != 0)
          numbers.push(templates[29 + i]);

        int remainder = number % static_cast<int>(pow(10, 2 - j));

        if (remainder != 0) {
          if (j == 0) {
            if (remainder <= 20) {
              numbers.push(templates[remainder + 1]);
            } else {
              if (remainder % 10 != 0)
                numbers.push(templates[remainder % 10 + 1]);
              if (remainder % 100 - remainder % 10 != 0)
                numbers.push(templates[remainder % 100 / 10 + 19]);
            }
          }

          if (j == 1) {
            numbers.push(templates[29]);
            numbers.push(templates[remainder + 1]);
          }
        }

        number /= static_cast<int>(pow(10, 2 - j));
      }
    }
  }

  if (!is_positive) numbers.push(templates[0]);

  while (!numbers.empty()) {
    result += numbers.top();
    numbers.pop();
  }

  return result;
}

int main() {
  while (true) {
    bool input_is_valid;
    std::string input;

    do {
      std::cout << "Enter a valid long integer: ";
      std::cin >> input;
      input_is_valid = input_validation::IsLong(input, 10);
    } while (!input_is_valid);

    long number = strtol(input.c_str(), nullptr, 10);

    std::string result = Translate(number);

    std::cout << result << std::endl;
  }

  return 0;
}