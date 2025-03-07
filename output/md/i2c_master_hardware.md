<div class="section">

<div class="titlepage">

<div>

<div>

### <span id="i2c_master_hardware"></span>I2C Master Hardware

</div>

</div>

</div>

<span class="strong">**Explanation:**</span>

This program demonstrates how to read and write data from an EEPROM
device using the serial protocal called I2C.  

This program uses the hardware I2C module within the microcontroller. If
your microcontroller does not have a hardware I2C module then please use
the software I2C GCBASIC ibrary.

This program has three sections.

<div class="orderedlist">

1.  Read a single byte from the EEPROM
2.  Write and read a page of 64 bytes to and from the EEPROM, and
3.  Finally display the contents of the EEPROM.

</div>

This program has an interrupt driven serial handler to capture and
manage input from a serial terminal.

<span class="strong">**Demonstration program:**</span>

``` screen
    'Change the microcontroller, frequency and config to suit your needs.
    #chip 16F1937, 32
    #config MCLRE_ON

    'Required Library to read and write to an EEPROM
    #include <I2CEEPROM.h>

    ' Define I2C settings - CHANGE PORTS
    #define HI2C_BAUD_RATE 400
    #define HI2C_DATA PORTC.4
    #define HI2C_CLOCK PORTC.3
    'I2C pins need to be input for SSP module for Microchip PIC devices.
    Dir HI2C_DATA in
    Dir HI2C_CLOCK in
    'I2C MASTER MODE
    HI2CMode Master

    ' THIS CONFIG OF THE SERIAL PORT WORKS WITH max232 THEN TO PC
    ' USART settings
    #define USART_BAUD_RATE 9600
    Dir PORTc.6 Out
    Dir PORTc.7 In
    #define USART_DELAY OFF
    #define USART_TX_BLOCKING
    wait 500 ms

    'Create a Serial Interrupt Handler
    On Interrupt UsartRX1Ready Call readUSART

    ' Constants etc required for the serial Buffer Ring
    #define BUFFER_SIZE 32
    #define bkbhit (next_in <> next_out)
    ' Required Variables for the serial Buffer Ring
    Dim buffer(BUFFER_SIZE)
    Dim next_in as byte: next_in = 1
    Dim next_out as byte: next_out = 1


    Dim syncbyte as Byte
    wait 125 ms

    ' Read ONE byte from the EEPROM
    dim DeviceID as byte
    dim EepromAddress, syscounter as word
    #define EEpromDevice 0xA0

    'Master Main Loop
    location = 0
    'Define our array
    dim outarray(64), inarray(64)

    do
        HSerPrintCRLF 2
        HSerPrint "Commence Array Write and Read"
        'Populate the array
        for tt = 1 to 64
            outarray(tt) = tt
        next

        'Library write call is: eeprom_wr_array(device_number, page_size, address, array_name, number_of_bytes)
        eeprom_wr_array(EEpromDevice, 64, location, outarray, 64)


        'Library read call is: eeprom_rd_array(device_number, address, array_name, number_of_bytes)
        eeprom_rd_array(EEpromDevice, location, inarray, 64)

        'Show results of the read of the I2C EEPROM
        HSerPrintCRLF 2
        for tt = 1 to 64

            if outarray(tt) <> inarray(tt) then
               Hserprint "!"
               HSerPrint inarray(tt)
            else
               HSerPrint inarray(tt)
            end if
            HSerPrint ","
        next

        HSerPrintCRLF 2
        HSerPrint "Commence Write and Read a single byte":HSerPrintCRLF
        HSerPrint "Read value should be "
        HSerPrint  str(location):HSerPrintCRLF
        HSerPrint "Read = "
        'Use library to write and read from the I2C EEPROM
        eeprom_wr_byte (EEpromDevice, location, location)
        eeprom_rd_byte (EEpromDevice, location, bbyte )

        HSerPrint bbyte
        location++
        HSerPrintCRLF 2

        'Show the connnected I2C devices on the Serial terminal.
        HI2CDeviceSearch
        HSerPrint "Commence Dump of the EEPROM"
        validateEEPROM
    Loop
    End


    'Show the attached I2C devices
    sub HI2CDeviceSearch
        'Assumes serial is operational
        HSerPrintCRLF
        HSerPrint "I2C Device Search"
        HSerPrintCRLF 2
        for deviceID = 0 to 255
        HI2CStart
        HI2CSend ( deviceID )
        if HI2CAckPollState = false then
            HSerPrint   "ID: 0x"
            HSerPrint   hex(deviceID)
            HSerSend 9
            testid = deviceID | 1
            select case testid
                 case 49
                      Hserprint "DS2482_1Channel_1Wire Master"
                 case 65
                      Hserprint "Serial_Expander_Device"
                 Case 73
                       Hserprint "Serial_Expander_Device"
                 case 161
                      Hserprint "EEProm_Device_Device"
                 case 163
                      Hserprint "EEProm_Device_Device"
                 case 165
                      Hserprint "EEProm_Device_Device"
                 case 167
                      Hserprint "EEProm_Device_Device"
                 case 169
                      Hserprint "EEProm_Device_Device"
                 case 171
                      Hserprint "EEProm_Device_Device"
                 case 173
                      Hserprint "EEProm_Device_Device"
                 case 175
                      Hserprint "EEProm_Device_Device"
                 case 209
                      Hserprint "DS1307_RTC_Device"
                 case 249
                      Hserprint "FRAM_Device"
                 case else
                      Hserprint "Unknown_Device"
            end select
            HI2CSend ( 0 )
            HSerPrintCRLF
        end if
        HI2CStop
        next
        HSerPrint   "End of Device Search"
        HSerPrintCRLF 2
    end sub

    'Validation EEPROOM code
    sub validateEEPROM
        EepromAddress = 0
        HSerPrintCRLF 2
        HSerPrint "Hx"
        HSerPrint hex(EepromAddress_h)
        HSerPrint hex(EepromAddress)
        HSerPrint " "

        for EepromAddress = 0 to 0xffff
            'Read from EEPROM using a library function
            eeprom_rd_byte EEPromDevice, EepromAddress, objType

            HSerPrint hex(objType)+" "
            if ((EepromAddress+1) % 8 ) = 0 then
                HSerPrintCRLF
                HSerPrint "Hx"
                syscounter = EepromAddress + 1
                HSerPrint hex(syscounter_h)
                HSerPrint hex(syscounter)
                HSerPrint " "
            end if
            'Has serial data been received
            if bkbhit then
                syschar = bgetc
                select case syschar
                    case 32
                        do while bgetc = 32
                        loop
                    case else
                        HSerPrintCRLF
                        HSerPrint "Done"
                        exit sub
                end select
            end if
        next
        HSerPrintCRLF
        HSerPrint "Done"
    end Sub


    ' Start of Serial Support functions
    ' Required to read the serial port
    ' Assumes serial port has been initialised
    Sub readUSART
        buffer(next_in) = HSerReceive
        temppnt = next_in
        next_in = ( next_in + 1 ) % BUFFER_SIZE
        if ( next_in = next_out ) then  ' buffer is full!!
            next_in = temppnt
        end if
    End Sub

    ' Serial Support functions
    ' Get characters from the serial port
    function bgetc
        wait while !(bkbhit)
        bgetc = buffer(next_out)
        next_out=(next_out+1) % BUFFER_SIZE
    end Function
```

</div>
