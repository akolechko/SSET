#pragma once

struct LuckinessEvaluator {
  LuckinessEvaluator(Ticket t) : ticket(t) {}

  virtual ~LuckinessEvaluator() = default;

  virtual bool IsLucky() const = 0;

  Ticket ticket;
};

struct MoscowEvaluator : LuckinessEvaluator {
  MoscowEvaluator(Ticket t) : LuckinessEvaluator(t) {}

  bool IsLucky() const override {
    std::vector<short> decomposed = ticket.GetDecomposed();

    short sum_of_first_triple = decomposed[5] + decomposed[4] + decomposed[3];
    short sum_of_last_triple = decomposed[2] + decomposed[1] + decomposed[0];

    return (sum_of_first_triple == sum_of_last_triple);
  }
};

struct PiterEvaluator : LuckinessEvaluator {
  PiterEvaluator(Ticket t) : LuckinessEvaluator(t) {}

  bool IsLucky() const override {
    std::vector<short> decomposed = ticket.GetDecomposed();

    short sum_of_even = 0;
    short sum_of_odd = 0;

    for (auto n : decomposed) n % 2 == 0 ? sum_of_even += n : sum_of_odd += n;

    return (sum_of_even == sum_of_odd);
  }
};