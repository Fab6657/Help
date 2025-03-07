<div class="section">

<div class="titlepage">

<div>

<div>

#### <span id="more_on_setting_variables_and_constants"></span>More on setting Variables and Constants

</div>

</div>

</div>

<span class="strong">**Explanation**</span>

Within GCBASIC you can use regular variable assignments. But, you can
also use C like maths assignments.

The following methods are also supported.

``` screen
    GLCDPrintLoc += 6
    CharCode -= 15
    CharCode++
    CharCode---
```

Within GCBASIC you can define binary, hexidecimal and decimal constants,
see
<a href="constants" class="link" title="Constants">Constants</a>.
Please note what is and what is not support with respect to assigning
numbers to constants. An example program examines what is supported.

``` screen
    #chip 16F88, 4
    #config Osc = MCLRE_OFF

    ' All these work
    #define Test1 0b11111111
    #define Test2 0B11111111
    #define Test3 255
    #define Test4 0xFF
    #define Test5 0xff
    #define Test6 0Xff

    # Proof - select each option one in turn
    dir porta Out

    porta = test1
    porta = test2
    porta = test3
    porta = test4
    porta = test5
    porta = test6
```

You can assigned values/numbers with all the methods shown above (for
constants and variables) but please be aware that you must Use '0' not
'00'. One zero equates to zero and two zeros will give you an unassigned
variable.

<span class="strong">**Constants:**</span>

A few critical constants are defined within GCBASIC , you can re-use
these constants. They include:

``` screen
    #define ON 1       ' These are defined in System.h
    #define OFF 0
    #define TRUE 255
    #define FALSE 0

    #define OSC = 1    ' These are defined in TIMER.H
    #define EXT = 2    ' and, are used by InitTimer0 command
    #define EXTOSC = 3
```

</div>
