<div class="section">

<div class="titlepage">

<div>

<div>

### <span id="infrared_remote"></span>InfraRed Remote

</div>

</div>

</div>

<span class="strong">**Explanation:**</span>

GCBASIC support interfacing with IR remote controls. The header file
contains explanations, for both hardware and software.

This has been tested on many different IR sensors, and different remote
controls.

<span class="strong">**Demonstration program:**</span>

The example is expected to work with most any IR sensor running at a 38
kHz carrier frequency.

``` screen
    ;This demo prints the device number and key number sent by
    ;a Sony compatible IR remote control unit to an LCD

    ;Thomas Henry --- 4/23/2014

    #chip 16F88, 8                    ;PIC16F88 running at 8 MHz
    #config mclr=off                  ;reset handled internally
    #include <SonyRemote.h>           ;include the header file

    ;----- Constants

    #define LCD_IO      4             ;4-bit mode
    #define LCD_WIDTH 20              ;specified lcd width for clarity only.  20 is the default width
    #define LCD_RS      PortB.2       ;pin 8 is Register Select
    #define LCD_Enable  PortB.3       ;pin 9 is Enable
    #define LCD_DB4     PortB.4       ;DB4 on pin 10
    #define LCD_DB5     PortB.5       ;DB5 on pin 11
    #define LCD_DB6     PortB.6       ;DB6 on pin 12
    #define LCD_DB7     PortB.7       ;DB7 on pin 13
    #define LCD_NO_RW   1             ;ground RW line on LCD

    #define IR_DATA_PIN PortA.0       ;sensor on pin 17

    ;----- Variables

    dim device, button as byte

    ;----- Program

    dir PortA in                      ;A.0 is IR input
    dir PortB out                     ;B.2 - B.6 for LCD

    do
      readIR_Remote(device, button)   ;wait for button press

      cls                             ;show device code
      print "Device: "
      print device

      locate 1,0
      print "Button: "                ;show button code
      print button

      wait 10 mS                      ;ignore any repeats
    loop                              ;repeat forever
```

<span class="strong">**See also
<a href="sonyremote_h" class="link" title="SonyRemote.h">SonyRemote.h</a>**</span>.

</div>
