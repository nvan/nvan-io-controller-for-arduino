#pragma once

#include <Arduino.h>

namespace NvanIOController {
  namespace IOPins {
    class IOPin {
      protected:
        int pinNumber;
        virtual int getIOType() {}
      
      public:
        IOPin(int pinNumber) {
          this->pinNumber = pinNumber;
        }
      
        ~IOPin() {
            pinMode(this->pinNumber, OUTPUT);
            digitalWrite(this->pinNumber, LOW);
        }
      
        void init() {
          pinMode(this->pinNumber, this->getIOType());
        }
        
        int getPinNumber() {
          return this->pinNumber;
        }
        
        virtual int getValue() {}
        virtual void setValue(int value) {}
    };
  }
}
