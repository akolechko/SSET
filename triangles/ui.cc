#include "ui.h"

void UI::SendMessage(const std::string& str) { std::cout << str << std::endl; }

void UI::RequestData(std::string& str, const std::string& msg = "") {
  if (!msg.empty()) std::cout << msg;
  std::getline(std::cin, str);
}