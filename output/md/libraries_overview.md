<div class="section">

<div class="titlepage">

<div>

<div>

<span id="libraries_overview"></span>Libraries Overview
--------------------------------------------------------

</div>

</div>

</div>

<span class="strong">**About Libraries**</span>

GCBASIC (as with most other microcontroller programming languages)
supports libraries.

You can create you own device specific library, you are not limited to
those shown below. If you create a new device specific library - please
submit for inclusion in the next release via the GCBASIC forum.

Maintenance of these libraries is completed by the GCBASIC development
team. If you wish to adapt these libraries you should create a local
copy, edit and save within your development file structure. The
development team may update these libraries as part of a release and we
do not want you to lose your local changes.

To use a library, simple inlcude the following in your user code

``` screen
    #include <3PI.H>    'this will include the 3PI capabilities within your program
```

To use a local copy of a library, simple inlcude the following in your
user code

``` screen
    #include "C:\mydev\library\3pi.h"    'this will include a local copy of the the 3PI capabilities within your program
```

GCBASIC supports the following device libraries.

<div class="informaltable">

| <span class="strong">**Library**</span> | <span class="strong">**Class**</span>    | <span class="strong">**Usage**</span>                                                                                                            |
|:----------------------------------------|:-----------------------------------------|:-------------------------------------------------------------------------------------------------------------------------------------------------|
| 3PI                                     | Polulu 3pi robot                         | A library that interfaces the switch and the motors.                                                                                             |
| 47XXX\_EERAM.H                          | I2C EERAM memory                         | A device specific library for the Microchip EERAM device classs                                                                                  |
| ALPS-EC11                               | Rotary Encoder                           | A device specific library for a rotary encoder.                                                                                                  |
| ADS7843                                 | Touch Shield                             | A library that interfaces with the ADS7843 touch screen.                                                                                         |
| BME280                                  | Temp, Humidity and Pressure sensor       | A library that interfaces with the BME280 and the BMP280 sensor.                                                                                 |
| CHIPINO                                 | Shield                                   | A library that interfaces the Chipino board with Arduino like port addresses.                                                                    |
| DHT                                     | Temperature and Humidity                 | A library that supports the DHT22 and the DHT11 Temperature and Humidity sensors.                                                                |
| DS1307                                  | Clock                                    | A library that supports the timer clock and NVRAM functions.                                                                                     |
| DS1672                                  | Clock                                    | A library that supports the timer clock and NVRAM functions.                                                                                     |
| DS18B20                                 | Temperature                              | A library that supports the temperature functions.                                                                                               |
| DS18SB0MultiPort                        | Temperature                              | A library that supports the temperature functions with devices attached to multiple ports.                                                       |
| DS18S20                                 | Temperature                              | A library that supports the temperature functions.                                                                                               |
| DS2482                                  | Clock                                    | A library that supports the I2C to Dallas OneWire functions.                                                                                     |
| DS3231                                  | Clock                                    | A library that supports the timer clock and NVRAM functions.                                                                                     |
| DUEMILANOVE                             | Shield                                   | A library that interfaces the Duemilanove board with Arduino like port addresses.                                                                |
| EMC1001                                 | Temperature                              | A library that supports the temperature functions and the other device capabilities.                                                             |
| FRAM                                    | I2C Eeprom                               | A library that supports memory functions.                                                                                                        |
| GETUSERID                               | Microchip read ID                        | A library that supports the identification of Microchip microcontrollers.                                                                        |
| EPD\_EPD2In13                           | Graphical e-Paper display                | A core library for Graphical LCD support.                                                                                                        |
| EPD\_EPD7in5                            | Graphical e-Paper display                | A core library for Graphical LCD support.                                                                                                        |
| GLCD\_                                  | Graphical LCD                            | A device specific library for an Graphical LCD.                                                                                                  |
| GLCD\_HX8347                            | Graphical LCD                            | A device specific library for an Graphical LCD.                                                                                                  |
| GLCD\_ILI9340                           | Graphical LCD                            | A device specific library for an Graphical LCD.                                                                                                  |
| GLCD\_ILI9341                           | Graphical LCD                            | A device specific library for an Graphical LCD.                                                                                                  |
| GLCD\_ILI9481                           | Graphical LCD                            | A device specific library for an Graphical LCD.                                                                                                  |
| GLCD\_ILI9486L                          | Graphical LCD                            | A device specific library for an Graphical LCD.                                                                                                  |
| GLCD\_NT7108C                           | Graphical LCD                            | A device specific library for an Graphical LCD.                                                                                                  |
| GLCD\_IMAGESANDFONTS\_ADDIN3            | Graphical LCD                            | A library to increase the capabilities of the Graphical LCDs.                                                                                    |
| GLCD\_KS0108                            | Graphical LCD                            | A device specific library for an Graphical LCD.                                                                                                  |
| GLCD\_NEXTION                           | Graphical LCD                            | A device specific library for an Graphical LCD.                                                                                                  |
| GLCD\_PCD8544                           | Graphical LCD                            | A device specific library for an Graphical LCD.                                                                                                  |
| GLCD\_SH1106                            | Graphical LCD                            | A device specific library for an Graphical LCD.                                                                                                  |
| GLCD\_SSD1289                           | Graphical LCD                            | A device specific library for an Graphical LCD.                                                                                                  |
| GLCD\_SSD1306                           | Graphical LCD                            | A device specific library for an Graphical LCD.                                                                                                  |
| GLCD\_SSD1331                           | Graphical LCD                            | A device specific library for an Graphical LCD.                                                                                                  |
| GLCD\_ST7735                            | Graphical LCD                            | A device specific library for an Graphical LCD.                                                                                                  |
| GLCD\_ST7920                            | Graphical LCD                            | A device specific library for an Graphical LCD.                                                                                                  |
| GLCD\_T6963\_64                         | Graphical T6963 LCD with 240 x 64 pixels | A device specific library for an Graphical LCD.                                                                                                  |
| GLCD\_T6963\_128                        | Graphical T6963 LCD with 240 x 64 pixels | A device specific library for an Graphical LCD.                                                                                                  |
| HEFLASH                                 | HEF Memory Driver                        | A library that supports the HEF memory functions.                                                                                                |
| HMC5883L                                | Triple-axis Magnetometer                 | A library that supports the magnetometer functions.                                                                                              |
| HWI2C\_ISR\_HANDLER                     | I2C Slave Driver                         | A library that supports the use of a Microchip microcontroller as an I2C slave.                                                                  |
| HWI2C\_MESSAGEINTERFACE                 | I2C Slave                                | A support library that supports the use of a Microchip microcontroller as an I2C slave.                                                          |
| HWI2C\_ISR\_HANDLERKMODE                | I2C Slave Driver                         | A library that supports the use of a Microchip microcontroller as an I2C slave.                                                                  |
| HWI2C\_MESSAGEINTERFACEKMODE            | I2C Slave                                | A support library that supports the use of a Microchip microcontroller as an I2C slave.                                                          |
| I2CEEPROM                               | I2C EEProm memory                        | A library that supports memory functions.                                                                                                        |
| LCD2SERIALREDIRECT                      | LCD to Serial Handler                    | A library that supports the use of a serial and PC terminal as a psuedo LCD.                                                                     |
| LEGO-PF                                 | Lego Mindstorms shield                   | A library that supports the Lego Mindstorms robot                                                                                                |
| LEGO                                    | Lego Mindstorms shield                   | A library that supports the Lego Mindstorms robot                                                                                                |
| MATHS                                   | Maths routines                           | A library that supports maths functions such as logs, power and atan.                                                                            |
| MAX6675                                 | Temperature                              | A library that supports the temperature functions.                                                                                               |
| MAX7219\_ledmatrix\_driver              | LED 8\*8 Matrix driver                   | A library that supports the MAX7219 8\*8 LED matrixes                                                                                            |
| MCP23008                                | i2C to serial                            | A library that supports the I2C to serial functions.                                                                                             |
| MCP23017                                | i2C to serial                            | A library that supports the I2C to serial functions.                                                                                             |
| MCP4XXXDIGITALPOT                       | Digital Pot                              | A library that supports the MCPxxxx range of digital potentiometers.                                                                             |
| MCP7940N                                | Clock                                    | A library that supports the timer clock and NVRAM functions.                                                                                     |
| MILLIS                                  | Clock                                    | A library that supports the 1000ms timer event cycle.                                                                                            |
| NUNCHUCK                                | Game controller                          | A library that supports the NunChuck game controller.                                                                                            |
| PCA9685                                 | PWM                                      | A device specific library for the 16channel PWM driver. See the demonstrations for example on usage. Support up to four devices via the I2C bus. |
| PCF8574                                 | GLCD                                     | A device specific library for an Graphical LCD.                                                                                                  |
| PCF85X3                                 | Clock                                    | A library that supports the timer clock and alarms.                                                                                              |
| SD                                      | SD Card                                  | A device specific library for an SD Card.                                                                                                        |
| SMT\_Timers                             | Signal Measurment Timer                  | A library for Signal Measurment Timer for specific Microchip microcontrollers.                                                                   |
| SOFTSERIAL                              | Serial                                   | A library for software serial.                                                                                                                   |
| SOFTSERIALCH1                           | Serial                                   | A library for software serial.                                                                                                                   |
| SOFTSERIALCH2                           | Serial                                   | A library for software serial.                                                                                                                   |
| SOFTSERIALCH3                           | Serial                                   | A library for software serial.                                                                                                                   |
| SONGLAY                                 | Music                                    | A library for play music. Supports QBASIC and RTTTL format.                                                                                      |
| SONYREMOTE                              | Infrared                                 | A library that supports the functions of a Sony remote control.                                                                                  |
| SRF02                                   | Distance Sensor                          | A library that supports the SRF02 ultrasonic sensor.                                                                                             |
| SRAM                                    | Memory devices                           | A library that supports 23LC1024, 23LCV1024, 23LC1024, 23A1024, 23LCV512, 23LC512, 23A512, 23K256, 23A256, 23A640 or 23K640 devices              |
| SRF04                                   | Distance Sensor                          | A library that supports the SRF04 ultrasonic sensor.                                                                                             |
| TEA5767                                 | I2C Radio                                | A library that supports the TEA5767 radio.                                                                                                       |
| TM1637                                  | 7 Segment LED display                    | A library that supports the TM1637 7-Segment LED displays                                                                                        |
| TRIG2PLACES                             | Maths functions                          | A maths library that supports trignometry to two places.                                                                                         |
| TRIG3PLACES                             | Maths functions                          | A maths library that supports trignometry to three places                                                                                        |
| TRIG4PLACES                             | Maths functions                          | A maths library that supports trignometry to four places                                                                                         |
| UNO\_MEGA328P                           | Shield                                   | A library that interfaces the shield with Arduino like port addresses.                                                                           |
| USB                                     | USB Supoort                              | A library that interfaces the USB for 16f and 18f microcontrollers.                                                                              |

