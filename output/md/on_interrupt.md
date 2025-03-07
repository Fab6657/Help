<div class="section">

<div class="titlepage">

<div>

<div>

#### <span id="on_interrupt"></span>On Interrupt

</div>

</div>

</div>

<span class="strong">**Syntax:**</span>

``` screen
    On Interrupt event Call handler
    On Interrupt event Ignore
```

<span class="strong">**Command Availability:**</span>

Available on Microchip PIC and Atmel AVR microcontrollers with interrupt
support.

<span class="strong">**Explanation:**</span>

On Interrupt will add code to call the subroutine <span
class="emphasis">*handler*</span> whenever the interrupt <span
class="emphasis">*event*</span> occurs. When Call is specified, GCBASIC
will enable the interrupt, and call the interrupt handler when it
occurs. When Ignore is specified, GCBASIC will disable the interrupt
handler and prevent it from being called when the event occurs. If the
event occurs while the handler is disabled, then the handler will be
called as soon as it is re-enabled. The only way to prevent this from
happening is to manually clear the flag bit for the interrupt.

There are many possible interrupt events that can occur, and the events
vary greatly from chip to chip. GCBASIC will display an error if a given
chip cannot support the specified event.

On Interrupt may require the setting or clearing of the interrupt
register bit(s), and, On Interrupt may require setting of explicit
enable register bits. You should always consult the device datasheet for
these On Interrupt additional specific settings of register bits.
Typically, you will need define the 1) source event register bit(s) in
the main program, and, 2) clear or set the register bit at the start of
the of the interrupt handler subroutine.

GCBASIC has many demonstrations showing how to set and enable appropiate
interrupt register bits to support the On Interrupt method.

If On Interrupt is used to handle an event, then the Interrupt()
subroutine will not be called for that event. However, it will still be
called for any events not dealt with by On Interrupt.

<span class="strong">**Events:**</span>

GCBASIC supports the events shown on the table below. Some events are
only implemented on a few specialised chips. Events in <span
class="gray"><span class="strong">**grey**</span></span> are supported
by Microchip PIC and Atmel AVR microcontrollers, events in <span
class="blue"><span class="strong">**blue**</span></span> are only
supported by some Microchip PIC microcontrollers, and events in <span
class="red"><span class="strong">**red**</span></span> are only
supported by Atmel AVR microcontrollers.

Note that GCBASIC doesn’t fully support all of the hardware which can
generate interrupts - some work may be required with various system
variables to control the unsupported peripherals.

<div class="informaltable">

