#include "pch.h"

#include "envelopes_view.h"

EnvelopesView::EnvelopesView(std::ostream& out, std::istream& in)
    : out_(out), in_(in) {}

void EnvelopesView::PrintIntro() {
  out_ << "Enter the width and height of two envelopes to determine whether "
          "one suits other"
       << std::endl;
}

void EnvelopesView::PrintMessage(const std::string& str) {
  out_ << str << std::endl;
}

void EnvelopesView::PrintError(const validation::ErrorCode& error) {
  switch (error) {
    case validation::ErrorCode::kInvalidArgument:
      out_ << "Argument is invalid" << std::endl;

      break;
    case validation::ErrorCode::kOutOfRange:
      out_ << "Argument is too big" << std::endl;

      break;
  }
}

void EnvelopesView::PrintComparisonResult(bool fit) {
  fit ? out_ << "Envelopes suit each other." << std::endl
      : out_ << "Envelopes doesn't suit." << std::endl;
}

void EnvelopesView::RequestData(std::string& str, const std::string& msg) {
  if (!msg.empty()) out_ << msg;
  in_ >> str;
}
