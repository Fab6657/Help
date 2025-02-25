<div class="section">

<div class="titlepage">

<div>

<div>

### <span id="graphical_lcd_demonstration"></span>Graphical LCD Demonstration

</div>

</div>

</div>

<span class="strong">**Explanation:**</span>

This demonstration code shows the set of commands supported by GCBASIC.

<span class="strong">**Demonstration program:**</span>

``` screen
    ;Chip Settings
    #chip 16F877a,16

    #include <glcd.h>

    'Setup the GLCD
    #Define glcd_rw PORTD.3       'RW pin on LCD
    #Define glcd_reset PORTD.4    'Reset pin on LCD
    #Define glcd_cs1 PORTD.1      'CS1, CS2 can be reversed
    #Define glcd_cs2 PORTD.2      'CS1, CS2 are be reversed
    #Define glcd_rs PORTD.5       'D/I pin on LCD
    #Define glcd_enable PORTD.4   'E pin on LCD
    #Define glcd_db0 PORTB.0  'D0
    #Define glcd_db1 PORTB.1  'D1
    #Define glcd_db2 PORTB.2  'D2
    #Define glcd_db3 PORTB.3  'D3
    #Define glcd_db4 PORTB.4  'D4
    #Define glcd_db5 PORTB.5  'D5
    #Define glcd_db6 PORTB.6  'D6
    #Define glcd_db7 PORTB.7  'D7 on LCD

    'Specify the type of GLCD
    #define GLCD_TYPE GLCD_TYPE_KS0108
    #define GLCD_WIDTH 128
    #define GLCD_HEIGHT 64
    #define GLCD_PROTECTOVERRUN

    wait 1 s
    GLCDCLS
    GLCDPrint 0, 1, "GCBASIC "
    wait 1 s
    GLCDCLS

    rrun = 0
    dim msg1 as string * 16

    do forever

      GLCDCLS
      Box 18,30,28,40
      Line 0,0,127,63
      Line 0,63,127,0
      wait 1 s

      FilledBox 18,30,28,40
      wait 1 s

      GLCDCLS

        GLCDDrawString 30,0,"ChipMhz@"
        GLCDDrawString 78,0, str(ChipMhz)
        Circle(10,10,10,1)              'upper left
        Circle(117,10,10,1)             'upper right
        Circle(63,31,10,1)              'center
        Circle(63,31,20,1)              'center
        Circle(10,53,10,1)              'lower left
        Circle(117,53,10,1)             'lower right
        wait 1 s

        GLCDDrawString 30,0,"ChipMhz@"
        GLCDDrawString 78,0, str(ChipMhz)
        FilledCircle(10,10,10,1)         'upper left
        FilledCircle(117,10,10,1)        'upper right
        FilledCircle(63,31,10,1)         'center
        FilledCircle(63,31,20,1)         'center
        FilledCircle(10,53,10,1)         'lower left
        FilledCircle(117,53,10,1)        'lower right
        wait 1 s

        GLCDCLS
        GLCDDrawString 30,0,"ChipMhz@"
        GLCDDrawString 78,0, str(ChipMhz)
        Circle(10,0,10,1)                 'upper left
        Circle(117,0,10,1)                'upper right
        Circle(63,31,10,1)                'center
        Circle(63,31,20,1)                'center
        Circle(10,63,10,1)                'lower left
        Circle(117,63,10,1)               'lower right
        wait 1 s

        GLCDCLS
        GLCDDrawString 0,10,"Hello" 'Print Hello
        wait 1 s
        GLCDDrawString 0,10, "ASCII #:"    'Print ASCII #:
        Box 18,30,28,40                    'Draw Box Around ASCII Character
        for char = 0x30 to 0x39            'Print 0 through 9
          GLCDDrawString 16, 20 , Str(char)+"  "
          GLCDdrawCHAR 20, 30, char
          wait 250 ms
        next
        line 0,50,127,50                    'Draw Line using line command
        for xvar = 0 to 80                  'Draw line using Pset command
            pset xvar,63,on
        next
        FilledBox 18,30,28,40               'Draw Box Around ASCII Character '
        wait 1 s
        GLCDCLS
        GLCDDrawString 0,10,"End  "
        wait 1 s
        GLCDCLS

        workingGLCDDrawChar:
        dim gtext as string
        gtext = "KS0108"

            for xchar = 1 to gtext(0)      'Print 0 through 9
              xxpos = (1+(xchar*6)-6)
              GLCDDrawChar xxpos , 0 , gtext(xchar)
           next

        GLCDDrawString  1, 9, "GCBASIC @2021"
        GLCDDrawString  1, 18,"GLCD 128*64"
        GLCDDrawString  1, 27,"Using GLCD.H from GCB"
        GLCDDrawString  1, 37,"Using GLCD.H GCB@2021"
        GLCDDrawString  1, 45,"GLCDDrawChar method"
        GLCDDrawString  1, 54,"Test Routines"

        wait 1 s
        GLCDCLS

        msg1 = "Run = " +str(rrun)
        rrun++
        GLCDPrint 0, 3, msg1
        wait 1 s
        GLCDCLS

    loop
```

<span class="strong">**For more help, see**</span>
<a href="graphical_lcd_demonstration" class="link" title="Graphical LCD Demonstration">Graphical LCD Demonstration</a>,
<a href="glcdcls" class="link" title="GLCDCLS">GLCDCLS</a>,
<a href="glcddrawchar" class="link" title="GLCDDrawChar">GLCDDrawChar</a>,
<a href="glcdprint" class="link" title="GLCDPrint">GLCDPrint</a>,
<a href="glcdreadbyte" class="link" title="GLCDReadByte">GLCDReadByte</a>,
<a href="glcdwritebyte" class="link" title="GLCDWriteByte">GLCDWriteByte</a>,
<a href="pset" class="link" title="Pset">Pset</a>

</div>
