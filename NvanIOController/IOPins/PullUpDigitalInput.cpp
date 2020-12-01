#pragma once

#include "DigitalInput.cpp"

#include <Arduino.h>

namespace NvanIOController {
  namespace IOPins {
    class PullUpDigitalInput: public DigitalInput {
      using DigitalInput::DigitalInput;
      
      protected:
        int getIOType() { return INPUT_PULLUP; };
    };
  }
}
