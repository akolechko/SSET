#pragma once

struct Buffer {
  int rank = 0;
  unsigned long long number = 0;
  std::string number_str = "";
};

class BigNumber {
 public:
  BigNumber(const std::string& number = "0");

  [[nodiscard]] std::string GetStringRepr() const;
  void SetStringRepr(std::string number);

  BigNumber Multiply(const BigNumber& number);
  BigNumber Add(const BigNumber& number);
  bool Less(const BigNumber& number);

  BigNumber operator*(const BigNumber& number);
  bool operator<(const BigNumber& number);
  BigNumber& operator++();

  friend std::istream& operator>>(std::istream& is, BigNumber& number) {
    std::string str;
    is >> str;
    number.SetStringRepr(str);

    return is;
  }

  friend std::ostream& operator<<(std::ostream& os, const BigNumber& number) {
    os << number.GetStringRepr();

    return os;
  }

 private:
  std::string number_;

  void MakeMultiple(std::string& initial_number, size_t& len);

  void FillBuffers(std::vector<Buffer>& buffers, const std::string& str,
                   size_t len);

  void SplitBuffer(const Buffer& buffer, std::vector<Buffer>& to,
                   int& max_rank);

  void MultiplyBuffers(const std::vector<Buffer>& x_buffers,
                       const std::vector<Buffer>& y_buffers,
                       std::vector<Buffer>& result_buffers);

  void AddBuffers(const std::vector<Buffer>& buffers,
                  std::vector<Buffer>& result_buffers, int& max_rank);

  void AddSplit(std::vector<Buffer>& result_buffers, int& max_rank);

  void BuildResultString(const std::vector<Buffer>& result_buffers,
                         std::string& result_string, int max_rank);
};
