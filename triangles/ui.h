#pragma once
#include <iostream>
#include <string>

#include "shape_handler.h"
#include "validation.h"

void PrintMessage(const std::string& str) { std::cout << str << std::endl; }

void RequestData(std::string& str, const std::string& msg = "") {
  if (!msg.empty()) std::cout << msg;
  std::getline(std::cin, str);
}

void PrintHeader(const std::string& str_repr_singular) {
  std::cout << "============= " << str_repr_singular
            << " =============" << std::endl;
}

void PrintShape(const std::string& str_repr_singular, const std::string& number,
                const std::string& name, const std::string& property) {
  std::cout << number << ". [" << str_repr_singular << " " << name
            << "]: " << property << " cm" << std::endl;
}

template <class T>
void LoadData(ShapeHandler<T>& shandler) {
  std::string str;
  std::string delimiter = ",";
  std::vector<std::string> substrings;
  std::vector<double> sides;
  bool flag = true;

  while (flag) {
    RequestData(str, "Enter the name and sides: ");

    if ((substrings = StringSplitter(str, delimiter)).size() ==
        shandler.GetSidesRequired() + 1) {
      flag = false;

      for (int i = 1; i < substrings.size(); ++i) {
        if (IsValid<double>(substrings[i]))
          sides.push_back(strtod(substrings[i].c_str(), nullptr));
        else
          flag = true;
      }
    }

    if (flag) {
      PrintMessage("Invalid input. Try again.");
      substrings.clear();
      sides.clear();
    } else {
      shandler.AddShape(substrings[0], sides);
      substrings.clear();
      sides.clear();

      std::string answer;
      RequestData(answer, "Do you want to add one more shape? (y/n): ");
      answer = ToLower(answer);
      if (answer == "y" || answer == "yes") flag = true;
    }
  }
}
