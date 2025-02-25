<div class="section">

<div class="titlepage">

<div>

<div>

##### <span id="safwrite"></span>SAFWrite

</div>

</div>

</div>

<span class="strong">**Syntax:**</span>

``` screen
    SAFWrite ( location, data )
```

<span class="strong">**Command Availability:**</span>

Available on all PIC micro-controllers with SAFM memory

<span class="strong">**Explanation:**</span>  
  
SAFWrite is used to write information, byte values, to SAFM so that it
can be accessed later for use in a user program.  
  
`location` represents the location or relative address to write. The
location will range from location 0 to SAF\_BYTES - 1, or for all
practical purposes 0-255 since all PIC Microcontrollers with SAFM
support 256 bytes of SAF Memory.    HEF\_BYTES is a GCBASIC constant
that represents the number of bytes of SAF Memory.  
  
`data` is the data that is to be written to the SAFM location.    This
can be a byte value or a byte variable.  
This method writes information to SAFM given the specific location. This
method is similar to the EPWrite method for EEPROM.  
  
<span class="strong">**Example 1:**</span>

``` screen
     #chip 18F24K42, 16
    '... code to setup PPS
    '... code to setup serial

    'The following example writes a byte value of 126 into HEFM location 34

    SAFWrite( 34,126 )
```

  
  
<span class="strong">**Example 2:**</span>

``` screen
    #chip 18F24K42, 16
    '... code to setup PPS
    '... code to setup serial

    'This example will populate the 256 bytes of SAF memory with a value that is same as the SAFM location

     Dim Rel_Address, DataByte as Byte
     Dim NVM_Address as Long
     Dim  DataWord, as Word

    For Rel_Aaddress = 0 to 255
        SAFWrite ( Rel_Address, Rel_Address )
    Next

    SAFM_Dump
    end

    ; This subroutine displays the SAF Flash Memory on a terminal
    ; Words in reverse byte order relative to address
    sub SAFM_Dump

    Dim Blocknum as Byte
    NVM_Address  = SAF_START_ADDR
    BlockNum = 0

    Repeat SAF_WORDS    ;128
        If NVM_Address % SAF_ROWSIZE_BYTES = 0 then
           If BlockNum > 0 then   HSERPRINTCRLF
           HSerprintCRLF

           HserPrint "Block"
           HSerprint BlockNum
           HSerprint "  1 0   3 2   5 4   7 6   9 8   B A   D C   F E"
           BlockNum++
        End if

        IF NVM_Address  % 16 = 0 then
           HSerPrintCRLF
           hserprint hex(NVM_Address_H)
           hserprint hex(NVM_Address)
           hserprint "    "
        end if

        Rel_Address = NVM_ADDRESS - SAF_START_ADDR
        SAFReadWord(Rel_Address,DataWord)

        hserprint hex(DataWord_H)
        hserprint hex(DataWord)
        hserprint "  "

        NVM_Address+=2 ' Next "WORD"
    End Repeat
End sub
```

  
  
If example 2 were displayed on a serial terminal.   The result would
show:

``` screen
Block0  1 0   3 2   5 4   7 6   9 8   B A   D C   F E
7F00    0100  0302  0504  0706  0908  0B0A  0D0C  0F0E
7F10    1110  1312  1514  1716  1918  1B1A  1D1C  1F1E
7F20    2120  2322  2524  2726  2928  2B2A  2D2C  2F2E
7F30    3130  3332  3534  3736  3938  3B3A  3D3C  3F3E

Block1  1 0   3 2   5 4   7 6   9 8   B A   D C   F E
7F40    4140  4342  4544  4746  4948  4B4A  4D4C  4F4E
7F50    5150  5352  5554  5756  5958  5B5A  5D5C  5F5E
7F60    6160  6362  6564  6766  6968  6B6A  6D6C  6F6E
7F70    7170  7372  7574  7776  7978  7B7A  7D7C  7F7E

Block2  1 0   3 2   5 4   7 6   9 8   B A   D C   F E
7F80    8180  8382  8584  8786  8988  8B8A  8D8C  8F8E
7F90    9190  9392  9594  9796  9998  9B9A  9D9C  9F9E
7FA0    A1A0  A3A2  A5A4  A7A6  A9A8  ABAA  ADAC  AFAE
7FB0    B1B0  B3B2  B5B4  B7B6  B9B8  BBBA  BDBC  BFBE

Block3  1 0   3 2   5 4   7 6   9 8   B A   D C   F E
7FC0    C1C0  C3C2  C5C4  C7C6  C9C8  CBCA  CDCC  CFCE
7FD0    D1D0  D3D2  D5D4  D7D6  D9D8  DBDA  DDDC  DFDE
7FE0    E1E0  E3E2  E5E4  E7E6  E9E8  EBEA  EDEC  EFEE
7FF0    F1F0  F3F2  F5F4  F7F6  F9F8  FBFA  FDFC  FFFE
```

  
  
See also
<a href="safm_overview" class="link" title="SAFM Overview">SAFM Overview</a>,
<a href="safread" class="link" title="SAFRead">SAFRead</a>,
<a href="safreadword" class="link" title="SAFReadWord">SAFReadWord</a>,
<a href="safwrite" class="link" title="SAFWrite">SAFWrite</a>,
<a href="safwriteword" class="link" title="SAFWriteWord">SAFWriteWord</a>,
<a href="safreadblock" class="link" title="SAFReadBlock">SAFReadBlock</a>,
<a href="safwriteblock" class="link" title="SAFWriteBlock">SAFWriteBlock</a>,
<a href="saferaseblock" class="link" title="SAFEraseBlock">SAFEraseBlock</a>

</div>
