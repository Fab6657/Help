<div class="section">

<div class="titlepage">

<div>

<div>

#### <span id="lcdcmd"></span>LCDCmd

</div>

</div>

</div>

<span class="strong">**Syntax:**</span>

``` screen
    LCDCMD value
```

<span class="strong">**Command Availability:**</span>

Available on all microcontrollers.

<span class="strong">**Explanation:**</span>

This command set LCD specific instructions to the LCD display. As shown
in the table below.

<div class="informaltable">

| <span class="strong">**INSTRUCTION**</span>             | <span class="strong">**Decimal**</span> | <span class="strong">**Hexadecimal**</span> |
|:--------------------------------------------------------|:---------------------------------------:|:-------------------------------------------:|
| Scroll display one character right (all lines)          |                   28                    |                     1E                      |
| Scroll display one character left (all lines)           |                   24                    |                     18                      |
| Home (move cursor to top/left character position)       |                    2                    |                      2                      |
| Move cursor one character left                          |                   16                    |                     10                      |
| Move cursor one character right                         |                   20                    |                     14                      |
| Turn on visible underline cursor                        |                   14                    |                     0E                      |
| Turn on visible blinking-block cursor                   |                   15                    |                     0F                      |
| Make cursor invisible                                   |                   12                    |                     0C                      |
| Blank the display (without clearing)                    |                    8                    |                     08                      |
| Restore the display (with cursor hidden)                |                   12                    |                     0C                      |
| Clear Screen                                            |                    1                    |                     01                      |
| Set cursor position (DDRAM address)                     |               128 + addr                |                  80+ addr                   |
| Set pointer in character-generator RAM (CG RAM address) |                64 + addr                |                  40+ addr                   |

</div>

<span class="strong">**Example 1:**</span>

``` screen
    ;Chip Settings
    #chip 16F88,8

    ;Defines (Constants)
    #define LCD_IO 4
    #define LCD_WIDTH 20                ;specified lcd width for clarity only.  20 is the default width
    #define LCD_RS PORTA.6
    #define LCD_NO_RW
    #define LCD_Enable PORTA.7
    #define LCD_DB4 PORTB.4
    #define LCD_DB5 PORTB.5
    #define LCD_DB6 PORTB.6
    #define LCD_DB7 PORTB.7

    Locate 0,0
    Print "Reset"
    wait 1 s
    cls

    LCD_Command_Tests:

    locate 0,8
    print "123456"
    'Scroll display one character right (all lines)       28
    '
    lcdcmd 28
    wait 1 s
    lcdcmd 28
    wait 1 s
    lcdcmd 28
    wait 1 s
    lcdcmd 28
    wait 1 s

    'Scroll display one character left (all lines)        24
    '
    lcdcmd 24
    wait 1 s
    lcdcmd 24
    wait 1 s
    lcdcmd 24
    wait 1 s
    lcdcmd 24
    wait 1 s


    'Home (move cursor to top/left character position)    2
    '
    lcdcursor flash
    lcdcmd 2
    wait 1 s

    'Move cursor one character left                       16
    '
    lcdcursor flash
    locate 0,8

    lcdcmd 16
    wait 1 s
    lcdcmd 16
    wait 1 s
    lcdcmd 16
    wait 1 s
    lcdcmd 16
    wait 1 s

    'Move cursor one character right                      20
    '
    lcdcmd 20
    wait 1 s
    lcdcmd 20
    wait 1 s
    lcdcmd 20
    wait 1 s
    lcdcmd 20
    wait 1 s
```

<span class="strong">**Example 2:**</span>

