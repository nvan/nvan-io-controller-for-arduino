# NVAN IO Controller for Arduino
---
## Introduction
This is the software needed for Arduino Boards to interface with serial communication with NVAN IO Controller.
Our NVAN IO Controller PC software can be found at [this repository](https://github.com/nvan/nvan-io-controller).
Also refer to [that repository](https://github.com/nvan/nvan-io-controller) in order to find more compatible devices.

## Installation
It is as easy as downloading the Arduino IDE from here: [https://www.arduino.cc/en/software](https://www.arduino.cc/en/software)
Then download an extract this repository as ZIP in any folder. Double click the '.ino' file to open the project in the IDE.
You just have to select the correct model of your board (Mega or Mega 2560 in this case) on the tools menu on Arduino IDE, then select the COM Port in the same menu, you'll see that the name of the board is placed within parentheses.
After that, just press on the Upload arrow (the second icon on the dark green menu bar) and wait.

Ready! You have programmed your Arduino for NVAN IO Controller

## Supported Arduino boards
As of now, we support:
- Arduino UNO
- Arduino Mega
- Arduino Nano

## Disclaimer
As specified in the license, this software comes with no warranty, so we are not responsible if your board gets damaged while using this software, uploading the code, etc.

## Support
Please consider placing an issue on  this repository explaining the problem before sending me an e-mail.
If you really need, you can do it: [mduran@nvan.es](mailto:mduran@nvan.es)

## Contributions
You can do a Pull Request to contribute to this project.
Bare in mind that new features are not guatanteed to be added but error corrections are probably instead.

In the Arduino IDE you won't be able to see most of the files as it does not allow subfolders, you should edit the code with any other IDE or editor and compile it with the Arduino IDE.

## Donate
If you'd like to help me improving this projects, buying new hardware or jusy buying me a beer, you can donate via PayPal: [https://www.paypal.com/paypalme/maduranma](https://www.paypal.com/paypalme/maduranma)