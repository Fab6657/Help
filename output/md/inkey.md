<div class="section">

<div class="titlepage">

<div>

<div>

#### <span id="inkey"></span>InKey

</div>

</div>

</div>

<span class="strong">**Syntax:**</span>

``` screen
    output = InKey
```

<span class="strong">**Command Availability:**</span>

Available on all microcontrollers.

<span class="strong">**Explanation:**</span>

The `InKey` function will read the last pressed key from a PS/2
keyboard, and return an ASCII value corresponding to the key. If no key
is pressed, then `InKey` will return 0.

It will also monitor Caps Lock, Num Lock and Scroll Lock keys, and
update the status LEDs as appropriate.

<span class="strong">**Example:**</span>

``` screen
  'A program to accept messages from a standard PS/2 keyboard
    'Any keys pressed will be shown on an LCD screen.

    'Hardware settings
    #chip 18F4620, 20

    'LCD connection settings
    #define LCD_IO 4
    #define LCD_WIDTH 20                ;specified lcd width for clarity only.  20 is the default width
    #define LCD_DB4 PORTD.4
    #define LCD_DB5 PORTD.5
    #define LCD_DB6 PORTD.6
    #define LCD_DB7 PORTD.7
    #define LCD_RS PORTD.0
    #define LCD_RW PORTD.1
    #define LCD_Enable PORTD.2

    'PS/2 connection settings
    #define PS2Clock PORTC.1
    #define PS2Data PORTC.0
    #define PS2_DELAY 10 ms

    'Set up key log
    Dim KeyLog(32)
    DataCount = 0
    KeyLog(1) = 32

    Main:
        'Read the last pressed key
        KeyIn = INKEY
        'If no key pressed, try reading again
        If KeyIn = 0 Then Goto Main

        'Escape pressed - clear message
        If KeyIn = 27 Then
            DataCount = 0
            For DataPos = 1 to 32
                KeyLog(DataPos) = 32
            Next
            Goto DisplayData
        End If

        'Backspace pressed - delete last character
        If KeyIn = 8 Then
            If DataCount = 0 Then Goto Main
            KeyLog(DataCount) = 32
            DataCount = DataCount - 1
            Goto DisplayData
        End If

        'Otherwise, add the character to the buffer
        If KeyIn >= 31 And KeyIn <= 127 Then
            DataCount = DataCount + 1
            KeyLog(DataCount) = KeyIn
        End If

    DisplayData:
        'Display key buffer
        'LCDWriteChar is used instead of Print for greater control
        CLS
        For DataPos = 1 to DataCount
            If DataPos = 17 then Locate 1, 0
            LCDWriteChar KeyLog(DataPos)
        Next

    Goto Main
```

</div>
