<div class="section">

<div class="titlepage">

<div>

<div>

#### <span id="lcdcreatechar"></span>LCDCreateChar

</div>

</div>

</div>

<span class="strong">**Syntax:**</span>

``` screen
    LCDCreateChar char, chardata()
```

<span class="strong">**Command Availability:**</span>

Available on all microcontrollers.

<span class="strong">**Explanation:**</span>

The LCDCreateChar command is used to send a custom character to the LCD.

Each character on the LCD is made up from an 8 row by 5 column (5x8)
matrix of pixels. The data to be sent to the LCD is composed of an 8
element array, where each element corresponds to a row. Inside each
element, the 5 lowest bits make up the data for the corresponding row.
When a bit is set a dot will be drawn at the matching location; when it
is cleared, no dot will appear.

An array of more than 8 elements may be used, but only the first 8 will
be read.

`char` is the ASCII value of the character to create. ASCII codes 0
through 7 are usually used to store custom characters.  
`chardata()` is an array containing the data for the character.

<span class="strong">**Example:**</span>

``` screen
    'This program draws a smiling face character

    'General hardware configuration
    #chip 16F877A, 20

    'LCD connection settings
    #define LCD_IO 8
    #define LCD_WIDTH 20                ;specified lcd width for clarity only.  20 is the default width
    #define LCD_DATA_PORT PORTC
    #define LCD_RS PORTD.0
    #define LCD_RW PORTD.1
    #define LCD_Enable PORTD.2

    'Create an array to store the character until it is copied
    Dim CharArray(8)

    'Set the array to hold the character
    'Binary has been used to improve the readability of the code, but is not essential
    CharArray(1) = b'00011011'
    CharArray(2) = b'00011011'
    CharArray(3) = b'00000000'
    CharArray(4) = b'00000100'
    CharArray(5) = b'00000000'
    CharArray(6) = b'00010001'
    CharArray(7) = b'00010001'
    CharArray(8) = b'00001110'

    'Copy the character from the array to the LCD
    LCDCreateChar 0, CharArray()

    'Draw the custom character
    LCDWriteChar 0
```

<span class="strong">**For more help, see**</span>
<a href="lcdcreatechar" class="link" title="LCDCreateChar">LCDWriteChar</a>,
<a href="lcd_overview" class="link" title="LCD Overview">LCD Overview</a>

<span class="strong">**Supported in &lt;LCD.H&gt;**</span>

</div>
