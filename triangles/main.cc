#include <iostream>
#include <locale>
#include "shape_handler.h"
#include "validation.h"
#include "ui.h"

void ltrim(std::string &s) {
  s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
            return !std::isspace(ch);
          }));
}

void rtrim(std::string &s) {
  s.erase(std::find_if(s.rbegin(), s.rend(),
                       [](unsigned char ch) { return !std::isspace(ch); })
              .base(),
          s.end());
}

void trim(std::string &s) {
  ltrim(s);
  rtrim(s);
}

std::vector<std::string> StringSplitter(const std::string& str) {
  std::vector<std::string> v;
  std::string s = str;
  size_t position = 0;
  std::string substring;

  while ((position = s.find(",")) != std::string::npos) {
    substring = s.substr(0, position);
    trim(substring);
    v.push_back(substring);
    s.erase(0, position + 1);
  }
  trim(substring);
  v.push_back(substring);

  return v;
}

int main() {
  ShapeHandler<Triangle> shandler;
  UI ui;
  std::string str;
  std::vector<std::string> vs;
  std::vector<double> vd;
  bool flag = true;

  while (flag) {
    ui.RequestData(str, "[name], [a], [b], [c]: ");
    vs = StringSplitter(str);

    if (vs.size() == 4) {
      flag = false;

      for (int i = 1; i < vs.size(); ++i) {
        if (IsValid<double>(vs[i]))
          vd.push_back(strtod(vs[i].c_str(), nullptr));
        else
          flag = true;
      }
    }
    if (flag) std::cout << "Invalid input. Try again." << std::endl;
  }

  Triangle triangle1(vs[0], vd[0], vd[1], vd[2]);

  shandler.AddShape(triangle1);

  std::vector<Triangle> vec = shandler.GetSortedShapes();
  for (Triangle t : vec) std::cout << t.GetArea() << std::endl;

  return 0;
}