<table data-border="1">
<thead>
<tr class="header">
<th style="text-align: left;"><span class="strong"><strong>Event Name</strong></span></th>
<th style="text-align: left;"><span class="strong"><strong>Description</strong></span></th>
<th style="text-align: left;"><span class="strong"><strong>Supported</strong></span></th>
</tr>
</thead>
<tbody>
<tr class="odd">
<td style="text-align: left;"><p><span class="gray"><span class="strong"><strong>ADCReady</strong></span></span></p></td>
<td style="text-align: left;"><p>The analog/digital converter has finished a conversion</p></td>
<td style="text-align: left;"><p>Microchip&amp;AVR</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>BatteryFail</strong></span></span></p></td>
<td style="text-align: left;"><p>The battery has failed in some way. This is only implemented on the ATmega406</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="blue"><span class="strong"><strong>CANActivity</strong></span></span></p></td>
<td style="text-align: left;"><p>CAN bus activity is taking place</p></td>
<td style="text-align: left;"><p>Microchip</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="blue"><span class="strong"><strong>CANBadMessage</strong></span></span></p></td>
<td style="text-align: left;"><p>A bad CAN message has been received</p></td>
<td style="text-align: left;"><p>Microchip</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="gray"><span class="strong"><strong>CANError</strong></span></span></p></td>
<td style="text-align: left;"><p>Some CAN error has occured</p></td>
<td style="text-align: left;"><p>Microchip&amp;AVR</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="blue"><span class="strong"><strong>CANHighWatermark</strong></span></span></p></td>
<td style="text-align: left;"><p>CAN high watermark reached</p></td>
<td style="text-align: left;"><p>Microchip</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="blue"><span class="strong"><strong>CANRx0Ready</strong></span></span></p></td>
<td style="text-align: left;"><p>New message present in buffer 0</p></td>
<td style="text-align: left;"><p>Microchip</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="blue"><span class="strong"><strong>CANRx1Ready</strong></span></span></p></td>
<td style="text-align: left;"><p>New message present in buffer 1</p></td>
<td style="text-align: left;"><p>Microchip</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="blue"><span class="strong"><strong>CANRx2Ready</strong></span></span></p></td>
<td style="text-align: left;"><p>New message present in buffer 2</p></td>
<td style="text-align: left;"><p>Microchip</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="blue"><span class="strong"><strong>CANRxReady</strong></span></span></p></td>
<td style="text-align: left;"><p>New message present</p></td>
<td style="text-align: left;"><p>Microchip</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>CANTransferComplete</strong></span></span></p></td>
<td style="text-align: left;"><p>Transfer of data has been completed</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="blue"><span class="strong"><strong>CANTx0Ready</strong></span></span></p></td>
<td style="text-align: left;"><p>Buffer 0 has been sent</p></td>
<td style="text-align: left;"><p>Microchip</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="blue"><span class="strong"><strong>CANTx1Ready</strong></span></span></p></td>
<td style="text-align: left;"><p>Buffer 1 has been sent</p></td>
<td style="text-align: left;"><p>Microchip</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="blue"><span class="strong"><strong>CANTx2Ready</strong></span></span></p></td>
<td style="text-align: left;"><p>Buffer 2 has been sent</p></td>
<td style="text-align: left;"><p>Microchip</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="blue"><span class="strong"><strong>CANTxReady</strong></span></span></p></td>
<td style="text-align: left;"><p>Sending has completed</p></td>
<td style="text-align: left;"><p>Microchip</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>CCADCAccReady</strong></span></span></p></td>
<td style="text-align: left;"><p>CC ADC accumulate conversion finished (ATmega406 only)</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>CCADCReady</strong></span></span></p></td>
<td style="text-align: left;"><p>CC ADC instantaneous conversion finished (ATmega406 only)</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>CCADCRegular</strong></span></span></p></td>
<td style="text-align: left;"><p>CC ADC regular conversion finished (ATmega406 only)</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="blue"><span class="strong"><strong>CCP1</strong></span></span></p></td>
<td style="text-align: left;"><p>The CCP1 module has captured an event</p></td>
<td style="text-align: left;"><p>Microchip</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="blue"><span class="strong"><strong>CCP2</strong></span></span></p></td>
<td style="text-align: left;"><p>The CCP2 module has captured an event</p></td>
<td style="text-align: left;"><p>Microchip</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="blue"><span class="strong"><strong>CCP3</strong></span></span></p></td>
<td style="text-align: left;"><p>The CCP3 module has captured an event</p></td>
<td style="text-align: left;"><p>Microchip</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="blue"><span class="strong"><strong>CCP4</strong></span></span></p></td>
<td style="text-align: left;"><p>The CCP4 module has captured an event</p></td>
<td style="text-align: left;"><p>Microchip</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="blue"><span class="strong"><strong>CCP5</strong></span></span></p></td>
<td style="text-align: left;"><p>The CCP5 module has captured an event</p></td>
<td style="text-align: left;"><p>Microchip</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="gray"><span class="strong"><strong>Comp0Change</strong></span></span></p></td>
<td style="text-align: left;"><p>The output of comparator 0 has changed</p></td>
<td style="text-align: left;"><p>Microchip&amp;AVR</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="gray"><span class="strong"><strong>Comp1Change</strong></span></span></p></td>
<td style="text-align: left;"><p>The output of comparator 1 has changed</p></td>
<td style="text-align: left;"><p>Microchip&amp;AVR</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="gray"><span class="strong"><strong>Comp2Change</strong></span></span></p></td>
<td style="text-align: left;"><p>The output of comparator 2 has changed</p></td>
<td style="text-align: left;"><p>Microchip&amp;AVR</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="blue"><span class="strong"><strong>Crypto</strong></span></span></p></td>
<td style="text-align: left;"><p>The KEELOQ module has generated an interrupt</p></td>
<td style="text-align: left;"><p>Microchip</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="gray"><span class="strong"><strong>EEPROMReady</strong></span></span></p></td>
<td style="text-align: left;"><p>An EEPROM write has finished</p></td>
<td style="text-align: left;"><p>Microchip&amp;AVR</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="blue"><span class="strong"><strong>Ethernet</strong></span></span></p></td>
<td style="text-align: left;"><p>The Ethernet module has generated an interrupt. This must be dealt within the handler.</p></td>
<td style="text-align: left;"><p>Microchip</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="gray"><span class="strong"><strong>ExtInt0</strong></span></span></p></td>
<td style="text-align: left;"><p>External Interrupt pin 0 has been detected</p></td>
<td style="text-align: left;"><p>Microchip&amp;AVR</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="gray"><span class="strong"><strong>ExtInt1</strong></span></span></p></td>
<td style="text-align: left;"><p>External Interrupt pin 1 has been detected</p></td>
<td style="text-align: left;"><p>Microchip&amp;AVR</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="gray"><span class="strong"><strong>ExtInt2</strong></span></span></p></td>
<td style="text-align: left;"><p>External Interrupt pin 2 has been detected</p></td>
<td style="text-align: left;"><p>Microchip&amp;AVR</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="gray"><span class="strong"><strong>ExtInt3</strong></span></span></p></td>
<td style="text-align: left;"><p>External Interrupt pin 3 has been detected</p></td>
<td style="text-align: left;"><p>Microchip&amp;AVR</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>ExtInt4</strong></span></span></p></td>
<td style="text-align: left;"><p>External Interrupt pin 4 has been detected</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>ExtInt5</strong></span></span></p></td>
<td style="text-align: left;"><p>External Interrupt pin 5 has been detected</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>ExtInt6</strong></span></span></p></td>
<td style="text-align: left;"><p>External Interrupt pin 6 has been detected</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>ExtInt7</strong></span></span></p></td>
<td style="text-align: left;"><p>External Interrupt pin 7 has been detected</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="blue"><span class="strong"><strong>GPIOChange</strong></span></span></p></td>
<td style="text-align: left;"><p>The pins on port GPIO have changed</p></td>
<td style="text-align: left;"><p>Microchip</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="gray"><span class="strong"><strong>LCDReady</strong></span></span></p></td>
<td style="text-align: left;"><p>The LCD is about to draw a segment</p></td>
<td style="text-align: left;"><p>Microchip&amp;AVR</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="blue"><span class="strong"><strong>LPWU</strong></span></span></p></td>
<td style="text-align: left;"><p>The Low Power Wake Up has been detected</p></td>
<td style="text-align: left;"><p>Microchip</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="blue"><span class="strong"><strong>OscillatorFail</strong></span></span></p></td>
<td style="text-align: left;"><p>The external oscillator has failed, and the microcontroller is running from an internal oscillator.</p></td>
<td style="text-align: left;"><p>Microchip</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>PinChange</strong></span></span></p></td>
<td style="text-align: left;"><p>Logic level of PCINT pin has changed</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>PinChange0</strong></span></span></p></td>
<td style="text-align: left;"><p>Logic level of PCINT0 pin has changed</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>PinChange1</strong></span></span></p></td>
<td style="text-align: left;"><p>Logic level of PCINT1 pin has changed</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>PinChange2</strong></span></span></p></td>
<td style="text-align: left;"><p>Logic level of PCINT2 pin has changed</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>PinChange3</strong></span></span></p></td>
<td style="text-align: left;"><p>Logic level of PCINT3 pin has changed</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>PinChange4</strong></span></span></p></td>
<td style="text-align: left;"><p>Logic level of PCINT4 pin has changed</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>PinChange5</strong></span></span></p></td>
<td style="text-align: left;"><p>Logic level of PCINT5 pin has changed</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>PinChange6</strong></span></span></p></td>
<td style="text-align: left;"><p>Logic level of PCINT6 pin has changed</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>PinChange7</strong></span></span></p></td>
<td style="text-align: left;"><p>Logic level of PCINT7 pin has changed</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="blue"><span class="strong"><strong>PMPReady</strong></span></span></p></td>
<td style="text-align: left;"><p>A Parallel Master Port read or write has finished</p></td>
<td style="text-align: left;"><p>Microchip</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="blue"><span class="strong"><strong>PORTChange</strong></span></span></p></td>
<td style="text-align: left;"><p>The pins on ports ABCEDEF have changed. This is generic port change interrupt. You must inspect the source to ensure you are handlign the correct interrupt.</p></td>
<td style="text-align: left;"><p>Microchip</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="blue"><span class="strong"><strong>PORTAChange</strong></span></span></p></td>
<td style="text-align: left;"><p>The pins on port A have changed</p></td>
<td style="text-align: left;"><p>Microchip</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="blue"><span class="strong"><strong>PORTABChange</strong></span></span></p></td>
<td style="text-align: left;"><p>The pins on port A and/or B have changed</p></td>
<td style="text-align: left;"><p>Microchip</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="gray"><span class="strong"><strong>PORTBChange</strong></span></span></p></td>
<td style="text-align: left;"><p>The pins on port B have changed</p></td>
<td style="text-align: left;"><p>Microchip&amp;AVR</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>PSC0Capture</strong></span></span></p></td>
<td style="text-align: left;"><p>The counter for Power Stage Controller 0 matches the value in a compare register, the value of the counter has been captured, or a synchronisation error has occurred</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>PSC0EndCycle</strong></span></span></p></td>
<td style="text-align: left;"><p>Power Stage Controller 0 has reached the end of its cycle</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>PSC1Capture</strong></span></span></p></td>
<td style="text-align: left;"><p>The counter for Power Stage Controller 1 matches the value in a compare register, the value of the counter has been captured, or a synchronisation error has occurred</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>PSC1EndCycle</strong></span></span></p></td>
<td style="text-align: left;"><p>Power Stage Controller 1 has reached the end of its cycle</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>PSC2Capture</strong></span></span></p></td>
<td style="text-align: left;"><p>The counter for Power Stage Controller 2 matches the value in a compare register, the value of the counter has been captured, or a synchronisation error has occurred</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>PSC2EndCycle</strong></span></span></p></td>
<td style="text-align: left;"><p>Power Stage Controller 2 has reached the end of its cycle</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="blue"><span class="strong"><strong>PSPReady</strong></span></span></p></td>
<td style="text-align: left;"><p>A Parallel Slave Port read or write has finished</p></td>
<td style="text-align: left;"><p>Microchip</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="blue"><span class="strong"><strong>PWMTimeBase</strong></span></span></p></td>
<td style="text-align: left;"><p>The PWM time base matches the PWM Time Base Period register (PTPER)</p></td>
<td style="text-align: left;"><p>Microchip</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>SPIReady</strong></span></span></p></td>
<td style="text-align: left;"><p>The SPI module has finished the previous transfer</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>SPMReady</strong></span></span></p></td>
<td style="text-align: left;"><p>A write to program memory by the spm instruction has finished</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="blue"><span class="strong"><strong>SPPReady</strong></span></span></p></td>
<td style="text-align: left;"><p>A SPP read or write has finished</p></td>
<td style="text-align: left;"><p>Microchip</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="blue"><span class="strong"><strong>SSP1Collision</strong></span></span></p></td>
<td style="text-align: left;"><p>SSP1 has detected a bus collision</p></td>
<td style="text-align: left;"><p>Microchip</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="blue"><span class="strong"><strong>SSP1Ready</strong></span></span></p></td>
<td style="text-align: left;"><p>The SSP/SSP1/MSSP1 module has finished sending or receiving</p></td>
<td style="text-align: left;"><p>Microchip</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="blue"><span class="strong"><strong>SSP2Collision</strong></span></span></p></td>
<td style="text-align: left;"><p>SSP2 has detected a bus collision</p></td>
<td style="text-align: left;"><p>Microchip</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="blue"><span class="strong"><strong>SSP2Ready</strong></span></span></p></td>
<td style="text-align: left;"><p>The SSP2/MSSP2 module has finished sending or receiving</p></td>
<td style="text-align: left;"><p>Microchip</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>Timer0Capture</strong></span></span></p></td>
<td style="text-align: left;"><p>An input event on the pin ICP0 has caused the value of Timer 0 to be captured in the ICR0 register</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>Timer0Match1</strong></span></span></p></td>
<td style="text-align: left;"><p>Timer 0 matches the Timer 0 output compare register A (OCR0A)</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>Timer0Match2</strong></span></span></p></td>
<td style="text-align: left;"><p>Timer 0 matches the Timer 0 output compare register B (OCR0B)</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="gray"><span class="strong"><strong>Timer0Overflow</strong></span></span></p></td>
<td style="text-align: left;"><p>Timer 0 has overflowed</p></td>
<td style="text-align: left;"><p>Microchip&amp;AVR</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>Timer1Capture</strong></span></span></p></td>
<td style="text-align: left;"><p>An input event on the pin ICP1 has caused the value of Timer 1 to be captured in the ICR1 register</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>Timer1Error</strong></span></span></p></td>
<td style="text-align: left;"><p>The Timer 1 Fault Protection unit has been detected by an input on the INT0 pin</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>Timer1Match1</strong></span></span></p></td>
<td style="text-align: left;"><p>Timer 1 matches the Timer 1 output compare register A (OCR1A)<br />
Within the Interrupt handling sub routine ensure the timer reset and cleartimer is set appropriately.</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>Timer1Match2</strong></span></span></p></td>
<td style="text-align: left;"><p>Timer 1 matches the Timer 1 output compare register B (OCR1B)<br />
Within the Interrupt handling sub routine ensure the timer reset and cleartimer is set appropriately.</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>Timer1Match3</strong></span></span></p></td>
<td style="text-align: left;"><p>Timer 1 matches the Timer 1 output compare register C (OCR1C)<br />
Within the Interrupt handling sub routine ensure the timer reset and cleartimer is set appropriately.</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>Timer1Match4</strong></span></span></p></td>
<td style="text-align: left;"><p>Timer 1 matches the Timer 1 output compare register D (OCR1D)<br />
Within the Interrupt handling sub routine ensure the timer reset and cleartimer is set appropriately.</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="gray"><span class="strong"><strong>Timer1Overflow</strong></span></span></p></td>
<td style="text-align: left;"><p>Timer 1 has overflowed</p></td>
<td style="text-align: left;"><p>Microchip&amp;AVR</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="blue"><span class="strong"><strong>Timer2Match</strong></span></span></p></td>
<td style="text-align: left;"><p>Timer 2 matches the Timer 2 output compare register (PR2)<br />
Within the Interrupt handling sub routine ensure the timer reset and cleartimer is set appropriately.</p></td>
<td style="text-align: left;"><p>Microchip</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>Timer2Match1</strong></span></span></p></td>
<td style="text-align: left;"><p>Timer 2 matches the Timer 2 output compare register A (OCR2A)<br />
Within the Interrupt handling sub routine ensure the timer reset and cleartimer is set appropriately.</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>Timer2Match2</strong></span></span></p></td>
<td style="text-align: left;"><p>Timer 2 matches the Timer 2 output compare register B (OCR2B)<br />
Within the Interrupt handling sub routine ensure the timer reset and cleartimer is set appropriately.</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>Timer2Overflow</strong></span></span></p></td>
<td style="text-align: left;"><p>Timer 2 has overflowed</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>Timer3Capture</strong></span></span></p></td>
<td style="text-align: left;"><p>An input event on the pin ICP3 has caused the value of Timer 3 to be captured in the ICR3 register</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>Timer3Match1</strong></span></span></p></td>
<td style="text-align: left;"><p>Timer 3 matches the Timer 3 output compare register A (OCR3A)<br />
Within the Interrupt handling sub routine ensure the timer reset and cleartimer is set appropriately.</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>Timer3Match2</strong></span></span></p></td>
<td style="text-align: left;"><p>Timer 3 matches the Timer 3 output compare register B (OCR3B)<br />
Within the Interrupt handling sub routine ensure the timer reset and cleartimer is set appropriately.</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>Timer3Match3</strong></span></span></p></td>
<td style="text-align: left;"><p>Timer 3 matches the Timer 3 output compare register C (OCR3C)<br />
Within the Interrupt handling sub routine ensure the timer reset and cleartimer is set appropriately.</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="gray"><span class="strong"><strong>Timer3Overflow</strong></span></span></p></td>
<td style="text-align: left;"><p>Timer 3 has overflowed</p></td>
<td style="text-align: left;"><p>Microchip&amp;AVR</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>Timer4Capture</strong></span></span></p></td>
<td style="text-align: left;"><p>An input event on the pin ICP4 has caused the value of Timer 4 to be captured in the ICR4 register</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="blue"><span class="strong"><strong>Timer4Match</strong></span></span></p></td>
<td style="text-align: left;"><p>Timer 4 matches the Timer 4 output compare register (PR4)<br />
Within the Interrupt handling sub routine ensure the timer reset and cleartimer is set appropriately.</p></td>
<td style="text-align: left;"><p>Microchip</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>Timer4Match1</strong></span></span></p></td>
<td style="text-align: left;"><p>Timer 4 matches the Timer 4 output compare register A (OCR4A)<br />
Within the Interrupt handling sub routine ensure the timer reset and cleartimer is set appropriately.</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>Timer4Match2</strong></span></span></p></td>
<td style="text-align: left;"><p>Timer 4 matches the Timer 4 output compare register B (OCR4B)<br />
Within the Interrupt handling sub routine ensure the timer reset and cleartimer is set appropriately.</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>Timer4Match3</strong></span></span></p></td>
<td style="text-align: left;"><p>Timer 4 matches the Timer 4 output compare register C (OCR4C)<br />
Within the Interrupt handling sub routine ensure the timer reset and cleartimer is set appropriately.</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>Timer4Overflow</strong></span></span></p></td>
<td style="text-align: left;"><p>Timer 4 has overflowed</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="blue"><span class="strong"><strong>Timer5CAP1</strong></span></span></p></td>
<td style="text-align: left;"><p>An input on the CAP1 pin has caused the value of Timer 5 to be captured in CAP1BUF</p></td>
<td style="text-align: left;"><p>Microchip</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="blue"><span class="strong"><strong>Timer5CAP2</strong></span></span></p></td>
<td style="text-align: left;"><p>An input on the CAP2 pin has caused the value of Timer 5 to be captured in CAP2BUF</p></td>
<td style="text-align: left;"><p>Microchip</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="blue"><span class="strong"><strong>Timer5CAP3</strong></span></span></p></td>
<td style="text-align: left;"><p>An input on the CAP3 pin has caused the value of Timer 5 to be captured in CAP3BUF</p></td>
<td style="text-align: left;"><p>Microchip</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>Timer5Capture</strong></span></span></p></td>
<td style="text-align: left;"><p>An input event on the pin ICP5 has caused the value of Timer 5 to be captured in the ICR5 register</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>Timer5Match1</strong></span></span></p></td>
<td style="text-align: left;"><p>Timer 5 matches the Timer 5 output compare register A (OCR5A)<br />
Within the Interrupt handling sub routine ensure the timer reset and cleartimer is set appropriately.</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>Timer5Match2</strong></span></span></p></td>
<td style="text-align: left;"><p>Timer 5 matches the Timer 5 output compare register B (OCR5B)<br />
Within the Interrupt handling sub routine ensure the timer reset and cleartimer is set appropriately.</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>Timer5Match3</strong></span></span></p></td>
<td style="text-align: left;"><p>Timer 5 matches the Timer 5 output compare register C (OCR5C)<br />
Within the Interrupt handling sub routine ensure the timer reset and cleartimer is set appropriately.</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="gray"><span class="strong"><strong>Timer5Overflow</strong></span></span></p></td>
<td style="text-align: left;"><p>Timer 5 has overflowed</p></td>
<td style="text-align: left;"><p>Microchip&amp;AVR</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="blue"><span class="strong"><strong>Timer6Match</strong></span></span></p></td>
<td style="text-align: left;"><p>Timer 6 matches the Timer 6 output compare register (PR6)</p></td>
<td style="text-align: left;"><p>Microchip</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="blue"><span class="strong"><strong>Timer7Overflow</strong></span></span></p></td>
<td style="text-align: left;"><p>Timer 7 has overflowed</p></td>
<td style="text-align: left;"><p>Microchip</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="blue"><span class="strong"><strong>Timer8Match</strong></span></span></p></td>
<td style="text-align: left;"><p>Timer 8 matches the Timer 8 output compare register (PR8)</p></td>
<td style="text-align: left;"><p>Microchip</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="blue"><span class="strong"><strong>Timer10Match</strong></span></span></p></td>
<td style="text-align: left;"><p>Timer 10 matches the Timer 10 output compare register (PR10)</p></td>
<td style="text-align: left;"><p>Microchip</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="blue"><span class="strong"><strong>Timer12Match</strong></span></span></p></td>
<td style="text-align: left;"><p>Timer 12 matches the Timer 12 output compare register (PR12)</p></td>
<td style="text-align: left;"><p>Microchip</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="gray"><span class="strong"><strong>TWIConnect</strong></span></span></p></td>
<td style="text-align: left;"><p>The Atmel AVR has been connected to or disconnected from the TWI (I2C) bus</p></td>
<td style="text-align: left;"><p>Microchip&amp;AVR</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="gray"><span class="strong"><strong>TWIReady</strong></span></span></p></td>
<td style="text-align: left;"><p>The TWI has finished the previous transmission and is ready to send or receive more data</p></td>
<td style="text-align: left;"><p>Microchip&amp;AVR</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="gray"><span class="strong"><strong>UsartRX1Ready</strong></span></span></p></td>
<td style="text-align: left;"><p>UART/USART 1 has received data</p></td>
<td style="text-align: left;"><p>Microchip&amp;AVR</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="gray"><span class="strong"><strong>UsartRX2Ready</strong></span></span></p></td>
<td style="text-align: left;"><p>UART/USART 2 has received data</p></td>
<td style="text-align: left;"><p>Microchip&amp;AVR</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>UsartRX3Ready</strong></span></span></p></td>
<td style="text-align: left;"><p>UART/USART 3 has received data</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>UsartRX4Ready</strong></span></span></p></td>
<td style="text-align: left;"><p>UART/USART 4 has received data</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="gray"><span class="strong"><strong>UsartTX1Ready</strong></span></span></p></td>
<td style="text-align: left;"><p>UART/USART 1 is ready to send data</p></td>
<td style="text-align: left;"><p>Microchip&amp;AVR</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>UsartTX1Sent</strong></span></span></p></td>
<td style="text-align: left;"><p>UART/USART 1 has finished sending data</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="gray"><span class="strong"><strong>UsartTX2Ready</strong></span></span></p></td>
<td style="text-align: left;"><p>UART/USART 2 is ready to send data</p></td>
<td style="text-align: left;"><p>Microchip&amp;AVR</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>UsartTX2Sent</strong></span></span></p></td>
<td style="text-align: left;"><p>UART/USART 2 has finished sending data</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>UsartTX3Ready</strong></span></span></p></td>
<td style="text-align: left;"><p>UART/USART 3 is ready to send data</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>UsartTX3Sent</strong></span></span></p></td>
<td style="text-align: left;"><p>UART/USART 3 has finished sending data</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>UsartTX4Ready</strong></span></span></p></td>
<td style="text-align: left;"><p>UART/USART 4 is ready to send data</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>UsartTX4Sent</strong></span></span></p></td>
<td style="text-align: left;"><p>UART/USART 4 has finished sending data</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>USBEndpoint</strong></span></span></p></td>
<td style="text-align: left;"><p>A USB endpoint has generated an interrupt</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="gray"><span class="strong"><strong>USB</strong></span></span></p></td>
<td style="text-align: left;"><p>The USB module has generated an interrupt. This must be dealt with in the handler.</p></td>
<td style="text-align: left;"><p>Microchip&amp;AVR</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>USIOverflow</strong></span></span></p></td>
<td style="text-align: left;"><p>The USI counter has overflowed from 15 to 0</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>USIStart</strong></span></span></p></td>
<td style="text-align: left;"><p>The USI module has detected a start condition</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="blue"><span class="strong"><strong>VoltageFail</strong></span></span></p></td>
<td style="text-align: left;"><p>The input voltage has dropped too low</p></td>
<td style="text-align: left;"><p>Microchip</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>VoltageRegulator</strong></span></span></p></td>
<td style="text-align: left;"><p>An interrupt has been generated by the voltage regulator (ATmega16HVA only)</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="even">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>WakeUp</strong></span></span></p></td>
<td style="text-align: left;"><p>The Wake-Up timer has overflowed</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
<tr class="odd">
<td style="text-align: left;"><p><span class="red"><span class="strong"><strong>WDT</strong></span></span></p></td>
<td style="text-align: left;"><p>An interrupt has been generated by the Watchdog Timer</p></td>
<td style="text-align: left;"><p>AVR</p></td>
</tr>
</tbody>
</table>

