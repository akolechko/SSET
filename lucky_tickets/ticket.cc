#include "stdafx.h"

constexpr short kNumberSize = 6;

Ticket::Ticket(const std::string& number) { SetNumber(number); }

void Ticket::SetNumber(const std::string& number) {
  if (number.length() != kNumberSize)
    throw std::invalid_argument("The number must be six digits.");

  for (char c : number)
    if (!isdigit(c)) throw std::invalid_argument("The number must be digits.");

  number_ = number;
}

std::vector<short> Ticket::GetDecomposed() const { return Decompose(number_); }

std::string Ticket::GetNumber() const { return number_; }

std::vector<short> Ticket::Decompose(const std::string& number) const {
  std::vector<short> decomposed;

  for (char c : number) decomposed.push_back(c - '0');

  return decomposed;
}