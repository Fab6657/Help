<div class="section">

<div class="titlepage">

<div>

<div>

#### <span id="leftpad"></span>LeftPad

</div>

</div>

</div>

<span class="strong">**Syntax:**</span>

``` screen
    LeftPad(string_variable,byte_value_of_the_new_length,pad_character)
```

<span class="strong">**Command Availability:**</span>

Available on all microcontrollers

<span class="strong">**Explanation:**</span>

The LeftPad function is used to create string to a specific length that
is extended with a specific character to the left hand side of the
string.

The length of the string is specified by the second parameter.

The character used to pad the string is specified by the third
parameter.

A typical use is to pad a string to be displayed on a serial terminal or
LCD.

<span class="strong">**Example:**</span>

``` screen
    'Set chip model
 'Set chip model
    #chip 16f877a


    DIR PORTA 0x03


    ' make port C as output
    Dir PortC 0x0


    'Defines (Constants)
    #define LCD_SPEED slow
    #define LCD_IO 4
    #define LCD_WIDTH 20                ;specified lcd width for clarity only.  20 is the default width
    #define LCD_NO_RW
    #define LCD_Enable PORTc.0
    #define LCD_RS PORTc.1
    #define LCD_DB4 PORTa.5
    #define LCD_DB5 PORTa.4
    #define LCD_DB6 PORTa.3
    #define LCD_DB7 PORTa.2
    '''--------------------------------------------
    '''-------End of board-specific settings-------
    '''--------------------------------------------


    '''DEMO for padding strings left with
    '''1st character of a given string.
    '''if no string is given, blanks are used


    ; ---- variables
    DIM inString as string * 5
    DIM outString1 as String
    DIM outString2 as String

    ; ---- main body of program begins here

    inString = "12345"

    outString1 = leftpad(inString, 9, "*")
    outString2 = leftpad(inString, 9)

    'show results on LCD-Display
    cls

    print instring
    print " "
    print outstring1
    locate 1,0
    print instring
    print " "
    print outstring2

    end
```

</div>
