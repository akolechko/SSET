#pragma once
#include <iostream>
#include <string>
#include <unordered_map>

class UI {
 public:
  void SendMessage(const std::string &msg);
  void RequestData(std::string &str, const std::string &msg);

 private:
  std::unordered_map<std::string, std::string> templates_;
};
