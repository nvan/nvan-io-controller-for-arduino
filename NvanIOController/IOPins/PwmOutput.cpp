#pragma once

#include "IOPin.cpp"

#include <Arduino.h>

namespace NvanIOController {
  namespace IOPins {
    class PwmOutput: public IOPin {
      using IOPin::IOPin;
      
      protected:
        int getIOType() { return OUTPUT; };
        
      public:
        void setValue(int value) {
          analogWrite(this->pinNumber, value);
        }
    };
  }
}