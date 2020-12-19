#pragma once

class Generator {
 public:
  Generator();
  Generator(unsigned long long end);
  Generator(unsigned long long begin, unsigned long long end);

  unsigned long long End();

  void Next();

  unsigned long long operator*();
  Generator& operator++();

 private:
  unsigned long long current_ = 0;
  unsigned long long end_;
};
