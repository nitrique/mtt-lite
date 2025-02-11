# Sunrise Telecom MTT Lite with SSMTT-19a (ADSL2+) exploration

This repository trace my MTT Lite exploration, I firstly corrupted the device's flash. I thought it was a CF card as it is the same format,
but after purchasing a reader, nothing was mounted to my computer.

I finally bought 6 more MTT as it worth nothing now, €40 for 6 of them, mostly dead due to a capacitor "C17" ! The original cost was about €1300 each.

It finally drove me into a circuit exploration and testing.

## Step 1: Glitch card

1. Press the menu button while powering on, if you see rectangular pattern, your unit is screwed. Take another one, insert the flash into the first one, do it again, you will see "LITE MANAGER".
2. Go into serial configuration and set the upper speed.
3. Go back to menu and then "flash management".
4. TAKE CARE, if you "download", it upload to the device and corrupt the flash (engineers has reversed the words, or thought you speak on the unit side).
5. Select "upload flash", it takes couple of hours, but it download using XModem the flash content onto your computer.
6. Reboot the device and go to hidden menu again.
7. Go to serial configuration, stay here.
8. Remove the card while powered-on and insert the screwed one. Press enter, if the glitch work, you are back to the menu, otherwise, the cursor will be blocked (do it a couple of times, it will works).
9. Go to serial, set the upper value, go back to flash management, then "Download application", send the dumped flash.
10. After a couple of hours again, your flash is back with a new serial number.

## Step 2: Serial number rewrite

Using the sketches in arduino folder, you can dump and write the content of the flash with an arduino, and an EEPROM ICSP clip.

The EEPROM is the 24LC32A next to the main microcontroller (the big chip).

The serial number is located at position 30 to 35 on the hex values.

I don't known what is the purpose of other differences mentionned on datasheet folders.

## Step 3: Boot and use

After flashing the EEPROM, it will boot with the new serial number :)

## Step 4: Firmware exploration

Here is the default login and password:

Web interface (while using power supply only):

- login: Admin (note the UPPER A)
- password: Admin

Telnet (while using power supply only):

- login: root
- password: Admin

It should be the same on SSH, but the algorithm is to old for my macOS to connect to.

### Shadow content

```
# cat /etc/shadow
root:ABW9wzpK6VV4Q:11876:0:99999:7:::
```

### FSTab

```
# cat /etc/fstab
# /etc/fstab: static file system information.
#
# <file system> <mount point>   <type>  <options>               <dump>  <pass>
/dev/root       /               auto    defaults,errors=continue        0 0
proc            /proc           proc    defaults                        0 0
ramfs           /var            ramfs   defaults                        0 0
```
