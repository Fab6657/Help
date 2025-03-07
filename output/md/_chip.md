<div class="section">

<div class="titlepage">

<div>

<div>

### <span id="_chip"></span>\#chip

</div>

</div>

</div>

<span class="strong">**Syntax:**</span>

``` screen
    #chip model, frequency
```

<span class="strong">**Explanation:**</span>

The `#chip` directive is used to specify the chip model and frequency
that GCBASIC will use.

The `model` is the specific microcontroller - examples are "16F819".

The `frequency` is the frequency of the chip in MHz, and is required for
the delay and PWM routines. The following constants simplify setting
specific frequencies. `31k`, `32.768K`, `125k`, `250k` or `500k`. Any of
these constant can be used. As shown in the example below.

If `frequency` is not present the compiler will select a frequency
default frequency that should work for the microcontroller.

<div class="orderedlist">

1.  If the chip has an internal oscillator, the compiler will use that
    and pick the highest frequency it supports.
2.  If the chip does not have an internal oscillator, then GCBASIC will
    assume that the chip is being run at its maximum possible clock
    frequency using an external crystal.
3.  If you are using an external crystal then you must specify a chip
    frequency.

</div>

When using an AVR, there is no need to specify "AT" before the name.

<span class="strong">**Examples:**</span>

``` screen
    #chip 12F509, 4
    #chip 18F4550, 48
    #chip 16F88, 0.125
    #chip tiny2313, 1
    #chip mega8, 16
    #chip 12f1840, 31k
    #chip 12f1840, 500k
    #chip 12f1840, 250k
    #chip 12f1840, 125k

    'Select the internal low frequency oscillator. The microcontroller must have a low frequency oscillator option.  The internal oscillator is automatically selected.
    #chip 16f18326, 31k

    'Select the external SOSC clock source.
    #chip 16f18855, 32.768k
    #config osc=SOSC
```

<span class="strong">**Setting Other Clock frequencies:**</span> Some
alternative compilers allow value of the clock frequency to be set with
the numerical value in Hertz (<span class="emphasis">*i.e.*</span>
24576000). This can be useful when using the clock frequencies other
than standard frequencies.

GCBASIC requires clock frequencys to be specified in MHz, but will
accept decimal points. For example, if you wanted to run a 16F1827 at
24576000 Hz, you would write the following:

``` screen
    #chip 16F1827, 24.576
```

<span class="strong">**GCBASIC support for microcontrollers:**</span>

Each microcontroller has a microcontroller data file. This file is
located in \\GCBasic\\chipdata\\ folder when installed.

An example is 12F1840.dat

The there are two sections in the microcontroller data file that control
the "chip frequency", they are:

``` literallayout
*[ChipData]* and *[ConfigOps]*
```

<span class="strong">**ChipData section**</span>

The ChipData section for 12F1840 microcontroller. The 12F1840 is used an
example

``` screen
    [ChipData]
    Prog=4096
    EEPROM=256
    RAM=256
    I/O=6
    ADC=4
    MaxMHz=32
    IntOsc=32, 16, 8, 4, 2, 1, 0.5, 0.25, 0.125
    31kSupport=INTOSC,OSCCON,2
    Pins=8
    Family=15
    ConfigWords=2
    PSP=0
    MaxAddress=4095
```

The IntOsc line specifies the supported internal clock frequencies - The
12F1840 microcontroller supports nine internal frequencies (ChipMHz).
\#Chip is used as follows: The 31kSupport line specifies the chip
supports 31k for internal clock frequency.

``` screen
    #chip 12F1840, 32
```

A ChipMHz of 32 does two things.

<div class="orderedlist">

1.  When using the internal oscillator, it tells the compiler to set the
    chip clock frequency (FOSC) to 32MHz
2.  It tells the compiler to calculate all delays (wait times) based
    upon FOSC of 32 MHz. Unlike Picaxe Basic (and other compilers)
    GCBASIC delays ("wait") are correct regardless of the setting of
    FOSC. If you set the internal oscillator to 4 MHz a "wait 1 ms" will
    still be 1 ms.

</div>

If you set chipMHz to something other than the valid options in the
\[ChipData\] IntOsc section of the microcontroller specific dat file,
then, the compiler assumes that you are using an external oscillator and
will calculate the delays according to the value you use. The wait times
will be incorrect if you are not using an external oscillator at the
same frequency as ChipMhz.

``` screen
    Example:  #chip 12F1840, 12
```

