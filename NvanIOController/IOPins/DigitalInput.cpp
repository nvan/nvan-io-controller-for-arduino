#pragma once

#include "IOPin.cpp"

#include <Arduino.h>

namespace NvanIOController {
  namespace IOPins {
    class DigitalInput: public IOPin {
      using IOPin::IOPin;
      
      protected:
        int getIOType() { return INPUT; };
        
      public:
        int getValue() {
          return digitalRead(this->pinNumber);
        }
    };
  }
}
