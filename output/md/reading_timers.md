<div class="section">

<div class="titlepage">

<div>

<div>

#### <span id="reading_timers"></span>Reading Timers

</div>

</div>

</div>

GCBASIC has the following functions to read the current timer value.
They are:

``` screen
    Timer0()
    Timer1()
    Timer2()
    Timer3()
    Timer4()
    Timer5()
    Timer6()
    Timer7()
    Timer8()
    Timer10()
    Timer12()
```

Note that these functions should only be used to read the timer value.
To write the timer value, `settimer` should be used.

Not all of these functions are available on all microcontrollers. For
example, if a microcontrollers has three timers, then typically only
`Timer0`, `Timer1` and `Timer2` will be available.

Please refer to the datasheet for your microcontroller to determine the
supported timer numbers, and if a specific timer is 8-bit or 16-bit.

</div>
