#pragma once
#include <iostream>
#include <string>

void PrintMessage(const std::string& str) { std::cout << str << std::endl; }

void RequestData(std::string& str, const std::string& msg = "") {
  if (!msg.empty()) std::cout << msg;
  std::getline(std::cin, str);
}

void PrintHeader(const std::string& class_name) {
  std::cout << "============= " << class_name << " =============" << std::endl;
}

void PrintShape(const std::string& class_name, const std::string& number,
                const std::string& name, const std::string& property) {
  std::cout << number << ". [" << class_name << " " << name << "]: " << property
            << " cm" << std::endl;
}
