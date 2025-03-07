<div class="section">

<div class="titlepage">

<div>

<div>

### <span id="_option_nolatch"></span>\#Option NoLatch

</div>

</div>

</div>

<span class="strong">**Syntax:**</span>

``` screen
    #option nolatch
```

This option disables PORTx to LATx redirection.

<span class="strong">**Introduction:**</span>

The GCBASIC compiler will redirect all I/O pin writes from PORTx to LATx
registers on 16F1/18F Microchip PIC microcontrollers.

The Microchip PIC mid-range microcontrollers use a sequence known as
<span class="strong">**Read-Modify-Write**</span> (RMW) when changing an
output state (1 or 0) on a pin. This can cause unexpected behavior under
certain circumstances.

When your program changes the state on a specific pin, for example RB0
in PORTB, the microcontroller first <span
class="strong">**READs**</span> all 8 bits of the PORTB register which
represents the states of all 8 pins in PORTB (RB7-RB0).

The microcontroller then stores this data in the MCU. The bit associated
with RB that you’ve commanded to <span class="strong">**MODIFY**</span>
is changed, and then the microcontrollers <span
class="strong">**WRITEs**</span> all 8 bits (RB7- RB0) back to the PORTB
register.

During the first reading of the PORT register, you will be reading the
actual state of the physical pin. The problem arises when an output pin
is loaded in such a way that its logic state is affected by the load.
Instances of such loads are LEDs without current-limiting resistors or
loads with high capacitance or inductance.

For example, if a capacitor is attached between pin and ground, it will
take a short while to charge when the pin is set to 1. On the other
hand, if the capacitor is discharged, it acts like a short circuit,
forcing the pin to '0' state, and, therefore, a read of the PORT
register will return 0, even though we wrote a 1 to it.

GCBASIC resolves this issue using the LATx register when writing to
ports, rather than using PORTx registers. Writing to a LATx register is
equivalent to writing to a PORTx register, but readings from LATx
registers return the data value held in the port latch, regardless of
the state of the actual pin. So, for reading use PORTx.

<span class="strong">**Note:**</span>

You can use the `#option nolatch` if problems occur with compiler
redirection.

</div>