Since "12" is not a valid internal osc frequency, the microcontroller
FOSC will default to 8 MHz because there is no external crystal
installed. However, the wait times will be incorrect as they will be
calculated by the compiler based upon a 12 Mhz clock.

<span class="strong">**ConfigOps section**</span>

The \[ConfigOps\] section of 12F1840.dat is towards the end of the chip
data file. For the 12F1840 is looks like this

``` screen
    [ConfigOps]
    OSC=LP,XT,HS,EXTRC,INTOSC,ECL,ECM,ECH
    WDTE=OFF,SWDTEN,NSLEEP,ON
    PWRTE=ON,OFF
    MCLRE=OFF,ON
    CP=ON,OFF
    CPD=ON,OFF
    BOREN=OFF,SBODEN,NSLEEP,ON
    CLKOUTEN=ON,OFF
    IESO=OFF,ON
    FCMEN=OFF,ON
    WRT=ALL,HALF,BOOT,OFF
    PLLEN=OFF,ON
    STVREN=OFF,ON
    BORV=HI,LO,19
    LVP=OFF,ON
```

`OSC` specifies which oscillator options are available for the specific
microcontroller. `INTOSC` is the internal oscillator. All others are
some form of external clock source. `PLLEN` sets the internal Phase Lock
Loop either on or off. With this chip the default clock frequency is 8
Mhz. The PLL multiplies this by 4. So to get 32 Mhz the basic internal
oscillator will be 8 Mhz then multiplied by 4. For 16 MHz it wil be 4
multiplied by 2.

GCB sets the PLL automatically, so this option should generally be left
alone. IF PLLEN is set to ON, then GCB may not be able to set the
correct frewuency of the internal oscillator. Only set PLL = ON if you
know what you are doing.

It is a good practice to set the oscillator source in \#config at the
beginning of your code when you are not using the internal oscillator.
This prevents potential errors. Example:

``` screen
    #Chip 12F1840, 16
    #Config OSC = INTOSC   'This is normally not required as the internal oscillator is the default oscillator.
```

In this example above, GCBASIC will automatically set the necessary OSC
bits for the microcontroller. Frequency bits will be set to 4 MHz and
the PLL will be turned on and wait times will be calculated on an FOSC
of 16.

You can set the clock to other frequencies but you have to put the PIC
into `EC` or `External Clock` mode and then supply that specific clock
frequency to the OSC1 pin.

There are three EC modes on the PIC12F1840:

``` screen
    ECL - 0 MHz - 0.5 MHz
    ECM - 0.5 MHz - 4 MHz
    ECH = 4 MHz - 32MHz
```

Example: For a 2.1 MHz clock you would need to set the \#config and the
clock frequency, and, provide the OSC1 pin with a 2.1 MHz signal.

``` screen
    #chip 12f1840,2.1
    #config OSC = ECM
```

<span class="strong">**Notes**</span>

When "\#config osc=" is not specified in the source code, most
microcontrollers will default to an external oscillator source. This
means at runtime the chip is expecting an external clock signal. If the
external clock signal is not present, the chip detects a "failure" of
the external clock and will "falls back" to the default internal
oscillator setting.

The PLLEN bit defaults to OFF. The PLL is enabled depending upon the
ChipMhz in \#Chip xxxxxx, ChipMhz.

The GCBASIC defaults - This is how the bits are set if there is no
\#config in the source code, GCBASIC does set certain bits. To examine
what bits are set on a particular chip you can omit \#config in the
source code, thenm compile the code and then use "Open ASM" in the
GCBASIC IDE. The bits that are set will be in the config section. All
other bits ( those not specifically set) with \#Config will be at the
POR setting as described below, The `POR` settings are shown in the
datasheet for each microcontroller.

Currently GCBASIC sets the `LVP` bit `OFF` by default on many chips.
This does not affect normal HV programming like a with a PicKit3. The
default of LVP = OFF will prevent the microcontroller from being
programmed with Low Voltage Programmer. This means that if a PIC
microcontroller has previously been programmed with with "LVP = OFF",
then it must be erased or reprogrammed with LVP = ON using a HVP
programmer prior to using certain programming devices e.g. Curiosity
development boards, or "NS" programmers as these required that LVP = ON.

When LVP = ON, the MCLR pin is automatically set to EXTERNAL MCLR. This
means that the MCLRE pin CANNOT be sue for general purpose I/O
functions.

The native `POR` (Power On Reset) defaults. This is the state of the
config bits after Power on if the ASM code has no configuration entries
or on a blank factory chip. The only way to power up in this state with
GCB code is to use " \#option NoConfig" in the GCBASIC source code.

</div>
