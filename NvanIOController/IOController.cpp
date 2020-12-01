#pragma once

// SERIAL MANAGER
#include "SerialManager.cpp"

// PIN TYPES
#include "IOPins/IOPin.cpp"

#include "IOPins/AnalogInput.cpp"
#include "IOPins/DigitalInput.cpp"
#include "IOPins/PullUpDigitalInput.cpp"
#include "IOPins/DigitalOutput.cpp"
#include "IOPins/PwmOutput.cpp"

#include <Arduino.h>

using namespace NvanIOController::IOPins;

namespace NvanIOController {
  class IOController {
    private:
      static inline IOPin *ioPins[DEVICE_TOTAL_IO_PINS];
      
    public:
      static void begin() {
        SerialManager::begin();
        
        while(true) {
          SerialMessage message = SerialManager::readNext();
          
          SerialMessage out;
          
          switch(message.command) {
            
            // INIT PIN
            case 'i':
              switch(message.data[2]) {
                case 0:
                  ioPins[message.data[0]] = new DigitalInput(message.data[1]);
                  break;
                  
                case 1:
                  ioPins[message.data[0]] = new PullUpDigitalInput(message.data[1]);
                  break;
                  
                case 2:
                  ioPins[message.data[0]] = new DigitalOutput(message.data[1]);
                  break;
                  
                case 3:
                  ioPins[message.data[0]] = new AnalogInput(message.data[1]);
                  break;
                  
                case 4:
                  ioPins[message.data[0]] = new PwmOutput(message.data[1]);
                  break;
              }
              
              ioPins[message.data[0]]->init();
              
              out.command = 'i';
              out.depth = 0;
              break;
            
            // SET OUTPUT
            case 's':
              ioPins[message.data[0]]->setValue(message.data[1]);
              out.command = 's';
              out.depth = 0;
              break;
              
            // READ INPUT
            case 'r':
              out.command = 'r';
              out.data[0] = ioPins[message.data[0]]->getValue();
              out.depth = 1;
              break;
            
            // UNKNOWN COMMAND
            default:
              SerialMessage out;
              out.command = 'u';
              out.depth = 0;
              break;
          }
          
          SerialManager::send(out);
        }
      }
      
  };
}
