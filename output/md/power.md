<div class="section">

<div class="titlepage">

<div>

<div>

#### <span id="power"></span>Power

</div>

</div>

</div>

<span class="strong">**Syntax**</span>:

``` screen
    power( base, exponent )
```

<span class="strong">**Explanation:**</span>

This function raises a base to an exponent, i.e, `power(base,exponent)`.
Calculation powers will become large, in terms of long numbers, you must
ensure the program manage numbers remain within range of the defined
variables.

The `base` and `exponent` are Byte sized numbers in this method.  
The returned result is a Long.  
Non-negative numbers are assumed throughout.

<span class="strong">**Note:**</span> 0 raised to 0 is meaningless and
should be avoided, but, any other non-zero base raised to 0 is handled
correctly.

<span class="strong">**Example:**</span>

``` screen
    ;Thomas Henry -- 5/2/2014

    ;----- Configuration

    #chip 16F88, 8              ;PIC16F88 running at 8 MHz
    #config mclr=off            ;reset handled internally

    #include <maths.h>          ;required maths.h

    ;----- Constants

    #define LCD_IO 4            ;4-bit mode
    #define LCD_WIDTH 20                ;specified lcd width for clarity only.  20 is the default width
    #define LCD_RS PortB.2      ;pin 8 is LCD Register Select
    #define LCD_Enable PortB.3  ;pin 9 is LCD Enable
    #define LCD_DB4 PortB.4     ;DB4 on pin 10
    #define LCD_DB5 PortB.5     ;DB5 on pin 11
    #define LCD_DB6 PortB.6     ;DB6 on pin 12
    #define LCD_DB7 PortB.7     ;DB7 on pin 13
    #define LCD_NO_RW 1         ;Ground the RW line on LCD

    ;----- Variables

    dim i, j as byte

    ;----- Program

    dir PortB out               ;all outputs to the LCD
    for i = 1 to 10             ;do all the way from
      for j = 0 to 9            ;1^0 on up to 10^9
        cls
        print i
        print "^"
        print j
        print "="
        locate 1,0
        print power(i,j)        ;here's the invocation
        wait 1 S
      next j
    next i
```

<span class="strong">**Supported in &lt;MATHS.H&gt;**</span>

</div>
