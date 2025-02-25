<div class="section">

<div class="titlepage">

<div>

<div>

#### <span id="readtemp"></span>ReadTemp

</div>

</div>

</div>

<span class="strong">**Syntax:**</span>

``` screen
    byte_var = ReadTemp
```

<span class="strong">**Command Availability:**</span>

Available on all microcontrollers.

<span class="strong">**Explanation:**</span>

`ReadTemp` is a function that returns the raw value of the sensor. The
following two lines must be included in the GCBASIC source file.

``` screen
    #include <DS18B20.h>
    #define DQ PortC.3 ; change port configuration as required
```

`ReadTemp` reads the sensor and stores in output variable. The
conversion takes up to 750ms. Readtemp carries out a full 12 bit
conversion and then rounds the result to the nearest full degree
Celsius.

To read the full 12 bit value of the sensor use the `readtemp12`
command.

The temperature is read back in whole degree steps, and the sensor
operates from -55 to + 125 degrees Celsius. Note that bit 7 is 0 for
positive temperature values and 1 for negative values (ie negative
values will appear as 128 + numeric value).

Note the `Readtemp` command does not work with the older DS1820 or
DS18S20 as they have a different internal resolution. This command is
not designed to be used with parasitically powered DS18B20 sensors, the
5V pin of the sensor must be connected.

<span class="strong">**Example:**</span>

``` screen
    'Chip Settings. Assumes the development board with with a 16F877A
    #chip 16F877A,1

    #include <DS18B20.h>

    'Use LCD in 4 pin mode and define LCD pins
    #define LCD_IO 4
    #define LCD_WIDTH 20                ;specified lcd width for clarity only.  20 is the default width
    #define LCD_RW PORTE.1
    #define LCD_RS PORTE.0
    #define LCD_Enable PORTE.2
    #define LCD_DB4 PORTD.4
    #define LCD_DB5 PORTD.5
    #define LCD_DB6 PORTD.6
    #define LCD_DB7 PORTD.7

    ' DS18B20 port settings
    #define DQ PortC.3

      ccount = 0
      CLS

    do forever
       ' The function readtemp returns the integer value of the sensor
       DSdata = readtemp

       ' Display the integer value of the sensor on the LCD
       locate 0,0
       print hex(ccount)
       print " Ceil"
       locate 0,8
       print DSdata
       print chr(223)+"C"

       wait 2 s
       ccount++

    loop
```

</div>
