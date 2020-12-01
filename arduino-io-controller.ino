#define BAUD_RATE 115200

// Arduino MEGA
#if defined(ARDUINO_AVR_MEGA) || defined(ARDUINO_AVR_MEGA2560)
#define DEVICE_TOTAL_IO_PINS 70
#endif

// Arduino UNO
#if defined(ARDUINO_AVR_UNO)
#define DEVICE_TOTAL_IO_PINS 19
#endif

// Arduino NANO
#if defined(ARDUINO_AVR_NANO)
#define DEVICE_TOTAL_IO_PINS 21
#endif

/*
 * If you wanna add support for more boards, feel free
 * to commit more definitions. Pins al calculated in base
 * of the total available pins for I/O in each board.
 * We count Analog Inputs and Digital I/O.
 */

#include "NvanIOController/IOController.cpp"

int main() {
  init();
  NvanIOController::IOController::begin();

  return 0;
}
