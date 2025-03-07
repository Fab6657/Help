<div class="section">

<div class="titlepage">

<div>

<div>

### <span id="scripts"></span>Scripts

</div>

</div>

</div>

<span class="strong">**About Scripts**</span>

A script is a small section of code that GCBASIC runs when it starts to
compile a program. Uses include performing calculations that are
required to adjust the program for different chip frequencies.

Scripts are not compiled or downloaded to the microcontroller - GCBASIC
reads them, executes them, then removes them from the program and then
the results calculated can be used as <span
class="emphasis">*constants*</span> in the user program.

Inside a script, <span class="emphasis">*constants*</span> are treated
like variables. Scripts can read the values of <span
class="emphasis">*constants*</span>, and set them to contain new values.

<span class="strong">**Using Scripts**</span>

Scripts start with `#script` and end with `#endscript`. Inside, they can
consist of the following commands:

``` screen
    If
    Assignment (=)
    Error
    Warning
    Int()
```

`If` is similar to the If command in normal GCBASIC code, except that it
does not have an `Else` clause. It is used to compare the values of the
script constants.

The `=` sign is identical to that in GCBASIC programs. The <span
class="emphasis">*constant*</span> that is to be set goes on the left
side of the `=` and the new value goes to the right of the `=`.

`Error` is used to display an error message. Anything after the `Error`
command is displayed at the end of compilation, and is saved in the
error log for the program.

`Warning` is used to display a warning message. Anything after the
`Warning` command is displayed at the end of compilation but warning
does not halt compilation.

`Int()` will calculate the integer value of a calculation. Using `Int()`
is critical to set the <span class="emphasis">*constant*</span> to the
integer component of the calculation.

<span class="strong">**Notes:**</span>

Use `Warning` to display constant values when creating and debugging
scripts.

Scripts have a limited syntax and limited error checking when compiling.
The compiler may halt if you get something wrong.

Scripts that are incorrectly formatted may also halt the compiler or
return unrelated error.

Scripts used for calculations should use the `Int( expression )` where
you may have a floating point numbers returned.  
Scripts do use floating point for all calculations and a failure to use
`Int()` may set the script constant and the resulting <span
class="emphasis">*constant*</span> to 0.

Scripts may require that complex math expressions may require definition
in multiple steps/line to simplify the calculation.  
The returned value could be incorrect if simplification is not
implemented.

Scripts can only access existing `constants` both user and system
defined.

User defines variables are not accessible within the scope of a script.

Scripts has precendence over \#define. A \#define constant statements
are read first, then scripts run. So, a script will always overwrite a
constant that was set with \#define.

Use `Warning` to display constants values when creating and debugging
scripts.

<span class="strong">**Example Script**</span>

This script is used in the pwm.h file. It takes the values of the user
defined <span class="emphasis">*constants*</span> PWM\_Freq, PWM\_Duty
and system <span class="emphasis">*constant*</span> ChipMHz and
calculates the results using the equations. These calculation are based
on information from a Microchip PIC datasheet to calculate the correct
values to setup Pulse Width Modulation (PWM).

``` screen
    #script
        PR2Temp = INT((1/PWM_Freq)/(4*(1/(ChipMHz*1000))))
        T2PR = 1
        If PR2Temp > 255 Then
            PR2Temp = INT((1 / PWM_Freq) / (16 * (1 / (ChipMHz * 1000))))
            T2PR = 4
            If PR2Temp > 255 Then
                PR2Temp = INT(( 1 / PWM_Freq) / (64 * (1 / (ChipMHz * 1000))))
                T2PR = 16
                If PR2Temp > 255 Then
                    Error Invalid PWM Frequency value
                End If
            End If
        End If

        DutyCycle = (PWM_Duty * 10.24) * PR2Temp / 1024
        DutyCycleH = (DutyCycle AND 1020) / 4
        DutyCycleL = DutyCycle AND 3
    #endscript
```

During the execution of the script the calculations and assignment uses
the constants in the script.

After this script has completed the <span
class="emphasis">*constants*</span> `PR2Temp`, `DutyCycleH` and
`DutyCycleL` are set using the constants and/or the calculations.

The <span class="emphasis">*constants*</span> assigned in this script,
`PR2Temp`, `DutyCycleH` and `DutyCycleL`, are made available as <span
class="emphasis">*constants*</span> in the user program.

</div>
