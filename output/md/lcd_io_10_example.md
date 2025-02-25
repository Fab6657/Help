<div class="section">

<div class="titlepage">

<div>

<div>

##### <span id="lcd_io_10_example"></span>LCD\_IO 10 Example

</div>

</div>

</div>

This is an connection mode 10 I2C Driver to demonstrate LCD features.
This for the 16F877A, but, it can easily be adapted for other
microcontrollers.

A 2 by 16 LCD is assumed with the LCD being driven using an LCD I2C
adapter. Two types are supported the YwRobot LCD1602 IIC V1 / a
Sainsmart LCD\_PIC I2C adapter or the Ywmjkdz I2C adapter with pot bent
over top of chip.

The demonstrates reading a DS18B20 and showing the results on the LCD.

<span class="strong">**Example:**</span>

``` screen
    #chip mega328p, 16
    #include <DS18B20.h>

    ; ----- Define Hardware settings
    ' Define I2C settings - CHANGE PORTS
     #define I2C_MODE Master
     #define I2C_DATA PORTC.4
     #define I2C_CLOCK PORTC.5
     #define I2C_DISABLE_INTERRUPTS ON

    '''Set up LCD
     #define LCD_IO 10
     #define LCD_I2C_Address_1 0x4E                ; LCD 1
     #define LCD_I2C_Address_2 0x4C                ; LCD 2

    ; ----- Constants
    ' DS18B20 port settings - this is required
       #define DQ PortC.3

    ; ----- Quick Command Reference:

    '''Set LCD_10 to 10 for the YwRobot LCD1602 IIC V1 or the Sainsmart LCD_PIC I2C adapter
    '''Set LCD_10 to 12 for the Ywmjkdz I2C adapter with pot bent over top of chip

    ; ----- Variables
    dim TempC_100 as word   ' a variabler to handle the temperature calculations
    dim DSdataRaw as Integer


    ; ----- Main body of program commences here.

    'Change to the correct LCD by setting     LCD_I2C_Address_Current to the correct address then write to LCD.
    LCD_I2C_Address_Current = LCD_I2C_Address_1: DisplayInformation ( 1 )
    LCD_I2C_Address_Current = LCD_I2C_Address_2: DisplayInformation ( 1 )
    wait 4 s
    LCD_I2C_Address_Current = LCD_I2C_Address_1:  CLS
    LCD_I2C_Address_Current = LCD_I2C_Address_2:  CLS

    ccount = 0
    Do forever

        ' The function readtemp12 returns the raw value of the sensor.
        ' The sensor is read as a 12 bit value therefore each unit equates to 0.0625 of a degree
        DSdataRaw = readtemp12    ; save to this variable to prevent the delay bewtween screen up dates
        ' The function readtemp returns the integer value of the sensor
        DSdata = readtemp

        LCD_I2C_Address_Current = LCD_I2C_Address_1: DisplayInformation ( 2 )  ; update LCD1
        LCD_I2C_Address_Current = LCD_I2C_Address_2: DisplayInformation ( 2 )  ; update LCD2
        DSdata = DSdataRaw ; Set the data
        LCD_I2C_Address_Current = LCD_I2C_Address_1: DisplayInformation ( 3 )  ; update LCD1
        DSdata= DSdataRaw ; Set the data
        LCD_I2C_Address_Current = LCD_I2C_Address_2: DisplayInformation ( 3 )  ; update LCD2

        ccount++

        wait 1 s

    loop
    End

    Sub DisplayInformation ( LCDCommand )

        Select case LCDCommand

        Case 1
          CLS
          print "GCBASIC 2021"
          locate 1,0
          print "DS18B20 Demo"

        Case 2
           ' Display the integer value of the sensor on the LCD
           locate 0,0
           print hex(ccount)
           print " Ceil"
           locate 0,8
           print DSdata
           print chr(223)+"C"+"  "

         Case 3

           ' Display the integer and decimal value of the sensor on the LCD

           SignBit = DSdata / 256 / 128
           If SignBit = 0 Then goto Positive
           ' its negative!
           DSdata = ( DSdata # 0xffff ) + 1 ' take twos comp

        Positive:

           ' Convert value * 0.0625. Mulitple value by 6 then add result to multiplication of the value with 25 then divide result by 100.
           TempC_100 =  DSdata * 6
           DSdata = ( DSdata * 25 ) / 100
           TempC_100 = TempC_100 + DSdata

           Whole = TempC_100 / 100
           Fract = TempC_100 % 100
           If SignBit = 0 Then goto DisplayTemp
           Print "-"

        DisplayTemp:
           locate 1,0
           print hex(ccount)
           print " Real"
           locate 1,8
           print str(Whole)
           print "."
          ' To ensure the decimal part is two digits
           Dig = Fract / 10
           print Dig
           Dig = Fract % 10
           print Dig
           print chr(223)
           print "C"+"  "

        End Select

    end sub
```

</div>
