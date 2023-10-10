# Text-Based Clock for ESP32 (Arduino IDE 2)

## Overview

This project implements a text-based clock on the ESP32S2 microcontroller using the Arduino IDE 2 platform. The clock displays the current time in a text format on a custom led wall mount. It serves as a practical example of using the ESP32's capabilities for timekeeping.

**This project is currently in development**

## Features

- Real-time clock (RTC) synchronization for accurate timekeeping.
- Easily configurable through the Arduino IDE 2.

## Hardware Requirements

- ESP32 microcontroller.
- Appropriate power supply for the ESP32.
- Leds
- Breadboard
- Resistors
- The wallmount is custom
- USB-to-Serial converter (for initial setup and debugging).

## Getting Started

1. **Setup Your Development Environment**

   - Install the Arduino IDE 2 and the ESP32 board support.
   - Ensure you have the required libraries installed (Additional Boards Manager URLs: https://dl.espressif.com/dl/package_esp32_index.json and install esp32 by Espressif Systems on the BOARD MANAGER tab).

2. **Connect the Hardware**

   - Connect your ESP32 with the resistors and leds (see picture below).
   - Connect the necessary power supply.

3. **Configure the Clock**

   - Open the Arduino IDE 2.
   - Load the provided sketch (`.ino` file) into the IDE.
   - Configure the clock settings, such as time format and display options, in the sketch.

4. **Upload and Run**

   - Select the appropriate ESP32 board and COM port.
   - Click "Upload" to flash the code to your ESP32.
   - Open the serial monitor or activate your chosen display to view the text-based clock.

## Configuration

In the sketch, you can customize the following options:

- **Time Format:** Choose between 12-hour and 24-hour time formats.
- **Display Output:** Select the type of display output (serial terminal, OLED display, etc.).
- **Time Zone:** Set your desired time zone for accurate timekeeping.

## Troubleshooting

- If you encounter issues during setup or operation, consult the troubleshooting section in the sketch or refer to the project's documentation.

## Contributors

- Hendrik Brüning

## License

Use it like u want :)

## Acknowledgments

- Inspiration drawn from QCLOCKTWO CLASSIC

## Support

For any questions, bug reports, or feature requests, please contact hendrikbruening@gmx.de.