``` screen
    #chip 16F877A,20
    #option Explicit

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

    ;Here are various LCD commands which can be used.
    ;These are the LCD commands for the HD44780 controller
    #define clrHome = 1     ;clear the display, home the cursor
    #define home    = 2     ;home the cursor only
    #define RtoL    = 4     ;print characters right to left
    #define insR    = 5     ;insert characters to right
    #define LtoR    = 6     ;print characters left to right
    #define insL    = 7     ;insert characters to left
    #define lcdOff  = 8     ;LCD screen off
    #define lcdOn   = 12    ;LCD screen on, no cursor
    #define curOff  = 12    ;an alias for the above
    #define block   = 13    ;LCD screen on, block cursor
    #define under   = 14    ;LCD screen on, underline cursor
    #define undblk  = 15    ;LCD screen on, blinking and underline cursor
    #define CLeft   = 16    ;cursor left
    #define CRight  = 20    ;cursor right
    #define panR    = 24    ;pan viewing window right
    #define panL    = 28    ;pan viewing window left
    #define bus4    = 32    ;4-bit data bus mode
    #define bus8    = 48    ;8-bit data bus mode
    #define mode1   = 32    ;one-line mode (alias)
    #define mode2   = 40    ;two-line mode
    #define line1   = 128   ;go to start of line 1
    #define line2   = 192   ;go to start of line 2
    ;----- Variables
    dim char, msn, lsn, index, ii as byte
    ;----- Main Program
    LoadEeprom              ;load the EEprom with strings

    do forever
        printMsg(0)             ;print first message
        wait 3 S                ;pause 3 seconds
        printMsg(2)             ;print next message
        wait 3 S                ;pause 3 seconds
        repeat 5                ;blink it five times
          LCDCmd(lcdOff)       ;display off
          wait 500 mS           ;pause
          LCDCmd(lcdOn)        ;display on
          wait 500 mS           ;pause
        end repeat
        wait 1 S                ;pause before next demo
        ;demonstrate panning
        printMsg(4)             ;print next message
        wait 3 S                ;pause 3 seconds
        repeat 16
          LCDCmd(panL)         ;pan left a step at a time
          wait 300 mS           ;slow down to avoid blur
        end repeat
        repeat 16
          LCDCmd(panR)         ;then pan right
          wait 300 mS
        end repeat
        wait 1 S                ;pause before next demo
                                ;demonstrate moving the cursor
        printMsg(6)             ;print next message
        wait 3 S                ;pause 3 seconds
        LCDHome
        LCDCmd(under)          ;choose underline cursor
        for ii = 0 to 15         ;move cursor across first line
          LCDCmd(line1+ii)
          wait 200 mS
        next i
        for ii = 0 to 15         ;move cursor across second line
          LCDCmd(line2+ii)
          wait 200 mS
        next i
        for ii = 15 to 0 step -1 ;move cursor back over second line
          LCDCmd(line2+ii)
          wait 200 mS
        next i
        for ii = 15 to 0 step -1 ;move cursor back over first line
          LCDCmd(line1+ii)
          wait 200 mS
        next i
        wait 3 S
        ;demonstrate blinking block cursor
        printMsg(8)             ;print next message
        LCDHome                  ;home the cursor
        LCDCmd(block)          ;choose blinking block cursor
        wait 4 S                ;pause 4 seconds
        LCDCmd(mode1)          ;change to one long line mode
        LCDHome                  ;home the cursor again
        LCDCmd(curOff)         ;and disable it


        ;demonstrate scrolling a lengthy one-line marquee
        for ii = 0xd0 to 0xff    ;print next message - the remaining EEPROM
          EPread ii, char        ;fetch directly from eeprom
          print chr(char)
        next i
        wait 1 S
        LCDHome                  ;home cursor once more
        repeat 141               ;scroll message twice
          LCDCmd(panR)
          wait 250 mS
        end repeat
        wait 2 S
        LCDCmd(mode2)          ;change back to two line mode
        CLS                   ;clear the screen
        ;demonstrate all of the characters
        printMsg(11)             ;print next message
        for ii = 33 to 127       ;print first batch of ASCII characters
          LCDCmd(line1+12)       ;overwrite each character displayed
          print chr(ii)          ;this is the ASCII code
          wait 500 mS
        next i
        for ii = 161 to 255      ;print next batch of ASCII characters
          LCDCmd(line1+12)
          print chr(ii)
          wait 500 mS
        next i
        ;say good-bye
        LCDCmd(line2)
        printMsg(11)             ;print next message
        LCDHome                  ;home the cursor
    loop
    end

    ;----- Print a message to the LCD
    ;The parameter 'row' points to the start of the string.
    sub printMsg(in row as byte, in Optional StringLength As Byte = 15)
      Locate 0, 0              ;get set for first line

      for ii = 0 to StringLength
        index = row*16+ii
        EPread index, char        ;fetch next character and
        print chr(char)             ;transmit to the LCD
      next

      Locate 1,0              ;get set for second line
      for ii = 0 to StringLength
        index = (row+1)*16+ii
        EPread index, char        ;fetch next character and
        print chr(char)             ;transmit to the LCD
      next
    end sub

    sub loadEeprom

    ' Strings for EEPROM, Strings should be limited to 16 characters for the first 13 sstrings, then a long string to fill eeprom
    WriteEeprom "First we'll show"
    WriteEeprom "this message.   "
    WriteEeprom "Then we'll blink"
    WriteEeprom "five times.     "
    WriteEeprom "Now lets pan    "
    WriteEeprom "left and right. "
    WriteEeprom "Watch the line  "
    WriteEeprom "cursor move.    "
    WriteEeprom "A block cursor  "
    WriteEeprom "is available.   "
    WriteEeprom "Characters:     "
    WriteEeprom "Bye!            "
    WriteEeprom "in one line mode"
    WriteEeprom "Next well scroll this long message as a marquee"
    end sub


    ; Write to the device eeprom
    sub WriteEeprom ( in Estring() )

        Dim eeLocation as Byte 'if the EEPROM size was larger than 256 bytes then this would need to be a WORD

        for eeLocation = 1 to len ( Estring )
            HSersend Estring( eeLocation )
            epwrite eeLocation, Estring( eeLocation )
        next
    end sub
```

<span class="strong">**Supported in &lt;LCD.H&gt;**</span>

</div>