</div>

  
  
<span class="strong">**Example 1:**</span>

``` screen
    'This program increments a counter every time Timer1 overflows
    #chip 16F877A, 20

    'LCD connection settings
    #define LCD_IO 4
    #define LCD_WIDTH 20                ;specified lcd width for clarity only.  20 is the default width
    #define LCD_DB4 PORTD.4
    #define LCD_DB5 PORTD.5
    #define LCD_DB6 PORTD.6
    #define LCD_DB7 PORTD.7
    #define LCD_RS PORTD.0
    #define LCD_RW PORTD.1
    #define LCD_Enable PORTD.2

    InitTimer1 Osc, PS1_1/8
    StartTimer 1
    CounterValue = 0

    Wait 100 ms
    Print "Int Test"

    On Interrupt Timer1Overflow Call IncCounter

    Do
        CLS
        Print CounterValue
        Wait 100 ms
    Loop

    Sub IncCounter
        CounterValue ++
    End Sub
```

  
  
<span class="strong">**Example 2:**</span>

``` screen
    'This example reflects the input signal on the output port.
    #chip mega328p, 16
    #option explicit

    'set out SOURCE interrupt port as an output
    dir portb.0 in

    'set/enable the mask for the specific input port
    'this is crutial - for a lot of the On Interrupt methods you will need to specify the interrupt source via a mask.bit.
    PCINT0 = 1

    'set out signal port as an output
    dir portB.5 out

    'setup the On Interrupt method
    On Interrupt PinChange0 Call TogglePin

    'maintain a loop
    do

    loop

    'handle the output signal
    'Note. The AVR automatically clears the Interrupt. Please study the datasheet for each specific microcontroller

    sub togglePin
        portb.5 =  !pinb.5
    end sub
```

  
  
