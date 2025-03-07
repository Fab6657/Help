<div class="section">

<div class="titlepage">

<div>

<div>

#### <span id="on_interrupt_the_default_handler"></span>On Interrupt: The default handler

</div>

</div>

</div>

<span class="strong">**Introduction**</span>

GCBASIC supports a default interrupt handler in two modes:

<div class="orderedlist">

1.  You can define the interrupt flags and the default handler (a sub
    routine) will executed
2.  You can define an On Interrupt event Call handler where the handler
    is executed that matches the event and where all other define/valid
    events are handled by the default handler (a sub routine), The
    easiest way to write an interrupt handler is to write it in GCBASIC
    in conjunction with the On Interrupt statement. On Interrupt tells
    microcontroller to activate its internal interrupt handling and to
    jump to a predetermined interrupt handler (a sub routine that has
    been defined) when the interrupt handler (the sub routine) has
    completed processing returns to correct address in the program. See
    <a href="on_interrupt" class="link" title="On Interrupt">On Interrupt</a>.

</div>

This method of supports the handling interrupts by enabling a default
interrupt subroutine.

<span class="strong">**Example 1**</span>

This example shows if an event occurs the microcontroller will be
program to jump to the interrupt vector and the program will not know
the event type, it will simple execute the Interrupt subroutine. This
code is not intended as a meaningful solution and intended to show the
functionality only. An LED is attached to PORTB.1 via a suitable
resistor. It will light up when the Interrupt event has occurred.

``` screen
    #chip 16f877a, 4
    dir PORTB.1 out
    Set PORTB.1 Off

    'Note: there is NO On Interrupt handler
    InitTimer1 Osc, PS1_8
    SetTimer 1, 1
    StartTimer 1
    'Manually set Timer1Overflow to the overflow event
    'this will event will be handled by the Interrupt sub routine
    TMR1IE = 1
    end

    Sub Interrupt
      Set PORTB.1 On
      TMR1IF = 0
    End Sub
```

<span class="strong">**Example 2**</span>

Any events that are not dealt with by On Interrupt will result in the
code in the Interrupt subroutine executing. This example shows the
operation of two interrupt handlers - is not intended as a meaningful
solution.

LEDs are attached to PORTB.1 and PORTB.2 via suitable resistors. They
will light up when the Interrupt events occur.

``` screen
    #chip 16f877a, 4
    On Interrupt Timer1Overflow call Overflowed

    dir PORTB.1 out
    Set PORTB.1 Off

    dir PORTB.2 out
    Set PORTB.2 Off

    InitTimer1 Osc, PS1_8
    SetTimer 1, 1
    StartTimer 1

    InitTimer2 PS2_16, PS2_16
    SetTimer 2, 255
    StartTimer 2

    'Manually set Timer2Overflow to create a second event
    'this will event will be handled by the Interrupt sub routine
    TMR2IE = 1
    end

    Sub Interrupt
      Set PORTB.2 On
      TMR2IF = 0
    End Sub

    Sub Overflowed
      Set PORTB.1 On
      TMR1IF = 0
    End Sub
```

</div>
