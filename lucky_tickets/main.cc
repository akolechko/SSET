#include "stdafx.h"

#include "luckiness_evaluator.h"

int main() {
  Ticket ticket("000112");
  LuckinessEvaluator* le = new PiterEvaluator(ticket);

  std::cout << le->IsLucky() << std::endl;

  return 0;
}