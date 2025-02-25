<div class="section">

<div class="titlepage">

<div>

<div>

### <span id="generate_accurate_pulses"></span>Generate Accurate Pulses

</div>

</div>

</div>

<span class="strong">**Explanation:**</span>

The `PulseOut` Command is a reliable method for generating pulses if
accuracy is not critical, the `PulseOut` command uses a calculation of
the clock to speed for the timing .

If you need better accuracy and resolution then an alternative approach
is required.

To generate pulses in the 100 us to 2500 us range with an accuracy of +-
1us over this range is practical using the approach shown in this
example.

This example code works on a midrange PIC16F690 operating at 8Mhz.
However, it should work on any Microchip PIC microcontroller, but may
need some minor modifications.

<span class="strong">**Usage:**</span>

``` screen
    Pulse_Out_us ( word_value )
```

<span class="strong">**How It Works:**</span>

`Timer1` is loaded with a preset value based upon the variable passed to
the sub routine. The timer (`Timer1`) is started and the pulse pin (the
output pin) is set high. When `Timer1` overflows the Timer1 interrupt
flag bit (`TMR1IF`) is set. This causes the program to exit a polling
loop and set the pulse Pin off. Then, `Timer1` is stopped and `TMRIF`
flag is cleared and the sub routine exits.

This method supports delays between 5 us and 65535 us and uses Timer1.

<span class="strong">**Test Results:**</span>

These tests were completed using a Saleae Logic Analyzer.

<div class="informaltable">

| <span class="strong">**Pulse setting**</span> | <span class="strong">**Time Results**</span> |
|:----------------------------------------------|:---------------------------------------------|
| `Pulse_Out_us (2500)`                         | `2501.375 us`                                |
| `Pulse_Out_us (1000)`                         | `1000.750 us`                                |
| `Pulse_Out_us (100)`                          | `100. 125 us`                                |
| `Pulse_Out_us (10)`                           | `10.125 us`                                  |
| `Pulse_Out_us with less then 4`               | `Unreliable results`                         |

</div>

<span class="strong">**Demonstration program:**</span>

``` screen
    ;**************************************
    ; Code:  Output an accurate pulse
    ; Author: William Roth 03/13/2021
    ;**************************************

    #chip 16F690,8

    ; ---- Define Hardware settings
    ; ---- Define I2C settings - CHANGE PORTS AS REQUIRED
    #define I2C_MODE Master
    #define I2C_DATA PORTB.4
    #define I2C_CLOCK PORTB.6
    #define I2C_DISABLE_INTERRUPTS ON

    ; ---- Set up LCD - Using I2C LCD Backpack
    #define LCD_IO 10
    #define LCD_WIDTH 20                ;specified lcd width for clarity only.  20 is the default width
    #define LCD_I2C_Address_1 0x4e ; default to 0x4E
    ; ----  May need to use SLOW or MEDIUM if your LCD is a slower device.
    #define LCD_SPEED Medium
    #define LCD_Backlight_On_State  1
    #define LCD_Backlight_Off_State 0

    CLS
    ; ---- USART settings
    #define USART_BAUD_RATE 38400
    #define USART_TX_BLOCKING
    DIR PORTB.7 OUT

    ; ---- Setup Pulse parameters
    #define PulsePin PORTC.4
    Dim Time_us As WORD
    Dir PulsePin Out     'Pulsout pin
    Set PulsePin off

    ; ---- Setup Timer
    InitTimer1 Osc, PS1_2  'For 8Mhz Chip
    'InitTimer1 Osc, PS1_4, 'For 16 Mhz Chip
    TMR1H = 0: TMR1L = 0   'Clear timer1
    TMR1IF = 0  'Clear timer1 int flag
    TMR1IE = on 'Enable timer1 Interrupt (Flag only)

    ' **** This is the MAIN loop *****
    Do
        PULSE_OUT_US (2500)  'Measured as 2501.375 us
        wait 19 ms
        Pulse_Out_US (1000)  'Measured as 1000.750 us
        wait 19 ms
        Pulse_Out_US (100)   'Measured as 100.125 us
        wait 19 ms
        Pulse_Out_US (10)    'Measured as 10.125 us
        Wait 19 ms
    loop

    SUB PULSE_OUT_US (IN Variable as WORD)
    TMR1H = 65535 - Variable_H      'Timer 1 Preset High
    TMR1L = (65535 - Variable) + 4  'Timer 1 Preset Low
    Set TMR1ON ON                'Start timer1
    Set PulsePin ON               'Set Pin high
    Do While TMR1IF = 0      'Wait  for Timer1 overflow
        Loop
    Set PulsePin off          ' Pin Low
    Set TMR1ON OFF            ' Stop timer 1
    TMR1IF = 0             'Clear the Int flag
    END SUB
```

Also see
<a href="pulseout" class="link" title="PulseOut">PulseOut</a>

</div>
