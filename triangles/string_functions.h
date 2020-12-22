#pragma once

void LTrim(std::string &str) {
  str.erase(str.begin(),
            std::find_if(str.begin(), str.end(),
                         [](unsigned char ch) { return !std::isspace(ch); }));
}

void RTrim(std::string &str) {
  str.erase(std::find_if(str.rbegin(), str.rend(),
                         [](unsigned char ch) { return !std::isspace(ch); })
                .base(),
            str.end());
}

void Trim(std::string &str) {
  LTrim(str);
  RTrim(str);
}

std::vector<std::string> StringSplitter(const std::string &str,
                                        std::string delimiter) {
  std::vector<std::string> substrings;
  std::string s = str;
  std::string substring;
  size_t position = 0;

  while ((position = s.find(delimiter)) != std::string::npos) {
    substring = s.substr(0, position);
    Trim(substring);
    substrings.push_back(substring);
    s.erase(0, position + delimiter.length());
  }
  Trim(s);
  substrings.push_back(s);

  return substrings;
}

std::string ToLower(const std::string &str) {
  std::string s;
  for (char ch : str) s += tolower(ch);

  return s;
}
