# Text-Based Clock for ESP32 (Arduino IDE 2)

## Overview

This project implements a text-based clock on the ESP32S2 microcontroller using the Arduino IDE 2 platform. The clock displays the current time in a text format on a custom led wall mount. It serves as a practical example of using the ESP32's capabilities for timekeeping.

**This project is currently in development**

## Features

- Real-time clock synchronization for accurate timekeeping.
- daylight saving time
- Easily configurable through the Arduino IDE 2.

## Hardware Requirements

- ESP32 microcontroller.
- Appropriate power supply for the ESP32.
- Leds
- Resistors
- wallmount and panel are custom
- USB-to-Serial converter (for initial setup and debugging).

if you bought a non developer esp32 you might need a USB to TTL Serial Adapter Module.

## Getting Started

1. **Setup Your Development Environment**

   - Install the Arduino IDE 2 and the ESP32 board support.
   - Ensure you have the required libraries installed (Additional Boards Manager URLs: https://dl.espressif.com/dl/package_esp32_index.json and install esp32 by Espressif Systems on the BOARD MANAGER tab).

2. **Connect the Hardware**

   - Connect your ESP32 with the resistors and leds (see picture below).
   - Connect the necessary power supply.
   - ![Led connection](https://github.com/Hendrik7889/esp32clock/tree/main/design-and-ports/led_connection.png) 

3. **Configure the Clock**

   - Open the Arduino IDE 2.
   - Load the provided sketch (`.ino` file) into the IDE.
   - Configure the clock settings in the config.h file.
   - set daslight saving time with the database ![here](https://github.com/nayarsystems/posix_tz_db/blob/master/zones.csv)

4. **Configure the Panel**
  
   - ![Panel-layout-English](https://github.com/Hendrik7889/esp32clock/tree/main/design-and-ports/IO-Ports-English.png) / ![Panel-layout-German](https://github.com/Hendrik7889/esp32clock/tree/main/design-and-ports/IO-Ports-German.png)

      ![Panel-file-German](https://github.com/Hendrik7889/esp32clock/blob/main/panel/)
   - ![Wallmount-file](https://github.com/Hendrik7889/esp32clock/blob/main/wallmount/wallmount.3mf)

5. **Upload and Run**

   - Select the appropriate ESP32 board and COM port.
   - Click "Upload" to flash the code to your ESP32.
   - if you bought a non developer esp32 you might need a USB to TTL Serial Adapter Module.
   

## Acknowledgments

- Inspiration drawn from QCLOCKTWO CLASSIC
