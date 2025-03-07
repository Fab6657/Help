<div class="section">

<div class="titlepage">

<div>

<div>

#### <span id="select"></span>Select

</div>

</div>

</div>

<span class="strong">**Syntax:**</span>

``` screen
    Select Case var

    Case value1
      code1

    Case value2
      code2

    Case value_3 To _value4
      code3

    Case Else
      code4

    End Select
```

<span class="strong">**Command Availability:**</span>

Available on all microcontrollers.

<span class="strong">**Explanation:**</span>

The Select Case control structure is used to select and run a particular
section of code, based on the value of `var`. If `var` equals `value1`
then `code1` will be run. Once `code1` has run, the chip will jump to
the `End Select` command and continue running the program. If none of
the other conditions are true, then the code under the `Case Else`
section will be run.

`Case var TO var` is a range of values. If the value is within the range
the code section will be executed.

`Case Else` is optional, and the program will function correctly without
it.

If there is only one line of code after the `Case`, the code may look
neater if the line is placed after the `Case`. This is shown below in
the example, for cases 3, 4 and 5.

It is important to note that <span class="strong">**only one section of
code will be run**</span> when using `Select Case`.

There are two examples shown below.

<span class="strong">**Example 1:**</span>

``` screen
    'Program to read a value from a potentiometer, and display a
    'different word based on the result

      #chip 16F877a, 4

    'LCD connection settings
    #define LCD_IO 4
    #define LCD_WIDTH 20                ;specified lcd width for clarity only.  20 is the default width
    #define LCD_DB4 PORTD.4
    #define LCD_DB5 PORTD.5
    #define LCD_DB6 PORTD.6
    #define LCD_DB7 PORTD.7
    #define LCD_RS PORTD.0
    #define LCD_NO_RW
    #define LCD_Enable PORTD.2

    DIR PORTA.0 IN
    Do
      Temp = ReadAD(AN0) / 20
      CLS
      Select Case Temp
        Case 0
          Print "None!"
        Case 1
          Print "One"
        Case 2
          Print "Two"
        Case 3: Print "Three"
        Case 4: Print "Four"
        Case 5: Print "Five"
        Case Else
          Print "A lot!"
      End Select
      Wait 250 ms
    Loop
```

<span class="strong">**Example 2:**</span>

This code demonstrates how to receive codes from a handheld remote
control unit. This has been tested and supports a Sony TV remote and
also a universal remote set to Sony TV mode.

The program gets both the device number and the key number, and also
translates the key number to English. The received results are displayed
on an LCD.

The circuit for the IR receiver and the chip is shown below.

``` screen
    'A program to receive IR codes sent by a Sony
    'compatible handheld remote control.

    #chip 16F88, 8                    'PIC16F88 running at 8 MHz
    #config mclr=off                  'reset handled internally

    '----- Constants

    #define LCD_IO      4             '4-bit mode
    #define LCD_WIDTH 20                ;specified lcd width for clarity only.  20 is the default width
    #define LCD_RS      PortB.2       'pin 8 is Register Select
    #define LCD_Enable  PortB.3       'pin 9 is Enable
    #define LCD_DB4     PortB.4       'DB4 on pin 10
    #define LCD_DB5     PortB.5       'DB5 on pin 11
    #define LCD_DB6     PortB.6       'DB6 on pin 12
    #define LCD_DB7     PortB.7       'DB7 on pin 13
    #define LCD_NO_RW                 'ground RW line on LCD
    #define IR          PortA.0       'sensor on pin 17

    '----- Variables

    dim device, cmd, count, i as byte
    dim pulse(12)                     'pulse count array
    dim button as string              'ASCII for button label

    '----- Program

    dir PortA in                      'A.0 is IR input
    dir PortB out                     'B.2 - B.6 for LCD

    cls                               'clear the LCD
    print "Dev:    Cmd:"              'logo for top line
    locate 1,0
    print "Button:"                   'logo for second line

    do
      getIR, cmd                      'wait for IR signal
      printCmd                        'show device and command
      printKey                        'show key label
      wait 10 mS                      'ignore any repeats
    loop                              'repeat forever

    '----- Subroutines

    sub getIR
      tarry1:
        count = 0                     'wait for start bit
        do while IR = 0               'measure width (active low)
          wait 100 uS                 '24 X 100 uS = 2.4 mS
          count += 1
        loop
      if count < 20 then goto tarry1  'less than this so wait

      for i=1 to 12                   'read/store the 12 pulses
        tarry2:
          count = 0
          do while IR = 0             'zero = 6 units = 0.6 mS
            wait 100 uS               'one = 12 units = 1.2 mS
            count += 1
          loop
        if count < 4 then goto tarry2 'too small to be legit
        pulse(i) = count              'else store pulse width
      next

      cmd = 0                         'command built up here
      for i = 1 to 7                  '1st seven bits are the cmd
        cmd = cmd / 2                 'shift into place
        if pulse(i) > 10 then         'longer than 10 mS
           cmd = cmd + 64             'so call it a one
        end if
      next

      device = 0                      'device number built up here
      for i=8 to 12                   'next 5 bits are device number
        device = device / 2
        if pulse(i) > 10 then
           device = device + 16
        end if
      next
    end sub

    sub printCmd            'print device number
      locate 0,5
      print "   "
      locate 0,5
      print device

      locate 0,13           'print raw command number
      print "   "
      locate 0,13
      print cmd
    end sub

    sub PrintKey            'print translated button
      locate 1,9
      print "       "
      locate 1,9

      select case cmd       'translate command code
        case 0
          button = "One"
        case 1
          button = "Two"
        case 2
          button = "Three"
        case 3
          button = "Four"
        case 4
          button = "Five"
        case 5
          button = "Six"
        case 6
          button = "Seven"
        case 7
          button = "Eight"
        case 8
          button = "Nine"
        case 9
          button = "Zero"
        case 10
          button = "#####"
        case 11
          button = "Enter"
        case 12
          button = "#####"
        case 13
          button = "#####"
        case 14
          button = "#####"
        case 15
          button = "#####"
        case 16
          button = "Chan+"
        case 17
          button = "Chan-"
        case 18
          button = "Vol+"
        case 19
          button = "Vol-"
        case 20
          button = "Mute"
        case 21
          button = "Power"
        case else
          button = "     "
      end select
      print button
    end sub
```

<div class="informalfigure">

<div class="mediaobject" align="center">

![graphic](./images/selectb1.PNG)

</div>

</div>

</div>
