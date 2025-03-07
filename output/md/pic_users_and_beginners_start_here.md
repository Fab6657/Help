<div class="section">

<div class="titlepage">

<div>

<div>

<span id="pic_users_and_beginners_start_here"></span>PIC users and Beginners: Start Here
-----------------------------------------------------------------------------------------

</div>

</div>

</div>

Welcome to GCBASIC.  This document is especially important for
experienced PIC users moving from MPASM or C so please spend a few
seconds here before you start.   It could save you hours of frustration.

As a PIC user most of us are conditioned, regardless of the Assembler or
Compiler, to reach for the devices data sheet first and try to work out
how to setup the Oscillator, interrupt vectors and Configuration bits.

<span class="strong">**Do not DO IT**</span>.   read this document first
as it will give you some great insights.    For the basic operation the
only setup and configuration required for a GCBASIC program is the name
of the target Device i.e. `#Chip 16f1619`.    That is it, honestly,
GCBASIC will do the rest and will determine the optimal Oscillator
settings, interrupt vectors, Configuration bits etc

Next we would start deciding on and including the Device files and
libraries that we intend to use.  <span
class="strong">**STOP**</span>.   Let GCBASIC decide.    GCBASIC is
creating Portable Code, it doesn’t care if you use a PIC12, PIC18 or an
ATmega328.   You write in BASIC and at compile time GCBASIC will decide
which core libraries to include based on the instructions you have used
and the target device you specified in the \#chip statement.

Finally we would decide on the pins to use, their port names, which
register bits are needed to make them inputs or outputs and override any
Analog function if a digital function is desired.

Again, I say let GCBASIC DO IT…​…​…​ `Dir PortC.0 In` - Will set Pin RC0
to a Digital Input.    There is no need to manually set the TRIS
register or see if there is an associated ADCON bit to set or clear.

Putting it all together: An example GCBASIC program.

``` screen
    #Chip 16f1619

    #Define LED PortC.0

    Dir LED Out

    Do
      LED = !LED
      Wait 500 ms
    Loop
```

That is it. If you have an LED attached to PortC.0 (LED DS1 on the Low
Pin Count Board that shipped with the PICKit 2 or PICKit 3
programmer).   It will start to Blink confirming that you have a working
microcontroller and hardware.

To change target device or family just change the \#Chip Entry along
with the Pin you have the LED on and recompile.   it Really IS as Simple
as that to get started in GCBASIC.

You can manually override GCBASIC and set every register, every flag,
every BIT, every Configuration ‘Fuse’ and every vector if you wish, but
why bother doing it upfront?   Rather get your code working with the
default settings and then adjust from there, if needed, as your
confidence grows.

One final bit of advice, the IDE tool bar has a “View Demos” button, use
it, there are examples of all of the most common programming challenges
and many different devices which, along with the Help files, will answer
most of your questions. The Forum is a friendly place too, so do not be
shy to introduce yourself and ask for help.

</div>
