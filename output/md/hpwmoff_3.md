<div class="section">

<div class="titlepage">

<div>

<div>

###### <span id="hpwmoff_3"></span>HPWMOff

</div>

</div>

</div>

<span class="strong">**Syntax:**</span>

``` screen
    HPWMOff ( channel, PWMHardware )
```

<span class="strong">**Command Availability:**</span>

Only available on Microchip PIC microcontrollers with PWM modules.

<span class="strong">**Explanation:**</span>

This command will disable the output of the PWM module on the Microchip
PIC chip.  

`PWMHardware` is a GCBASIC defined constant not a user vaariable.

<span class="strong">**Example:**</span>

``` screen
 'This program will alter the brightness of an LED using
    'hardware PWM.

    'Select chip model and speed
    #chip 16F18855, 32

    'Generated by PIC PPS Tool for GCBASIC
    '
    'Template comment at the start of the config file
    '
    #startup InitPPS, 85

    Sub InitPPS

            'Module: PWM6
            RA2PPS = 0x000E    'PWM6OUT > RA2

    End Sub
    'Template comment at the end of the config file


    'Set the PWM pin to output mode
    DIR PORTA.2 out

    'Main code
    For ForLoop = 1 to 4
        'Turn up brightness over 2.5 seconds
        For Bright = 1 to 255
            HPWM 6, 40, Bright, 2
            wait 10 ms
        next
        'Turn down brightness over 2.5 seconds
        For Bright = 255 to 1 Step -1
            HPWM 6, 40, Bright, 2
            wait 10 ms
        next
    next

    HPWMOff 6, PWMHardware   'where PWMHardware is the defined constant or you can use TRUE
```

</div>
