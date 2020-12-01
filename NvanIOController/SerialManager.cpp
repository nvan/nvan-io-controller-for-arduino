#pragma once

#define COMMAND_MAX_DEPTH 3
#define COMMAND_SEPARATOR ';'
#define COMMAND_PARAMETER_SEPARATOR ':'

#include <Arduino.h>

namespace NvanIOController {
  struct SerialMessage {
    char command;
    int data[COMMAND_MAX_DEPTH];
    int depth;
  };
  
  class SerialManager {
    public:
      static void begin() {
        Serial.begin(BAUD_RATE);
      }
      
      static SerialMessage readNext() {
        
        int c;
        int current = -1;
        char command;
        String rawData[COMMAND_MAX_DEPTH];
        int data[COMMAND_MAX_DEPTH];
        
        while(true) {
          c = Serial.read();
          
          if(c == -1) {
            continue;
          }
          
          if((char)c == COMMAND_SEPARATOR)  {
            break;
          }
          
          if((char)c == COMMAND_PARAMETER_SEPARATOR)  {
            current++;
            continue;
          }
          
          if(current == -1) {
            command = (char)c;
            continue;
          }
          
          rawData[current] += String((char)c);
        }
        
        SerialMessage message;
        message.command = command;
        message.depth = current + 1;
        
        for(int i = 0; i < message.depth; i++) {
          data[i] = rawData[i].toInt();
        }
        memcpy(message.data, data, COMMAND_MAX_DEPTH * sizeof(int));
        
        delay(10);
        return message;
      }
      
      static void send(SerialMessage message) {
        String parsedMessage = String(message.command);
        
        for(int i = 0; i < message.depth; i++) {
          parsedMessage += ":" + String(message.data[i]);
        }
        
        parsedMessage += ";";
        Serial.println(parsedMessage);
      }
  };
}
