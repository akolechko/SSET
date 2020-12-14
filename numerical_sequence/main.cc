#include <iostream>
#include <string>
#include <vector>

constexpr int kBufSize = 9;

struct Buffer {
  int rank = 0;
  unsigned long long number = 0;
  std::string number_str = "";
};

void MakeMultiple(std::string& initial_number, int& len) {
  while (len % kBufSize != 0) {
    initial_number = "0" + initial_number;
    ++len;
  }
}

void FillBuffers(std::vector<Buffer>& buffers, const std::string& str,
                 int len) {
  int rank = len / kBufSize - 1;
  std::string number_str = "";
  int buf_count = 0;

  for (int i = 0; i < len; ++i) {
    ++buf_count;
    number_str += str[i];

    if (buf_count == kBufSize) {
      Buffer buffer = {rank, std::stoull(number_str), number_str};
      buffers.push_back(buffer);
      --rank;
      buf_count = 0;
      number_str.clear();
    }
  }
}

void SplitBuffer(const Buffer& buffer, std::vector<Buffer>& to, int& max_rank) {
  std::string first_half_s = buffer.number_str.substr(0, kBufSize);
  std::string second_half_s = buffer.number_str.substr(kBufSize);

  int first_half_r = buffer.rank + 1;
  int second_half_r = buffer.rank;

  unsigned long long first_half_n = std::stoull(first_half_s);
  unsigned long long second_half_n = std::stoull(second_half_s);

  Buffer first_half_b = {first_half_r, first_half_n, first_half_s};
  Buffer second_half_b = {second_half_r, second_half_n, second_half_s};

  to.push_back(first_half_b);
  to.push_back(second_half_b);

  if (first_half_r > max_rank) max_rank = first_half_r;
}

void MultiplyBuffers(const std::vector<Buffer>& x_buffers,
                     const std::vector<Buffer>& y_buffers,
                     std::vector<Buffer>& result_buffers) {
  for (Buffer x_buffer : x_buffers) {
    for (Buffer y_buffer : y_buffers) {
      int rank = x_buffer.rank + y_buffer.rank;
      unsigned long long number = x_buffer.number * y_buffer.number;
      std::string number_str = std::to_string(number);

      while (number_str.length() != kBufSize * 2) number_str = "0" + number_str;

      Buffer buffer = {rank, number, number_str};

      result_buffers.push_back(buffer);
    }
  }
}

void AddBuffers(const std::vector<Buffer>& buffers,
                std::vector<Buffer>& result_buffers, int& max_rank) {
  for (int i = 0; i <= max_rank; ++i) {
    Buffer result_buffer;

    for (Buffer buffer : buffers) {
      if (buffer.rank > max_rank) max_rank = buffer.rank;
      if (buffer.rank == i) {
        int rank = i;
        unsigned long long number = buffer.number + result_buffer.number;
        std::string number_str = std::to_string(number);

        while (number_str.length() != kBufSize * 2)
          number_str = "0" + number_str;

        result_buffer.rank = rank;
        result_buffer.number = number;
        result_buffer.number_str = number_str;
      }
    }

    result_buffers.push_back(result_buffer);
  }
}

void AddSplit(std::vector<Buffer>& result_buffers, int& max_rank) {
  std::vector<Buffer> temp;
  bool less_than_bufsize = false;
  while (!less_than_bufsize) {
    less_than_bufsize = true;

    AddBuffers(result_buffers, temp, max_rank);

    result_buffers = temp;
    temp.clear();

    for (Buffer buffer : result_buffers) {
      if (std::to_string(buffer.number).length() > kBufSize) {
        less_than_bufsize = false;

        SplitBuffer(buffer, temp, max_rank);
      } else {
        temp.push_back(buffer);
      }
    }

    result_buffers = temp;
    temp.clear();
  }
}

void BuildResultString(const std::vector<Buffer>& result_buffers,
                       std::string& result_string, int max_rank) {
  for (int i = max_rank; i >= 0; --i)
    result_string += result_buffers[i].number_str.substr(kBufSize);

  result_string.erase(result_string.begin(),
                      std::find_if(result_string.begin(), result_string.end(),
                                   [](unsigned char ch) { return ch != '0'; }));

  if (result_string.empty()) result_string = "0";
}

std::string Multiply(std::string initial_x, std::string initial_y) {
  std::vector<Buffer> x_buffers;
  std::vector<Buffer> y_buffers;
  std::vector<Buffer> result_buffers;
  std::string result_string = "";
  int max_rank = 0;

  int x_len = initial_x.length();
  int y_len = initial_y.length();

  MakeMultiple(initial_x, x_len);
  MakeMultiple(initial_y, y_len);

  FillBuffers(x_buffers, initial_x, x_len);
  FillBuffers(y_buffers, initial_y, y_len);

  std::vector<Buffer> multiplied_buffers;
  MultiplyBuffers(x_buffers, y_buffers, multiplied_buffers);

  for (Buffer buffer : multiplied_buffers)
    SplitBuffer(buffer, result_buffers, max_rank);

  multiplied_buffers.clear();

  AddSplit(result_buffers, max_rank);

  BuildResultString(result_buffers, result_string, max_rank);

  return result_string;
}

std::string Add(std::string initial_x, std::string initial_y) {
  std::vector<Buffer> result_buffers;
  std::string result_string = "";
  int max_rank = 0;

  int x_len = initial_x.length();
  int y_len = initial_y.length();

  MakeMultiple(initial_x, x_len);
  MakeMultiple(initial_y, y_len);

  FillBuffers(result_buffers, initial_x, x_len);
  FillBuffers(result_buffers, initial_y, y_len);

  AddSplit(result_buffers, max_rank);

  BuildResultString(result_buffers, result_string, max_rank);

  return result_string;
}

bool Less(std::string initial_x, std::string initial_y) {
  int x_len = initial_x.length();
  int y_len = initial_y.length();

  if (x_len < y_len) return true;
  if (x_len > y_len) return false;

  MakeMultiple(initial_x, x_len);
  MakeMultiple(initial_y, y_len);

  initial_x = initial_x.substr(0, kBufSize);
  initial_y = initial_y.substr(0, kBufSize);

  return std::stoull(initial_x) < std::stoull(initial_y);
}

int main() {
  std::string a = "";
  std::string b = "";
  std::cin >> a;
  std::cin >> b;

  for (std::string n = a; Less(Multiply(n, n), b); n = Add(n, "1")) {
    std::cout << n << std::endl;
  }

  return 0;
}