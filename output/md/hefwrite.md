<div class="section">

<div class="titlepage">

<div>

<div>

##### <span id="hefwrite"></span>HEFWrite

</div>

</div>

</div>

<span class="strong">**Syntax:**</span>

``` screen
    HEFWrite ( location, data )
```

<span class="strong">**Command Availability:**</span>

Available on all PIC micro-controllers with HEFM memory

<span class="strong">**Explanation:**</span>  
  
HEFWrite is used to write information, byte values, to HEFM so that it
can be accessed later for use in a user program.  
  
`location` represents the location or relative address to write. The
location will range from location 0 to HEF\_BYTES - 1, or for all
practical purposes 0-127 since all PIC Microcontrollers with HEF support
128 bytes of HEF Memory. HEF\_BYTES is a GCBASIC constant that
represents the number of bytes of HEF Memory.  
  
`data` is the data that is to be written to the HEFM location.    This
can be a byte value or a byte variable.  
  
This method writes information to the HEFM given the specific location.
This method is similar to the EPWrite method for EEPROM.  
  

<span class="strong">**Example 1:**</span>

``` screen
    '... code preamble to select part
    '... code to setup serial

    'The following example writes a byte value of 126 into HEFM location 34

     HEFWrite( 34, 126 )
```

  
  
<span class="strong">**Example 2:**</span>

``` screen
    '... code preamble to select part
    '... code to setup serial

    'This example will populate all 128 bytes of HEF memory with a value that is same as the HEFM location

     Dim Rel_Address, DataByte as Byte
     Dim NVM_Address as Long
     Dim  DataWord, as Word
     Dim HEFaddress as Byte

    For Rel_Address = 0 to 127
        HEFWrite ( Rel_Address, Rel_Address )
    Next
    HEFM_DUMP

    End

  ; This subroutine displays the High Endurance Flash Memory on a terminal.
  ; Words are in reverse byte order relative to address.
  ; HEF data resides in the low byte of each 14bit program memory word.
  ; The high byte is not HEF and should always read "3F".

  Sub HEFM_DUMP

    Dim Blocknum as Byte
    NVM_Address  = HEF_START_ADDR
    BlockNum = 0

    Repeat  HEF_BYTES  ;128

        If NVM_Address % HEF_ROWSIZE_BYTES = 0 then
            If BlockNum > 0 then   HSERPRINTCRLF
           HSerprintCRLF
           HserPrint "Block"
           HSerprint BlockNum
           HSerprint "     0     1     2     3     4     5     6     7"
           BlockNum++
        End if

        IF NVM_Address  % 8 = 0 then
           HSerPrintCRLF
           hserprint hex(NVM_Address_H)
           hserprint hex(NVM_ADDRESS)
           hserprint "     "
        end if

        Rel_Address = (NVM_ADDRESS - HEF_START_ADDR)
        HEFRead(Rel_Address, DataWord)

        hserprint hex(DataWord_H)
        hserprint hex(DataWord)
        hserprint "  "

        NVM_Address++
    End Repeat
    HserPrintCRLF
End sub
```

  
  
If example 2 were displayed on a serial terminal.   The result would
show:

``` screen
Block0     0     1     2     3     4     5     6     7
3F80     3F00  3F01  3F02  3F03  3F04  3F05  3F06  3F07
3F88     3F08  3F09  3F0A  3F0B  3F0C  3F0D  3F0E  3F0F
3F90     3F10  3F11  3F12  3F13  3F14  3F15  3F16  3F17
3F98     3F18  3F19  3F1A  3F1B  3F1C  3F1D  3F1E  3F1F

Block1     0     1     2     3     4     5     6     7
3FA0     3F20  3F21  3F22  3F23  3F24  3F25  3F26  3F27
3FA8     3F28  3F29  3F2A  3F2B  3F2C  3F2D  3F2E  3F2F
3FB0     3F30  3F31  3F32  3F33  3F34  3F35  3F36  3F37
3FB8     3F38  3F39  3F3A  3F3B  3F3C  3F3D  3F3E  3F3F

Block2     0     1     2     3     4     5     6     7
3FC0     3F40  3F41  3F42  3F43  3F44  3F45  3F46  3F47
3FC8     3F48  3F49  3F4A  3F4B  3F4C  3F4D  3F4E  3F4F
3FD0     3F50  3F51  3F52  3F53  3F54  3F55  3F56  3F57
3FD8     3F58  3F59  3F5A  3F5B  3F5C  3F5D  3F5E  3F5F

Block3     0     1     2     3     4     5     6     7
3FE0     3F60  3F61  3F62  3F63  3F64  3F65  3F66  3F67
3FE8     3F68  3F69  3F6A  3F6B  3F6C  3F6D  3F6E  3F6F
3FF0     3F70  3F71  3F72  3F73  3F74  3F75  3F76  3F77
3FF8     3F78  3F79  3F7A  3F7B  3F7C  3F7D  3F7E  3F7F
```

  
  
See also
<a href="hefm_overview" class="link" title="HEFM Overview">HEFM Overview</a>,
<a href="hefread" class="link" title="HEFRead">HEFRead</a>,
<a href="hefreadword" class="link" title="HEFReadWord">HEFReadWord</a>,
<a href="hefwrite" class="link" title="HEFWrite">HEFWrite</a>,
<a href="hefwriteword" class="link" title="HEFWriteWord">HEFWriteWord</a>,
<a href="hefreadblock" class="link" title="HEFReadBlock">HEFReadBlock</a>,
<a href="hefwriteblock" class="link" title="HEFWriteBlock">HEFWriteBlock</a>,
<a href="heferaseblock" class="link" title="HEFEraseBlock">HEFEraseBlock</a>

</div>