<span class="strong">**Example 3:**</span>

``` screen
    'This example reflects the input signal on the output port from the external interrupt port.
    #Chip mega328p, 16
    #option explicit

    'Set external interrupt INTO input pin as an input
    dir portd.2 in

    'set out signal port as an output
    dir portB.5 out

    'hardware interrupt on Port D2
    INT0 = 1

    'set interrupt to a failing or rising edge
    'interrupt on falling edge
    EICRA = b'00000010'
        'or, alternatively you can set to a rising edge
    'EICRA = b'00000011'

    'set out signal port as an output
    dir portB.5 out

    'setup the On Interrupt method on external interrupt 0
    On Interrupt EXTINT0 Call togglePin

    'maintain a loop
    do

    loop

    'handle the output signal
    'Note. The AVR automatically clears the Interrupt. Please study the datasheet for each specific microcontroller

    sub togglePin
        portb.5 =  !pinb.5
    end sub
```

<span class="strong">**For more help, see**</span>
<a href="inittimer0" class="link" title="InitTimer0">InitTimer0</a>
article contains an example of using Timer 0 and On Interrupt to
generate a Pulse Width Modulation signal to control a motor.

<span class="strong">**See also**</span>
<a href="intoff" class="link" title="IntOff">IntOff</a>,
<a href="inton" class="link" title="IntOn">IntOn</a>

</div>
