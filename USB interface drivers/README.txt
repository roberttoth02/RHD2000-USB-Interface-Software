Intan USB Interface Installation Instructions
---------------------------------------------

Windows Installation
--------------------

Under Windows, it is important to install the USB drivers BEFORE
connecting the controller to the computer.

The latest driver package is available from Opal Kelly at the following link:
https://pins.opalkelly.com/downloads

Download the latest compatible installer of FrontPanel USB (Driver Only) for 
your system (v4.5.5 or later).  Double-click this file to run the installer.
Follow the instructions, and the driver will install quickly.


Linux Installation
------------------
These installation instructions are valid for FedoraCore 5.  They may work
with or without slight modifications under other Linux distributions.

The Linux installation requires the addition of one file to the directory:

   60-opalkelly.rules ----->  /etc/udev/rules.d/

This file includes a generic udev rule to set the permissions on all
attached Opal Kelly USB devices to allow user access.  Once this file is
in place, you will need to reload the rules by either rebooting or using
the following command:

   /sbin/udevadm control --reload_rules

With these files in place, the Linux device system should automatically
provide write permissions to XEM devices attached to the USB.


Mac Installation
----------------

No installation procedure is necessary to use the board under Mac OS X.
