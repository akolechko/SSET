#pragma once

class FibonacciView {
 public:
  FibonacciView(std::ostream& out);

  void PrintIntro();
  void PrintMessage(const std::string& str);
  void PrintError(const validation::ErrorCode& error);
  void PrintFibonacci(FibonacciGenerator& generator);

 private:
  std::ostream& out_;
};
