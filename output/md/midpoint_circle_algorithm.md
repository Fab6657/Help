<div class="section">

<div class="titlepage">

<div>

<div>

### <span id="midpoint_circle_algorithm"></span>Midpoint Circle Algorithm

</div>

</div>

</div>

<span class="strong">**Explanation:**</span>

GCBASIC can draw circles using the midpoint circle algorithm. The
midpoint circle algorithm determines the points needed for drawing a
circle. The algorithm is a variant of
<a href="https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm" class="link">Bresenham’s line algorithm</a>,
and is thus sometimes known as Bresenham’s circle algorithm, although
not actually invented by
<a href="https://en.wikipedia.org/wiki/Jack_Elton_Bresenham" class="link">Jack E. Bresenham</a>.

The example program below show the midpoint circle algorithm within
GCBASIC.

<span class="strong">**Example Output on GLCD Device:**</span>

<div class="informalfigure">

<div class="mediaobject" align="center">

![graphic](./images/midpointcirclealgorithmb1.PNG)

</div>

</div>

``` screen
    'Midpoint Circle algorithm
    'Chip model
    #chip 16F886, 8             ;PIC16F88 running at 8 MHz
    #config mclr=off            ;reset handled internally

    #include <glcd.h>

    ;----- Constants

    ;Pinout is shown for the LCM12864H-FSB-FBW
    ;graphical LCD available from Amazon.

    ;       +5V                 ;LCD pin 1
    ;       ground              ;LCD pin 2
    ;       Vo = wiper of pot   ;LCD pin 3
    #define GLCD_DB0 PORTB.0    ;LCD pin 4
    #define GLCD_DB1 PORTB.1    ;LCD pin 5
    #define GLCD_DB2 PORTB.2    ;LCD pin 6
    #define GLCD_DB3 PORTB.3    ;LCD pin 7
    #define GLCD_DB4 PORTB.4    ;LCD pin 8
    #define GLCD_DB5 PORTB.5    ;LCD pin 9
    #define GLCD_DB6 PORTB.6    ;LCD pin 10
    #define GLCD_DB7 PORTB.7    ;LCD pin 11
    #define GLCD_CS2 PORTA.0    ;LCD pin 12
    #define GLCD_CS1 PORTA.1    ;LCD pin 13
    #define GLCD_RESET PORTA.2  ;LCD pin 14
    #define GLCD_RW PORTA.3     ;LCD pin 15
    #define GLCD_RS PORTA.4     ;LCD pin 16
    #define GLCD_ENABLE PORTA.6 ;LCD pin 17
    ;       Vee = pot low side  ;LCD pin 18
    ;       backlight anode     ;LCD pin 19
    ;       backlight cathode   ;LCD pin 20

    #define GLCD_TYPE GLCD_TYPE_KS0108
    #define GLCD_WIDTH 128
    #define GLCD_HEIGHT 64

    ;----- Program

    Do forever

        GLCDDrawString 30,0,"ChipMhz@"
        GLCDDrawString 78,0, str(ChipMhz)
        Circle(10,10,10,0)            ;upper left
        Circle(117,10,10,0)           ;upper right
        Circle(63,31,10,0)            ;center
        Circle(63,31,20,0)            ;center
        Circle(10,53,10,0)            ;lower left
        Circle(117,53,10,0)           ;lower right
        GLCDDrawString 30,54,"PIC16F886"

    loop
```

</div>
