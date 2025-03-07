<div class="section">

<div class="titlepage">

<div>

<div>

### <span id="conditions"></span>Conditions

</div>

</div>

</div>

<span class="strong">**About Conditions**</span>

In GCBASIC (and most other programming languages) a condition is a
statement that can be either true or false. Conditions are used when the
program must make a decision. A condition is generally given as a value
or variable, a relative operator (such as = or &gt;), and another value
or variable. Several conditions can be combined to form one condition
through the use of logical operators such as AND and OR.

GCBASIC supports these relative operators:

<div class="informaltable">

| <span class="strong">**Symbol**</span> | <span class="strong">**Meaning**</span> |
|:--------------------------------------:|:---------------------------------------:|
|                  `=`                   |                  Equal                  |
|                  `<>`                  |                Not Equal                |
|                  `<`                   |                Less Than                |
|                  `>`                   |              Greater Than               |
|                  `⇐`                   |          Less than or equal to          |
|                  `>=`                  |        Greater than or equal to         |

</div>

In addition, these logical operators can be used to combine several
conditions into one:

<div class="informaltable">

| <span class="strong">**Name**</span> | <span class="strong">**Abbreviation**</span> | <span class="strong">**Condition true if**</span> |
|:------------------------------------:|:--------------------------------------------:|:-------------------------------------------------:|
|                `AND`                 |                     `&`                      |             both conditions are true              |
|                 `OR`                 |                     `|`                      |          at least one condition is true           |
|                `XOR`                 |                     `#`                      |               one condition is true               |
|                `NOT`                 |                     `!`                      |             the condition is not true             |

</div>

NOT is slightly different to the other logical operators, in that it
only needs one other condition. Other arithmetic operators may be
combined in conditions, to change values before they are compared, for
example.

GCBASIC has two built in conditions - TRUE, which is always true, and
FALSE, which is always false. These can be used to create Conditional
tests and infinite loops.

The condition bit\_variable = TRUE is treated as TRUE if the bit is
on.  Any non-zero value will be treated as equal to a high bit. The
condition bit\_variable = other\_type\_of\_variable generates a
warning.  If the byte\_variable is set to TRUE and then compared to the
bit, it will always be FALSE because the high bit will be treated as a
1.  But the new warning will be generated, "Comparison will fail if
%nonbit% is any value other than 0 or 1"

It is also possible to test individual bits in conditions. To do this,
specify the bit to test, then 1 or 0 (or ON and OFF respectively).
Presently there is no way to combine bit tests with other conditions -
NOT, AND, OR and XOR will not work.

<span class="strong">**Example conditions:**</span>

<div class="informaltable">

| <span class="strong">**Condition**</span> | <span class="strong">**Comments**</span>            |
|:------------------------------------------|:----------------------------------------------------|
| Temp = 0                                  | Condition is true if Temp = 0                       |
| Sensor &lt;&gt; 0                         | Condition is true if Sensor is not 0                |
| Reading1 &gt; Reading2                    | True if Reading1 is more than Reading2              |
| Mode = 1 AND Time &gt; 10                 | True if Mode is 1 and Time is more than 10          |
| Heat &gt; 5 OR Smoke &gt; 2               | True if Heat is more than 5 or Smoke is more than 2 |
| Light &gt;= 10 AND (NOT Time &gt; 7)      | True if Light is 10 or more, and Time is 7 or less  |
| Temp.0 ON                                 | True if Temp bit 0 is on                            |

</div>

<span class="strong">**Constraints when using Conditional Test**</span>

As GCBASIC is very flexible with the use of variables type this can
cause issues when testing constants and/or functions.

A few simple rules. <span class="strong">**Always put the function or
constant first, or, always call the function with the addition of the
braces.**</span>

The example code below shows the correct method and an example that does
compile but will not work as expected.

``` screen
    'Example A - works
    'Call the function by adding the braces
    '
    Do
    Loop While HSerReceive() <> 62

    'Example B - works
    'Please the constant first - this is the general rule - put the constant first.
    '
    Do
    Loop While 62 <> HSerReceive
```

This fails as the function will not be called

``` screen
    'Example C - compiles but does not operate as expected
    Do
    Loop While HSerReceive <> 62
```

  
  
  
  
  

</div>
