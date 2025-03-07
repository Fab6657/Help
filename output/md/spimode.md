<div class="section">

<div class="titlepage">

<div>

<div>

#### <span id="spimode"></span>SPIMode

</div>

</div>

</div>

<span class="strong">**Syntax:**</span>

``` screen
    SPIMode ( Mode [, SPIClockMode])
```

<span class="strong">**Command Availability:**</span>

Available on Microchip PIC microcontrollers with Hardware SPI modules.

<span class="strong">**Explanation:**</span>

<span class="emphasis">*Mode*</span> sets the mode of the SPI module
within the microcontroller. These are the possible SPI Modes:

<div class="informaltable">

| <span class="strong">**Mode Name**</span> | <span class="strong">**Description**</span>                             |
|:------------------------------------------|:------------------------------------------------------------------------|
| `MasterSlow`                              | Master mode, SPI clock is 1/64 of the frequency of the microcontroller. |
| `Master`                                  | Master mode, SPI clock is 1/16 of the frequency of the microcontroller. |
| `MasterFast`                              | Master mode, SPI clock is 1/4 of the frequency of the microcontroller.  |
| `Slave`                                   | Slave mode                                                              |
| `SlaveSS`                                 | Slave mode, with the Slave Select pin enabled.                          |

</div>

<span class="emphasis">*SPIClockMode*</span> is an optional parameter to
set the mode of the SPI clock mode. This optional parameter sets both
the clock polarity and clock edge.

<div class="informaltable">

| <span class="strong">**SPIClockMode**</span> | <span class="strong">**Description**</span> |
|:---------------------------------------------|:--------------------------------------------|
| 0                                            | SPI\_CPOL = 0 & SPI\_CPHA = 0               |
| 1                                            | SPI\_CPOL = 0 & SPI\_CPHA = 1               |
| 2                                            | SPI\_CPOL = 1 & SPI\_CPHA = 0               |
| 3                                            | SPI\_CPOL = 1 & SPI\_CPHA = 1               |

</div>

You can alternatively use constants to set the SPIClockMode as follows:

``` screen
    SPIMode ( MasterFast, SPI_CPOL_n + SPI_CPHA_n )
```

Where the following parameters can be used as a calculation to set the
SPIClockMode.

<div class="informaltable">

| <span class="strong">**Mode Name**</span> | <span class="strong">**Description**</span> |
|:------------------------------------------|:--------------------------------------------|
| SPI\_CPOL\_0                              | CPOL = 0                                    |
| SPI\_CPOL\_1                              | CPOL = 1                                    |
| SPI\_CPHA\_0                              | CPHA = 0                                    |
| SPI\_CPHA\_1                              | CPHA = 1                                    |

</div>

<span class="strong">**Summary:**</span>

When using SPI setting the clock frequency is completed using SPIMode,
and the master must also configure the clock polarity and phase with
respect to the data. Using the two options as CPOL and CPHA.

The timing diagram is shown below. The timing is further described and
applies to both the master and the slave device.

When CPOL=0 the base value of the clock is zero, i.e. the active state
is 1 and idle state is 0.

<div class="itemizedlist">

-   For CPHA=0, data are captured on the clock’s rising edge (low→high
    transition) and data is output on a falling edge (high→low clock
    transition).
-   For CPHA=1, data are captured on the clock’s falling edge and data
    is output on a rising edge.

</div>

When CPOL=1 the base value of the clock is one (inversion of CPOL=0),
i.e. the active state is 0 and idle state is 1.

<div class="itemizedlist">

-   For CPHA=0, data are captured on clock’s falling edge and data is
    output on a rising edge.
-   For CPHA=1, data are captured on clock’s rising edge and data is
    output on a falling edge.

</div>

When CPHA=0 means sampling on the first clock edge and , while CPHA=1
means sampling on the second clock edge, regardless of whether that
clock edge is rising or falling. Note that with CPHA=0, the data must be
stable for a half cycle before the first clock cycle.

In other words, CPHA=0 means transmitting data on the active to idle
state and CPHA=1 means that data is transmitted on the idle to active
state edge. Note that if transmission happens on a particular edge, then
capturing will happen on the opposite edge(i.e. if transmission happens
on falling, then reception happens on rising and vice versa). The MOSI
and MISO signals are usually stable (at their reception points) for the
half cycle until the next clock transition. SPI master and slave devices
may well sample data at different points in that half cycle.

This adds more flexibility to the communication channel between the
master and slave.

<div class="informalfigure">

<div class="mediaobject" align="center">

![\[graphic](./images/spimode1.PNG)

</div>

</div>

<span class="strong">**Example**</span>

This example demonstrates the SPI capabilities for the mega328p. The
process is similar of any microcontroller..

You must set the data line as inputs and outputs.

``` screen
        #chip mega328p, 16
        #option explicit
        #include <UNO_mega328p.h >

        #define SPI_HardwareSPI  'comment this out to make into Software SPI but, you may have to change clock lines

        'Pin mappings for SPI - this SPI driver supports Hardware SPI
        #define SPI_DC       DIGITAL_8          ' Data command line
        #define SPI_CS       DIGITAL_4          ' Chip select line
        #define SPI_RESET    DIGITAL_9          ' Reset line

        #define SPI_DI       DIGITAL_12          ' Data in | MISO
        #define SPI_DO       DIGITAL_11          ' Data out | MOSI
        #define SPI_SCK      DIGITAL_13          ' Clock Line

        dir SPI_DC    out
        dir SPI_CS    out
        dir SPI_RESET out
        dir SPI_DO    Out
        dir SPI_DI    In
        dir SPI_SCK   Out

        'If DIGITAL_10 is NOT used as the SPI_CS (sometimes called SS) the port must and output or set as input/pulled high with a 10k resistor.
        'As follows:
        'If CS is configured as an input, it must be held high to ensure Master SPI operation.
        'If the CS pin is driven low by peripheral circuitry when the SPI is configured as a Master with the SS pin defined as an input, the
        'SPI system interprets this as another master selecting the SPI as a slave and starting to send data to it!
        'If CS is an output SPI communications will commence with no flow control.
        dir DIGITAL_10 Out


        dim outbyte, inbyte as byte

        SPIMode ( MasterFast, SPI_CPOL_0 + SPI_CPHA_0 )


       do
        set SPI_CS OFF;  Select line
        set SPI_DC OFF;  Send Data if off, or, Data if On
        SPITransfer ( outbyte, inbyte )
        set SPI_CS ON;   Deselect Line
        set SPI_DC ON
        wait 10 ms
       loop
```

<span class="strong">**See also**</span>
<a href="spitransfer" class="link" title="SPITransfer">SPITransfer</a>,<a href="fasthwspitransfer" class="link" title="FastHWSPITransfer">FastHWSPITransfer</a>

</div>
