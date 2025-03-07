<div class="section">

<div class="titlepage">

<div>

<div>

### <span id="usb_drivers_installer"></span>USB Drivers Installer

</div>

</div>

</div>

<div class="warning" style="margin-left: 0.5in; margin-right: 0.5in;">

### Warning

Installing the USB driver is only required when using the GCBASIC USB
library.

</div>

<span class="strong">**Description:**</span>

The drivers for windows x86 and x64 correspond to the USB LIBKWIN
capability of GCBasic for supported PIC microcontrollers.

For security reasons, in Microsoft windows for a driver to be installed,
it is necessary that it be digitally signed by Microsoft.

Microsoft did make a special “Test” mode for developers to install
MANUALLY unsigned drivers for debug and testing, being a technical
advanced and not user-friendly procedure; at the same time the windows
developers make efforts to disable the capability of doing this in an
automated fashion by the concerns of being used as a vulnerability of
the operating system.

This scenario will make installing test drivers difficult and
frustrating for the uninitiated, at the same time for a useful Hobby
project it will be not practical to make end users to take all this
drama.

This driver installer method resolves the constraints imposed by the
Windows operating system, and, therefore will allow you to install the
drivers in the easiest way possible, almost like any driver of a
well-known company.

<span class="strong">**Usage:**</span>

<div class="warning" style="margin-left: 0.5in; margin-right: 0.5in;">

### Warning

The installer will reboot the system without notice. Please close all
programs and save any work you have open before begin whit the driver
install.

</div>

1 - Open the installer, it will request admin rights.

2 - Navigate thru the wizard to automatically extract the driver files
(there aren’t any options to select).

3 - At the end of the wizard, after you click the exit button, the
system will restart automatically

<div class="warning" style="margin-left: 0.5in; margin-right: 0.5in;">

### Warning

In the case where your computer has Secure Boot enabled, the installer
will advise you of extra steps needed after reboot, at the end of this
page you will find a graphic reflecting those steeps and what elements
you need to select.

</div>

4 - After restart and login in to your user account, a window will
inform you that the driver is not signed and you will be asked if you
want to install the driver, please allow it.

5 - when the driver has been installed, the computer will restart
automatically.

  
  

<span class="strong">**Secure Boot Enabled, Boot menu steps**</span>  
  

<div class="informalfigure">

<div class="mediaobject" align="center">

![graphic](./images/winresteepsm.png)

</div>

</div>

  
  

<span class="strong">**USB Driver details**</span>

The driver uses the following USB flags.

``` screen
    USB_VID 0x1209
    USB_PID 0x2006
    USB_REV 0x0000
```

For others, need to modify and recompile the USB library.

USB\_PRODUCT\_NAME and USB\_VENDOR\_NAME can change without problem
(windows device manager will show the name reported by the hardware not
the driver

<span class="strong">**Tested on (but not limited to)**</span>

``` screen
    Windows 11 pro x64 secureboot disabled, os build Dev 21H2 22000.194
    Windows 11 pro x64 secureboot enabled, os build Dev rs_prerelease 22458.1000
    Windows 10 pro x64 secureboot disabled, os build stable 20H2 19042.867
    Windows 7 pro x86 secureboot disabled, os service pack 1 build 6.1.7601
```

</div>
