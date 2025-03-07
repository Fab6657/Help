<div class="section">

<div class="titlepage">

<div>

<div>

##### <span id="serprint"></span>SerPrint

</div>

</div>

</div>

<span class="strong">**Syntax:**</span>

``` screen
  SerPrint channel, value
```

<span class="strong">**Command Availability:**</span>

Available on all microcontrollers.

<span class="strong">**Explanation:**</span>

`SerPrint` is used to send a value over the serial connection. `value`
can be a string, integer, long, word or byte.

`channel` is the serial connection to send data through (1 \| 2 \|3 ).

`SerPrint` will not send any new line characters. If the chip is sending
to a terminal, these commands should follow `SerPrint`.

``` screen
    SerSend channel, 13
    SerSend channel, 10
```

<span class="strong">**Example:**</span>

``` screen
    'This program will display any values received over the serial
    'connection. If "pot" is received, the value of the analog sensor
    'will be sent.

    'Chip settings
    #chip 18F2525, 8

    'LCD settings
    #define LCD_IO 4
    #define LCD_WIDTH 20                ;specified lcd width for clarity only.  20 is the default width
    #define LCD_RS PORTC.7
    #define LCD_RW PORTC.6
    #define LCD_Enable PORTC.5
    #define LCD_DB4 PORTC.4
    #define LCD_DB5 PORTC.3
    #define LCD_DB6 PORTC.2
    #define LCD_DB7 PORTC.1

    'Serial settings
    #define RS232Out PORTB.0
    #define RS232In  PORTB.1

    'Set pin direction
    Dir RS232Out Out
    Dir RS232In In

    'Config Software-UART
    #define SendAHigh Set RS232Out ON
    #define SendALow Set RS232Out OFF
    #define RecAHigh Set RS232In ON
    #define RecALow Set RS232In OFF
    set RS232Out On

    Do
      'Potentiometer
      #define POT_PORT PORTA.0
      #define POT_AN AN0

      'Set pin direction
      Dir POT_PORT In

      'Create buffer variables to store received messages
      Dim Buffer As String
      Dim OldBuffer As String
      BufferSize = 0

      'Set up serial connection
      InitSer 1, r9600, 1 + WaitForStart, 8, 1, none, invert

      'Show test messages
      Print "Serial Tester"
      Wait 1 s
      SerPrint 1, "GCBASIC RS232 Test"
      SerSend 1, 13
      SerSend 1, 10
      Wait 1 s

      'Main loop
     'Get a byte from the terminal
      SerReceive 1, Temp

      'If Enter key was pressed, deal with buffer contents
      If Temp = 13 Then
        Buffer(0) = BufferSize

        'Try to execute commands in buffer
        If Not ExecCommand (Buffer) Then
          'Show message on bottom line, last message on top.
          CLS
          Print OldBuffer
          Locate 1, 0
          Print Buffer
          'Store the message for next time
          OldBuffer = Buffer
        End If

        BufferSize = 0
      End If
      'Backspace code, delete last character in buffer
      If Temp = 8 Then
        If BufferSize > 0 Then BufferSize -= 1
      End If
      'Received ASCII code between 32 and 127, add to buffer
      If Temp >= 32 And Temp <= 127 Then
        BufferSize += 1
        Buffer(BufferSize) = Temp
      End If
    Loop

    'Takes a sensor reading and sends it to terminal
    Sub SendSensorReading
      SerPrint 1, "Sensor Reading: "
      SerPrint 1, ReadAD10(POT_AN)
      SerSend 1, 13
      SerSend 1, 10
    End Sub

    'Will check the buffer for a command
    'If command found, run it and return true
    'If not, return false
    Function ExecCommand (CmdIn As String)
      ExecCommand = False
      'If received command is "pot", show potentiometer value
      If CmdIn = "pot" Then
        SendSensorReading
        ExecCommand = True
      End If
    End Function
```

<span class="strong">**For more help, see**</span>
<a href="rs232_software_overview" class="link" title="RS232 Software Overview">RS232 Software Overview</a>

</div>
