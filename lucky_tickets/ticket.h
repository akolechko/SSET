#pragma once

class Ticket {
 public:
  Ticket(const std::string& number);

  void SetNumber(const std::string& number);
  [[nodiscard]] std::vector<short> GetDecomposed() const;
  [[nodiscard]] std::string GetNumber() const;

 private:
  std::vector<short> Decompose(const std::string& number) const;
  std::string number_;
};