</div>

  

  
GCBASIC supports the following core libraries. These libraries are
automatically included in your user program therefore you do not need to
use '\#include' to access the libraries capabilities.

<div class="informaltable">

| <span class="strong">**Library**</span> | <span class="strong">**Class**</span> | <span class="strong">**Usage**</span>                                                                      |
|:----------------------------------------|:--------------------------------------|:-----------------------------------------------------------------------------------------------------------|
| 7SEGMENT                                | 7 Segment LED display                 | A library that interfaces the device. See also TM1637a library.                                            |
| A-D                                     | Analog to Digital                     | A library that supports the ADC functionality.                                                             |
| EEPROM                                  | EEProm                                | A library that supports I2C eeprom devices.                                                                |
| HWI2C                                   | I2C                                   | A library that supports the MSSP and TWI hardware modules of I2C                                           |
| HWI2C2                                  | I2C                                   | A library that supports the MSSP and TWI hardware modules of I2C on channel two                            |
| HWSPI                                   | SPI                                   | A library that supports the MSSP and TWI hardware modules of SPI                                           |
| I2C                                     | I2C                                   | A library that supports software I2C                                                                       |
| KEYPAD                                  | KeyPad                                | A library that supports a keypad.                                                                          |
| PS2                                     | I2C                                   | A library that supports keyboard functionality                                                             |
| LCD                                     | LCD                                   | A library that supports LCD functionality, library supports many different communications methods.         |
| PWM                                     | Pulse Width Modulation                | A library supports PWM functionality.                                                                      |
| RANDOM                                  | Random Numbers                        | A library supports random number functionality.                                                            |
| REMOTE                                  | Infrared                              | A library that supports the functions of a NEC remote control.                                             |
| RS232                                   | Serial                                | A library for serial communications.                                                                       |
| SOUND                                   | Tones                                 | A library for sound and tone generation                                                                    |
| STDBASIC                                | Utility Functions                     | The library that contains many of the utility methods.                                                     |
| STRING                                  | String                                | The library that contains the string methods.                                                              |
| SYSTEM                                  | System                                | The library that contains the system methods.                                                              |
| TIMER                                   | Timers                                | The library that contains the timer methods.                                                               |
| USART                                   | Serial                                | The library that contains the hardware serial methods that use the MSSP or AVR equivilent hardware module. |
| XPT2046                                 | Touch Shield                          | A library that interfaces with the APT2026 and the ADS7843 touch sensors.                                  |

</div>

  
  

</div>
