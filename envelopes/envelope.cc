#include "envelope.h"

void Envelope::SetWidthAndHeight(float side1, float side2) {
  if (side1 >= side2) {
    h_ = side2;
    w_ = side1;
  } else {
    h_ = side1;
    w_ = side2;
  }
}