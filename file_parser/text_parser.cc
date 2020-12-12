#include "text_parser.h"

#include <exception>
#include <filesystem>

TextParser::TextParser(FileIn* input, FileOut* output)
    : input_(input), output_(output) {}

long TextParser::CountStr(const std::string& str) {
  std::string buffer;
  std::string substr;
  std::string string;
  bool has_input = true;
  long counter = 0;
  size_t pos = 0;

  do {
    if (buffer.length() >= str.length())
      substr = buffer.substr(buffer.length() - str.length());
    else
      substr = buffer;

    buffer.clear();
    has_input = !input_->GetData(buffer);
    string = substr + buffer;

    while (pos != std::string::npos) {
      pos = string.find(str, pos);

      if (pos != std::string::npos) {
        ++counter;
        ++pos;
      } else {
        pos = 0;

        break;
      }
    }
  } while (has_input);

  return counter;
}

void TextParser::ReplaceStr(const std::string& str,
                            const std::string& to_replace) {
  std::string previous_buffer;
  std::string current_buffer;
  std::string buffer;
  std::string substr;
  bool has_input = true;
  size_t pos = 0;

  do {
    previous_buffer = current_buffer;
    current_buffer.clear();
    has_input = !input_->GetData(current_buffer);

    if (previous_buffer.length() >= to_replace.length()) {
      substr = previous_buffer.substr(previous_buffer.length() -
                                      to_replace.length());
      previous_buffer = previous_buffer.substr(
          0, previous_buffer.length() - to_replace.length());
    } else {
      substr = previous_buffer;
      previous_buffer.clear();
    }

    buffer = substr + current_buffer;

    while (pos != std::string::npos) {
      pos = buffer.find(to_replace, pos);

      if (pos != std::string::npos) {
        buffer.replace(pos, to_replace.length(), str);
      } else {
        if (buffer.length() >= to_replace.length()) {
          previous_buffer += buffer.substr(0, to_replace.length());
          current_buffer = buffer.substr(to_replace.length());
        } else {
          previous_buffer = buffer;
          current_buffer.clear();
        }

        output_->PutData(previous_buffer);
        pos = 0;

        break;
      }
    }
  } while (has_input || !buffer.empty());
}