<div class="section">

<div class="titlepage">

<div>

<div>

### <span id="i2c_slave_hardware"></span>I2C Slave Hardware

</div>

</div>

</div>

<span class="strong">**Explanation:**</span>

This program demonstrates how to control and display using a LCD the
code for the keypad.

This program can be adapted. This program uses the hardware I2C module
within the microcontroller. If your microcontroller does not have a
hardware I2C module then please use the software I2C GCBASIC library for
most microcontrollers.

This program also has an interrupt driven I2C handler to manage the I2C
from the Start event.

<span class="strong">**Demonstration program:**</span>

``` screen
    'Code for the keypad and LCD Microchip PIC microcontroller on the Microlab board v2
    'microcontroller is responsible for:
    ' - Reading keypad
    ' - Displaying data on LCD
    ' - communication with main Microchip PIC microcontroller via I2C
    ' - providing 5 keypad lines to main Microchip PIC microcontroller (for compatibility)
    ' - receiving remote control signals for button and keypad

    'This code has support for two keypad layouts. This is one possible layout:
    '0123
    '4567
    '89AB
    'CDEF
    'And this is the other possible layout:
    '123A
    '456E
    '789D
    'A0BC
    'Select the keypad layout by uncommenting one of these lines:
    '#define KEYPAD_KEYMAP KeypadMap0123
    #define KEYPAD_KEYMAP KeypadMap123F

    'Chip and config
    #chip 16F882, 8

    'Ports connected to keypad
    'Column ports need pullups, hence columns are on PORTB for built in weak pullups
    #define KEYPAD_COL_1 PORTB.4
    #define KEYPAD_COL_2 PORTB.5
    #define KEYPAD_COL_3 PORTB.6
    #define KEYPAD_COL_4 PORTB.7
    #define KEYPAD_ROW_1 PORTA.4
    #define KEYPAD_ROW_2 PORTA.3
    #define KEYPAD_ROW_3 PORTA.2
    #define KEYPAD_ROW_4 PORTA.1

    'Ports connected to LCD
    #define LCD_IO 4
    #define LCD_WIDTH 20                ;specified lcd width for clarity only.  20 is the default width
    #define LCD_RW PORTA.7
    #define LCD_RS PORTA.6
    #define LCD_Enable PORTA.5
    #define LCD_DB4 PORTA.4
    #define LCD_DB5 PORTA.3
    #define LCD_DB6 PORTA.2
    #define LCD_DB7 PORTA.1
    #define BACKLIGHT PORTA.0

    'Button port (for remote control)
    #define BUTTON PORTB.0

    'Keypad ports connected to main Microchip PIC microcontroller
    'These are disabled when KeyoutDisabled = true
    #define KEYOUT_A PORTC.5
    #define KEYOUT_B PORTC.2
    #define KEYOUT_C PORTC.1
    #define KEYOUT_D PORTC.0
    #define KEYOUT_DA PORTB.1

    'I2C ports
    #define I2C_DATA PORTC.4
    #define I2C_CLOCK PORTC.3

    'RS232/USART settings
    'To do if/when remote support needed

    'Initialise
    Dir KEYOUT_A Out
    Dir KEYOUT_B Out
    Dir KEYOUT_C Out
    Dir KEYOUT_D Out
    Dir KEYOUT_DA Out

    Dir BACKLIGHT Out
    Dir BUTTON In 'Is an output, turn off by switching pin to Hi-Z

    'Initialise I2C Slave
    'I2C pins need to be input for SSP module
    Dir I2C_DATA In
    Dir I2C_CLOCK In
    HI2CMode Slave
    HI2CSetAddress 128

    'Buffer for incoming I2C messages
    'Each message takes 4 bytes
    Dim I2CBuffer(10)
    BufferSize = 0
    OldBufferSize = 0

    'Set up interrupt to process I2C
    On Interrupt SSP1Ready Call I2CHandler

    'Enable weak pullups on B4-7 (keypad col pins)
    NOT_RBPU = 0
    WPUB = b'11110000'

    'Key buffers
    '255 indicates no key, other value gives currently pressed key
    RemoteKey = 255
    OutKey = 255
    KeyoutDisabled = False 'False if KEYOUT lines used to send key

    'Main loop
    Do

        'Read keypad, send value
        CheckPressedKeys
        SendKeys

        'Check for I2C messages
        ProcessI2C

    Loop

    'This keymap table is for this arrangement:
    '0123
    '4567
    '89AB
    'CDEF
    Table KeypadMap0123
        3
        7
        11
        15
        2
        6
        10
        14
        1
        5
        9
        13
        0
        4
        8
        12
    End Table

    'This keymap table is for this arrangement:
    '123F
    '456E
    '789D
    'A0BC
    Table KeypadMap123F
        15
        14
        13
        12
        3
        6
        9
        11
        2
        5
        8
        0
        1
        4
        7
        10
    End Table

    Sub CheckPressedKeys
        'Subroutine to:
        ' - Read keypad
        ' - Check remote keypress
        ' - Decide which key to output

        'Read keypad
        If RemoteKey <> 255 Then
            OutKey = RemoteKey
        Else
            EnableKeypad
            OutKey = KeypadData

        End If

    End Sub

    Sub EnableKeypad
        'Disable LCD so that keypad can be activated
        Set LCD_RW Off 'Write mode, don't let LCD write

        'Re-init keypad
        InitKeypad

    End Sub

    Sub I2CHandler
        'Handle I2C interrupt
        'SSPIF doesn't trigger for stop condition, only start!

        'If buffer full flag set, read

        Do While HI2CHasData
            HI2CReceive DataIn

            'Sending code
            If BufferSize = 0 Then
                LastI2CWasRead = False
                'Detect read address
                If DataIn = 129 Then
                    LastI2CWasRead = True

                    HI2CSend OutKey

                    KeyoutDisabled = True
                    Dir KEYOUT_A In
                    Dir KEYOUT_B In
                    Dir KEYOUT_C In
                    Dir KEYOUT_D In
                    Dir KEYOUT_DA In

                    Exit Sub
                End If
            End If

            If BufferSize < 10 Then I2CBuffer(BufferSize) = DataIn
            BufferSize += 1
        Loop

    End Sub

    Sub SendKeys

        'Don't run if not using KEYOUT lines
        If KeyoutDisabled Then Exit Sub

        'Send pressed keys
        If OutKey <> 255 Then
            'If there is a key pressed, set output lines
            If OutKey.0 Then
                KEYOUT_A = 1
            Else
                KEYOUT_A = 0
            End If
            If OutKey.1 Then
                KEYOUT_B = 1
            Else
                KEYOUT_B = 0
            End If
            If OutKey.2 Then
                KEYOUT_C = 1
            Else
                KEYOUT_C = 0
            End If
            If OutKey.3 Then
                KEYOUT_D = 1
            Else
                KEYOUT_D = 0
            End If

            KEYOUT_DA = 1
        Else
            'If no key pressed, clear data available line to main Microchip PIC microcontroller
            KEYOUT_DA = 0
        End If

    End Sub

    Sub ProcessI2C

        If HI2CStopped Then
            IntOff

            If LastI2CWasRead Then BufferSize = 0

            If BufferSize <> 0 Then
                OldBufferSize = BufferSize
                BufferSize = 0
            End If
            IntOn
        End If

        If OldBufferSize <> 0 Then

            CmdControl = I2CBuffer(1)

            'Set backlight
            If CmdControl.6 = On Then
                Set BACKLIGHT On
            Else
                Set BACKLIGHT Off
            End If

            'Set R/S bit
            LCD_RS = CmdControl.4

            'Send bytes to LCD
            LCDDataBytes = CmdControl And 0x0F
            If LCDDataBytes > 0 Then
                For CurrSendByte = 1 To LCDDataBytes
                    LCDWriteByte I2CBuffer(LCDDataBytes + 1)
                Next
            End If
            'LCDWriteByte I2CBuffer(2)

            OldBufferSize = 0
        End If

    End Sub
```

</div>
