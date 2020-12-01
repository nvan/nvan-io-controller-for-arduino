#pragma once

#include "IOPin.cpp"

#include <Arduino.h>

namespace NvanIOController {
  namespace IOPins {
    class DigitalOutput: public IOPin {
      using IOPin::IOPin;
      
      protected:
        int getIOType() { return OUTPUT; };
        
      public:
        void setValue(int value) {
          digitalWrite(this->pinNumber, value);
        }
    };
  }
}